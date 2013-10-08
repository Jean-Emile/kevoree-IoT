#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contiki.h"
#include "contiki-net.h"


/* Define which resources to include to meet memory constraints. */

#define REST_RES_CHUNKS 1
#define REST_RES_SEPARATE 0
#define REST_RES_PUSHING 0
#define REST_RES_EVENT 0
#define REST_RES_SUB 0
#define REST_RES_LEDS 1
#define REST_RES_TOGGLE 0


/* Defines by kYc0o */
#define REST_RES_PUT 1
#define MAX_KEVMOD_BODY    2048

const char *current_model = "node0:ArduinoNode@{" +
                              "pin:period:serialport,DigitalLight:Timer:LocalChannel:SerialCT,on:off:toggle:flash:tick/" +
                              "1:L1:2/" +
                              "1:S1:3:2=devttyACM0/" +
                              "1:T1:1:1=1000/" +
                              "1:D1:0:0=13/1:T2:1:1=1000/" +
                              "3:T1:L1:4/" +
                              "3:D1:L1:3/" +
                              "3:T2:S1:4/" +
                              "0:S1:2=39/" +
                              "}";

/*#undef PLATFORM_HAS_BUTTON
#define PLATFORM_HAS_BUTTON 1*/
#define SERVER_NODE(ipaddr)   uip_ip6addr(ipaddr, 0xaaaa, 0, 0, 0, 0, 0, 0, 0x1)
#define LOCAL_PORT      UIP_HTONS(COAP_DEFAULT_PORT+1)
#define REMOTE_PORT     UIP_HTONS(COAP_DEFAULT_PORT)

#include "erbium.h"
#include "cfs/cfs.h"

#if defined (PLATFORM_HAS_BUTTON)
#include "dev/button-sensor.h"
#endif
#if defined (PLATFORM_HAS_LEDS)
#include "dev/leds.h"
#endif

/* For CoAP-specific example: not required for normal RESTful Web service. */
#if WITH_COAP == 3
#include "er-coap-03.h"
#include "er-coap-03-engine.h"
#elif WITH_COAP == 7
#include "er-coap-07.h"
#include "er-coap-07-engine.h"
#elif WITH_COAP == 12
#include "er-coap-12.h"
#include "er-coap-12-engine.h"
#elif WITH_COAP == 13
#include "er-coap-13.h"
#include "er-coap-13-engine.h"
#else
#warning "Erbium example without CoAP-specifc functionality"
#endif /* CoAP-specific example */

#define DEBUG 1
#if DEBUG
#define PRINTF(...) printf(__VA_ARGS__)
#define PRINT6ADDR(addr) PRINTF("[%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x]", ((uint8_t *)addr)[0], ((uint8_t *)addr)[1], ((uint8_t *)addr)[2], ((uint8_t *)addr)[3], ((uint8_t *)addr)[4], ((uint8_t *)addr)[5], ((uint8_t *)addr)[6], ((uint8_t *)addr)[7], ((uint8_t *)addr)[8], ((uint8_t *)addr)[9], ((uint8_t *)addr)[10], ((uint8_t *)addr)[11], ((uint8_t *)addr)[12], ((uint8_t *)addr)[13], ((uint8_t *)addr)[14], ((uint8_t *)addr)[15])
#define PRINTLLADDR(lladdr) PRINTF("[%02x:%02x:%02x:%02x:%02x:%02x]",(lladdr)->addr[0], (lladdr)->addr[1], (lladdr)->addr[2], (lladdr)->addr[3],(lladdr)->addr[4], (lladdr)->addr[5])
#else
#define PRINTF(...)
#define PRINT6ADDR(addr)
#define PRINTLLADDR(addr)
#endif

/* For printing ipv6 address in DEBUG=1 */
static void
print_local_addresses(void)
{
  int i;
  uint8_t state;

  PRINTF("Server IPv6 addresses: \n");
  for(i = 0; i < UIP_DS6_ADDR_NB; i++) {
    state = uip_ds6_if.addr_list[i].state;
    if(uip_ds6_if.addr_list[i].isused &&
       (state == ADDR_TENTATIVE || state == ADDR_PREFERRED)) {
      PRINT6ADDR(&uip_ds6_if.addr_list[i].ipaddr);
      PRINTF("\n");
    }
  }
}


/******************************************************************************/
#if REST_RES_CHUNKS
/*
 * For data larger than REST_MAX_CHUNK_SIZE (e.g., stored in flash) resources must be aware of the buffer limitation
 * and split their responses by themselves. To transfer the complete resource through a TCP stream or CoAP's blockwise transfer,
 * the byte offset where to continue is provided to the handler as int32_t pointer.
 * These chunk-wise resources must set the offset value to its new position or -1 of the end is reached.
 * (The offset for CoAP's blockwise transfer can go up to 2'147'481'600 = ~2047 M for block size 2048 (reduced to 1024 in observe-03.)
 */
RESOURCE(chunks, METHOD_GET, "test/chunks", "title=\"Blockwise demo\";rt=\"Data\"");

#define CHUNKS_TOTAL    2050

void
chunks_handler(void* request, void* response, uint8_t *buffer, uint16_t preferred_size, int32_t *offset)
{
  int32_t strpos = 0;

  /* Check the offset for boundaries of the resource data. */
  if (*offset>=CHUNKS_TOTAL)
  {
    REST.set_response_status(response, REST.status.BAD_OPTION);
    /* A block error message should not exceed the minimum block size (16). */

    const char *error_msg = "BlockOutOfScope";
    REST.set_response_payload(response, error_msg, strlen(error_msg));
    return;
  }

  /* Generate data until reaching CHUNKS_TOTAL. */
  while (strpos<preferred_size)
  {
    strpos += snprintf((char *)buffer+strpos, preferred_size-strpos+1, "|%ld|", *offset);
  }

  /* snprintf() does not adjust return value if truncated by size. */
  if (strpos > preferred_size)
  {
    strpos = preferred_size;
  }

  /* Truncate if above CHUNKS_TOTAL bytes. */
  if (*offset+(int32_t)strpos > CHUNKS_TOTAL)
  {
    strpos = CHUNKS_TOTAL - *offset;
  }

  REST.set_response_payload(response, buffer, strpos);

  /* IMPORTANT for chunk-wise resources: Signal chunk awareness to REST engine. */
  *offset += strpos;

  /* Signal end of resource representation. */
  if (*offset>=CHUNKS_TOTAL)
  {
    *offset = -1;
  }
}
#endif

/******************************************************************************/
#if REST_RES_SEPARATE && defined (PLATFORM_HAS_BUTTON) && WITH_COAP > 3
/* Required to manually (=not by the engine) handle the response transaction. */
#if WITH_COAP == 7
#include "er-coap-07-separate.h"
#include "er-coap-07-transactions.h"
#elif WITH_COAP == 12
#include "er-coap-12-separate.h"
#include "er-coap-12-transactions.h"
#elif WITH_COAP == 13
#include "er-coap-13-separate.h"
#include "er-coap-13-transactions.h"
#endif

#if REST_RES_PUT
/*
 * PUT TODO GET CURRENT MODEL   return current_model;
*/
RESOURCE(getData, METHOD_PUT, "data", "tile=\"PUT: data/, PUT binary data\"; rt=\"Control\"");

int fd_write, fd_read;
int n;
const char *filename;
static int32_t large_update_size = 0;
static uint8_t large_update_store[MAX_KEVMOD_BODY] = {0};
static unsigned int large_update_ct = -1;

void
getData_handler(void* request, void* response, uint8_t *buffer, uint16_t preferred_size, int32_t *offset)
{
	coap_packet_t *const coap_req = (coap_packet_t *) request;

	uint8_t *incoming = NULL;
	size_t len = 0;
	size_t len2 = 0;

	/*PRINTF("Entering to handler \n");*/

	unsigned int ct = REST.get_header_content_type(request);
	if (ct==-1){
	   REST.set_response_status(response, REST.status.BAD_REQUEST);
	   const char *error_msg = "NoContentType";
	   REST.set_response_payload(response, error_msg, strlen(error_msg));
	   return;
	}

	if ((len = REST.get_request_payload(request, (const uint8_t **) &incoming)))
	{
		if (len2=REST.get_query_variable(request, "filename", &filename)){
			PRINTF("File name %.*s\n", len2, filename);

		}

	  if (coap_req->block1_num*coap_req->block1_size+len <= sizeof(large_update_store))
	  {
		fd_write = cfs_open(filename, CFS_WRITE | CFS_APPEND);
		/*memcpy(large_update_store+coap_req->block1_num*coap_req->block1_size, incoming, len);*/
		if(fd_write != -1) {
			n = cfs_write(fd_write, incoming, len);
			cfs_close(fd_write);
			PRINTF("Successfully appended data to cfs. wrote %i bytes\n", n);
		} else {
		    PRINTF("ERROR: could not write to memory \n");
		}
	    large_update_size = coap_req->block1_num*coap_req->block1_size+len;
	    large_update_ct = REST.get_header_content_type(request);

        REST.set_response_status(response, REST.status.CHANGED);
        coap_set_header_block1(response, coap_req->block1_num, 0, coap_req->block1_size);

        PRINTF("Chunk num. : %ld Size: %d \n", coap_req->block1_num, coap_req->block1_size);
      }
	  else
	  {
	    REST.set_response_status(response, REST.status.REQUEST_ENTITY_TOO_LARGE);
	    REST.set_response_payload(response, buffer, snprintf((char *)buffer, REST_MAX_CHUNK_SIZE, "%uB max.", sizeof(large_update_store)));
	    return;
	  }
	}
	else
	{
	  REST.set_response_status(response, REST.status.BAD_REQUEST);
	  const char *error_msg = "NoPayload";
	  REST.set_response_payload(response, error_msg, strlen(error_msg));
	  return;
	}

	/*if (validQuery){
		if (len2=REST.get_query_variable(request, "filename", &filename)){
			PRINTF("File name %.*s\n", len2, filename);
			fd_write = cfs_open(filename, CFS_WRITE);
			validQuery = 0;
		}
		else
		{
			PRINTF("Invalid query variable");
		}
	}*/



	/*size_t len2 = 0;
	char *bytes = NULL;

	int len = coap_get_payload(request, (const uint8_t**) &bytes);

	if ((len2=REST.get_query_variable(request, "filename", &filename))) {
	   PRINTF("File name %.*s\n", len2, filename);
	   fd_write = cfs_open(filename, CFS_WRITE);

	   if(fd_write != -1) {
	       n = cfs_write(fd_write, bytes, sizeof(bytes));
	       cfs_close(fd_write);
	       PRINTF("Successfully written to cfs. wrote %i bytes\n", n);
	     } else {
	       PRINTF("ERROR: could not write to memory \n");
	     }
	}*/
}
#endif
/******************************************************************************/
#if defined (PLATFORM_HAS_LEDS)
/******************************************************************************/
#if REST_RES_LEDS
/*A simple actuator example, depending on the color query parameter and post variable mode, corresponding led is activated or deactivated*/
RESOURCE(leds, METHOD_POST | METHOD_PUT , "actuators/leds", "title=\"LEDs: ?color=r|g|b, POST/PUT mode=on|off\";rt=\"Control\"");

void
leds_handler(void* request, void* response, uint8_t *buffer, uint16_t preferred_size, int32_t *offset)
{
  size_t len = 0;
  const char *color = NULL;
  const char *mode = NULL;
  uint8_t led = 0;
  int success = 1;

  if ((len=REST.get_query_variable(request, "color", &color))) {
    PRINTF("color %.*s\n", len, color);

    if (strncmp(color, "r", len)==0) {
      led = LEDS_RED;
    } else if(strncmp(color,"g", len)==0) {
      led = LEDS_GREEN;
    } else if (strncmp(color,"b", len)==0) {
      led = LEDS_BLUE;
    } else {
      success = 0;
    }
  } else {
    success = 0;
  }

  if (success && (len=REST.get_post_variable(request, "mode", &mode))) {
    PRINTF("mode %s\n", mode);

    if (strncmp(mode, "on", len)==0) {
      leds_on(led);
    } else if (strncmp(mode, "off", len)==0) {
      leds_off(led);
    } else {
      success = 0;
    }
  } else {
    success = 0;
  }

  if (!success) {
    REST.set_response_status(response, REST.status.BAD_REQUEST);
  }
}
#endif

/******************************************************************************/
#if REST_RES_TOGGLE
/* A simple actuator example. Toggles the red led */
RESOURCE(toggle, METHOD_POST, "actuators/toggle", "title=\"Red LED\";rt=\"Control\"");
void
toggle_handler(void* request, void* response, uint8_t *buffer, uint16_t preferred_size, int32_t *offset)
{
  leds_toggle(LEDS_RED);
}
#endif
#endif /* PLATFORM_HAS_LEDS */




PROCESS(kevoree_runtime, "Kevoree Runtime");
AUTOSTART_PROCESSES(&kevoree_runtime);

uip_ipaddr_t server_ipaddr;

void
client_chunk_handler(void *response)
{
  const uint8_t *chunk;

  int len = coap_get_payload(response, &chunk);
  printf("|%.*s", len, (char *)chunk);
}

PROCESS_THREAD(kevoree_runtime, ev, data)
{
  PROCESS_BEGIN();

  static coap_packet_t request[1]; /* This way the packet can be treated as pointer as usual. */
  SERVER_NODE(&server_ipaddr);
  coap_receiver_init();

  PRINTF("Starting Kevoree Runtime\n");

#ifdef RF_CHANNEL
  PRINTF("RF channel: %u\n", RF_CHANNEL);
#endif
#ifdef IEEE802154_PANID
  PRINTF("PAN ID: 0x%04X\n", IEEE802154_PANID);
#endif

  PRINTF("uIP buffer: %u\n", UIP_BUFSIZE);
  PRINTF("LL header: %u\n", UIP_LLH_LEN);
  PRINTF("IP+UDP header: %u\n", UIP_IPUDPH_LEN);
  PRINTF("REST max chunk: %u\n", REST_MAX_CHUNK_SIZE);

  /* Initialize the REST engine. */
  rest_init_engine();


/* TODO call maven resolver paramètres const char*group,const char *group,const char *ext,const const char *urls[]
 copy in file system the file



 */

  /* Activate the application-specific resources. */
#if REST_RES_HELLO
  rest_activate_resource(&resource_helloworld);
#endif
#if REST_RES_MIRROR
  rest_activate_resource(&resource_mirror);
#endif
#if REST_RES_CHUNKS
  rest_activate_resource(&resource_chunks);
#endif
#if REST_RES_PUSHING
  rest_activate_periodic_resource(&periodic_resource_pushing);
#endif
#if defined (PLATFORM_HAS_BUTTON) && REST_RES_EVENT
  rest_activate_event_resource(&resource_event);
#endif
#if defined (PLATFORM_HAS_BUTTON) && REST_RES_SEPARATE && WITH_COAP > 3
  /* No pre-handler anymore, user coap_separate_accept() and coap_separate_reject(). */
  rest_activate_resource(&resource_separate);
#endif
/*#if defined (PLATFORM_HAS_BUTTON) && (REST_RES_EVENT || (REST_RES_SEPARATE && WITH_COAP > 3))*/
#if defined (PLATFORM_HAS_BUTTON)
  SENSORS_ACTIVATE(button_sensor);
#endif
#if REST_RES_SUB
  rest_activate_resource(&resource_sub);
#endif
#if REST_RES_PUT
  rest_activate_resource(&resource_getData);
#endif
#if defined (PLATFORM_HAS_LEDS)
#if REST_RES_LEDS
  rest_activate_resource(&resource_leds);
#endif
#if REST_RES_TOGGLE
  rest_activate_resource(&resource_toggle);
#endif
#endif /* PLATFORM_HAS_LEDS */
#if defined (PLATFORM_HAS_LIGHT) && REST_RES_LIGHT
  SENSORS_ACTIVATE(light_sensor);
  rest_activate_resource(&resource_light);
#endif
#if defined (PLATFORM_HAS_BATTERY) && REST_RES_BATTERY
  SENSORS_ACTIVATE(battery_sensor);
  rest_activate_resource(&resource_battery);
#endif
#if defined (PLATFORM_HAS_RADIO) && REST_RES_RADIO
  SENSORS_ACTIVATE(radio_sensor);
  rest_activate_resource(&resource_radio);
#endif

  /* Define application-specific events here. */
  while(1) {
    PROCESS_WAIT_EVENT();


#if defined (PLATFORM_HAS_BUTTON)
    if (ev == sensors_event && data == &button_sensor) {
      PRINTF("BUTTON\n");
      print_local_addresses();

      coap_init_message(request, COAP_TYPE_CON, COAP_GET, 0);
      coap_set_header_uri_path(request, "/helloWorld");

      /*printf("--Requesting /mavenresolver?group=org.kevoree.helloworld&name=hello_world&version=1.0&extension=.ce\n");*/
      printf("--Requesting /helloWorld\n");

      PRINT6ADDR(&server_ipaddr);
      PRINTF(" : %u\n", UIP_HTONS(REMOTE_PORT));

      COAP_BLOCKING_REQUEST(&server_ipaddr, REMOTE_PORT, request, client_chunk_handler);

      printf("\n--Done--\n");

#if REST_RES_EVENT
      /* Call the event_handler for this application-specific event. */
      event_event_handler(&resource_event);
#endif
#if REST_RES_SEPARATE && WITH_COAP>3
      /* Also call the separate response example handler. */
      separate_finalize_handler();
#endif
    }
#endif /* PLATFORM_HAS_BUTTON */
  } /* while (1) */

  PROCESS_END();
}

