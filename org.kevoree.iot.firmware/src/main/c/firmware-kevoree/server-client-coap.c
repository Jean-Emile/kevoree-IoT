#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contiki.h"
#include "contiki-net.h"


/* Define which resources to include to meet memory constraints. */
#define REST_RES_CHUNKS 0
#define REST_RES_LEDS 0

#define CHUNKS_TOTAL 2050

/* Defines by kYc0o */
#define REST_RES_PUT 1
#define REST_RES_MODELS 1
#define COAP_CLIENT_ENABLED 1
#define MAX_KEVMOD_BODY 2048

#define SERVER_NODE(ipaddr) uip_ip6addr(ipaddr, 0xaaaa, 0, 0, 0, 0, 0, 0, 0x1)
#define LOCAL_PORT UIP_HTONS(COAP_DEFAULT_PORT+1)
#define REMOTE_PORT UIP_HTONS(COAP_DEFAULT_PORT)

#include "erbium.h"
#include "cfs/cfs.h"

#if defined (PLATFORM_HAS_BUTTON)
#include "dev/button-sensor.h"
#endif
#if defined (PLATFORM_HAS_LEDS)
#include "dev/leds.h"
#endif

/* For CoAP-specific example: not required for normal RESTful Web service. */
#include "er-coap-13.h"
#include "er-coap-13-engine.h"

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

    for(i = 0; i < UIP_DS6_ADDR_NB; i++)
    {
        state = uip_ds6_if.addr_list[i].state;

        if(uip_ds6_if.addr_list[i].isused && (state == ADDR_TENTATIVE || state == ADDR_PREFERRED))
        {
            PRINT6ADDR(&uip_ds6_if.addr_list[i].ipaddr);
            PRINTF("\n");
        }
    }
}

/*void
write_current_model(void)
{
    int fd_write;
    int n;
    char *filename = "current.kev";
    char current_model[216];

    strcpy(current_model, "node0:uKevoreeNode@{pin:period:serialport,DigitalLight:Timer:LocalChannel:SerialCT,on:off:toggle:flash:tick/1:L1:2/1:S1:3:2=devttyUSB0/1:T1:1:1=1000/1:D1:0:0=13/1:T2:1:1=1000/3:T1:L1:4/3:D1:L1:3/3:T2:S1:4/0:S1:2=39/}");

    fd_write = cfs_open(filename, CFS_WRITE);

    if (fd_write != -1)
    {
        n = cfs_write(fd_write, current_model, sizeof(current_model));
        cfs_close(fd_write);
        PRINTF("current.kev successfully written to cfs. wrote %i bytes \n", n);
    }
    else
    {
        PRINTF("ERROR: could not write to memory.\n");
    }
}*/

static int32_t large_update_size = 0;
static uint8_t large_update_store[MAX_KEVMOD_BODY] = {0};
static unsigned int large_update_ct = -1;

#if REST_RES_MODELS
/*
* Resource for GET and PUT models in .kev format (text or bytes)
*/

RESOURCE(models, METHOD_GET | METHOD_PUT, "models", "tile=\"GET: ?modelname=\"model_name.kev\" /, Kevoree Model\"; rt=\"Control & Data\"");

int32_t strAcc = 0;
int32_t length = 0;
int32_t length2 = 0;
uint16_t pref_size = 0;

void
models_handler(void* request, void* response, uint8_t *buffer, uint16_t preferred_size, int32_t *offset)
{
    if (*offset >= CHUNKS_TOTAL)
    {
        REST.set_response_status(response, REST.status.BAD_OPTION);
        /* A block error message should not exceed the minimum block size (16).*/
        const char *error_msg = "BlockOutOfScope";
        REST.set_response_payload(response, error_msg, strlen(error_msg));
        PRINTF("ERROR: Block out of scope.\n");
        return;
    }

    PRINTF("Entering models_handler \n");
    size_t len = 0;
    int32_t strpos = 0;
    const char *modelname;
    coap_packet_t *const coap_req = (coap_packet_t *) request;
    uint8_t method = REST.get_method_type(request);

    if ((len=(REST.get_query_variable(request, "modelname", &modelname))))
    {
        if (method & METHOD_GET)
        {
            PRINTF("Method GET\nmodel name: %.*s\n", len, modelname);

            if (strncmp(modelname, "current.kev", len)==0)
            {
                /*PRINTF("*offset = %ld\npreferred_size = %d\nstrAcc = %ld\n", *offset, preferred_size, strAcc);*/

                char *filename = "current.kev";
                char buf[preferred_size];
                int fd_read;
                int32_t n = 0;

                /* strAcc is 0 when the request is made for the first time. We read the file and calculate size */
                if (strAcc == 0)
                {
                    fd_read = cfs_open(filename, CFS_READ);

                    if (fd_read != -1)
                    {
                        do
                        {
                            n = cfs_read(fd_read, buf, sizeof(buf));
                            if (n != -1)
                            {
                                length2 = length;
                                length += n;
                            }
                        } while (length != length2);
                        cfs_close(fd_read);
                        PRINTF("Model length: %ld \n", length);
                    }
                    else
                    {
                        REST.set_response_status(response, REST.status.BAD_OPTION);
                        /* A block error message should not exceed the minimum block size (16). */
                        const char *error_msg = "FileCouldNotRead";
                        REST.set_response_payload(response, error_msg, strlen(error_msg));
                        PRINTF("ERROR: could not read from memory.\n");
                        return;
                    }
                }

                fd_read = cfs_open(filename, CFS_READ);

                /* Send data until reaching file lentgh.*/
                if (strpos < preferred_size && fd_read != -1)
                {
                    if (length2 - strAcc >= preferred_size)
                    {
                        /* strAcc is 0 when the request is made for the first time, we must read the first "prefered_size" bytes */
                        if (strAcc == 0)
                        {
                            n = cfs_read(fd_read, buf, sizeof(buf));
                            /* Stock the pointer wih the last "preferred_size" */
                            pref_size = preferred_size;
                            /*PRINTF("FIRST TIME of reading\n");*/
                        }
                        else
                        {
                            /* For the second and next requests we seek for the right data in the file, then cumulate the pointer */
                            cfs_seek(fd_read, pref_size, CFS_SEEK_SET);
                            n = cfs_read(fd_read, buf, sizeof(buf));
                            pref_size += preferred_size;
                            /*PRINTF("data SEEKED and READED\n");*/
                        }
                    }
                    else
                    {
                        /* When the last bytes are less than a complete "preferred_size" block, we read only these last bytes */
                        cfs_seek(fd_read, pref_size, CFS_SEEK_SET);
                        n = cfs_read(fd_read, buf, (length2 - strAcc));
                        /*PRINTF("last read! \n");*/
                    }
                    /*PRINTF("bytes readed %ld\n", n);*/
                    cfs_close(fd_read);
                    strpos += snprintf((char *)buffer, preferred_size - strpos + 1, buf);
                    length -= strpos;
                    /*PRINTF("length = %ld\n", length);
                    PRINTF("strpos = %ld \n", strpos);*/
                }
                else
                {
                    REST.set_response_status(response, REST.status.BAD_OPTION);
                    /* A block error message should not exceed the minimum block size (16). */
                    const char *error_msg = "FileCouldNotRead";
                    REST.set_response_payload(response, error_msg, strlen(error_msg));
                    PRINTF("ERROR: could not read from memory.\n");
                    return;
                }

                /* snprintf() does not adjust return value if truncated by size.*/
                if (strpos > preferred_size)
                {
                    strpos = preferred_size;
                    /*PRINTF("strpos = prefered_size, strpos : %ld \n", strpos);*/
                }

                /* Truncate if above CHUNKS_TOTAL bytes. */
                if (/* *offset*/ strAcc + (int32_t)strpos > length2)
                {
                    strpos = length2 - strAcc;/* *offset; */
                    /*PRINTF("strpos = length2 - *offset : %ld \n", strpos);*/
                }

                /* The query string can be retrieved by rest_get_query() or parsed for its key-value pairs. */
                REST.set_header_content_type(response, REST.type.TEXT_PLAIN); /* text/plain is the default, hence this option could be omitted. */
                REST.set_header_etag(response, (uint8_t *) &strpos, 1);
                REST.set_response_payload(response, buffer, strpos);

                /* IMPORTANT for chunk-wise resources: Signal chunk awareness to REST engine. */
                *offset += strpos;
                strAcc += strpos;
                /*PRINTF("offset: %ld \nstrAcc = %ld\n", *offset, strAcc);*/

                /* Signal end of resource representation. */
                if (/* *offset*/ strAcc >= length2)
                {
                    *offset = -1;
                    strAcc = 0;
                    length = 0;
                    /*PRINTF("*offset >= length, offset : %ld \n", *offset);*/
                }
            }
            else
            {
                REST.set_response_status(response, REST.status.BAD_OPTION);
                /* A block error message should not exceed the minimum block size (16). */
                const char *error_msg = "ModelUnavailable";
                REST.set_response_payload(response, error_msg, strlen(error_msg));
                PRINTF("ERROR: Model unavailable.\n");
                return;
            }
        }
        else if (method & METHOD_PUT)
        {
            PRINTF("Method PUT\nmodel name: %.*s\n", len, modelname);
            int fd_write = 0;
            int fd_read = 0;
            int n = 0;
            char *filename = "current.kev";
            uint8_t *incoming = NULL;;
            /*size_t len2 = 0;*/
            /*unsigned int ct = REST.get_header_content_type(request);

            if (ct==-1)
            {
                REST.set_response_status(response, REST.status.BAD_REQUEST);
                const char *error_msg = "NoContentType";
                REST.set_response_payload(response, error_msg, strlen(error_msg));
                PRINTF("ERROR: No content type.\n");
                return;
            }*/
            if (pref_size != 0 && coap_req->block1_num == 0)
            {
                fd_read = cfs_open(filename, CFS_READ);

                if (fd_read == -1)
                {
                    PRINTF("File can be written\n");
                }
                else
                {
                    cfs_remove(filename);
                    fd_read = cfs_open(filename, CFS_READ);
                    if (fd_read == -1)
                    {
                        PRINTF("file has been removed.\n");
                    }
                    else
                    {
                        PRINTF("ERROR: could read from memory, file exists.\n");
                        cfs_close(fd_read);
                    }
                }
            }

            if ((len = REST.get_request_payload(request, (const uint8_t **) &incoming)))
            {
                /*if ((len2 = REST.get_query_variable(request, "modelname", &filename)))
                {
                    PRINTF("File name %.*s\n", len2, filename);
                }*/

                if (coap_req->block1_num*coap_req->block1_size+len <= sizeof(large_update_store))
                {
                    if (coap_req->block1_num == 0)
                        fd_write = cfs_open(filename, CFS_WRITE);
                    else
                        fd_write = cfs_open(filename, CFS_WRITE | CFS_APPEND);
                    /*memcpy(large_update_store+coap_req->block1_num*coap_req->block1_size, incoming, len);*/
                    if(fd_write != -1)
                    {
                        n = cfs_write(fd_write, incoming, len);
                        cfs_close(fd_write);
                        PRINTF("Successfully appended data to cfs. wrote %i bytes\n", n);
                    }
                    else
                    {
                        REST.set_response_status(response, REST.status.BAD_OPTION);
                        /* A block error message should not exceed the minimum block size (16). */
                        const char *error_msg = "CannotWriteCFS";
                        REST.set_response_payload(response, error_msg, strlen(error_msg));
                        PRINTF("ERROR: could not write to memory \n");
                        return;
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
        }
    }
    else
    {
        REST.set_response_status(response, REST.status.BAD_OPTION);
        /* A block error message should not exceed the minimum block size (16). */
        const char *error_msg = "BadQueryVariable";
        REST.set_response_payload(response, error_msg, strlen(error_msg));
        PRINTF("ERROR: Bad query variable.\n");
        return;
    }
}
#endif

#if REST_RES_PUT
/*
* PUT in flash new application modules
*/
RESOURCE(putData, METHOD_PUT, "data", "tile=\"ELF MODULE: ?filename='filename.ce', PUT APPLICATION/OCTET_STREAM\"; rt=\"Control\"");

void
putData_handler(void* request, void* response, uint8_t *buffer, uint16_t preferred_size, int32_t *offset)
{
    coap_packet_t *const coap_req = (coap_packet_t *) request;
    int fd_write = 0;
    /*int fd_read = 0;*/
    int n = 0;
    const char *file_name;
    char *filename = NULL;
    uint8_t *incoming = NULL;
    size_t len = 0;
    size_t len2 = 0;

    /*PRINTF("Entering to handler \n");*/

    /*unsigned int ct = REST.get_header_content_type(request);
    if (ct==-1)
    {
        REST.set_response_status(response, REST.status.BAD_REQUEST);
        const char *error_msg = "NoContentType";
        REST.set_response_payload(response, error_msg, strlen(error_msg));
        return;
    }*/

    if ((len = REST.get_request_payload(request, (const uint8_t **) &incoming)))
    {
        if ((len2=REST.get_query_variable(request, "filename", &file_name)))
        {
            /*PRINTF("File name: %.*s\n", len2, file_name);*/
            filename = malloc(len2 + 1);
            snprintf(filename, len2 + 1, file_name);
            PRINTF("filename : %s size : %d\n", filename, len2);
        }

        if (coap_req->block1_num*coap_req->block1_size+len <= sizeof(large_update_store))
        {
            if (coap_req->block1_num == 0)
                fd_write = cfs_open(filename, CFS_WRITE);
            else
                fd_write = cfs_open(filename, CFS_WRITE | CFS_APPEND);
            /*memcpy(large_update_store+coap_req->block1_num*coap_req->block1_size, incoming, len);*/
            if(fd_write != -1)
            {
                n = cfs_write(fd_write, incoming, len);
                cfs_close(fd_write);
                free(filename);
                PRINTF("Successfully appended data to cfs. wrote %i bytes\n", n);
            }
            else
            {
                REST.set_response_status(response, REST.status.BAD_OPTION);
                /* A block error message should not exceed the minimum block size (16). */
                const char *error_msg = "CannotWriteCFS";
                REST.set_response_payload(response, error_msg, strlen(error_msg));
                PRINTF("ERROR: could not write to memory \n");
                return;
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
    const char *name = "current.kev";
    const char *name2 = "hello-world.ce";
    int fd_read = 0;

    cfs_remove(name);
    cfs_remove(name2);
    fd_read = cfs_open(name, CFS_READ);

    if (fd_read == -1)
    {
        PRINTF("Successfully removed file\n");
    }
    else
    {
        PRINTF("ERROR: could read from memory, file still exists.\n");
        cfs_close(fd_read);
    }

    fd_read = cfs_open(name2, CFS_READ);

    if (fd_read == -1)
    {
        PRINTF("Successfully removed file\n");
    }
    else
    {
        PRINTF("ERROR: could read from memory, file still exists.\n");
        cfs_close(fd_read);
    }
    PROCESS_BEGIN();
    /*write_current_model();*/
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

    /*PRINTF("uIP buffer: %u\n", UIP_BUFSIZE);
    PRINTF("LL header: %u\n", UIP_LLH_LEN);
    PRINTF("IP+UDP header: %u\n", UIP_IPUDPH_LEN);*/
    PRINTF("REST max chunk: %u\n", REST_MAX_CHUNK_SIZE);
    printf("PORT: %d", REMOTE_PORT);

    rest_init_engine();

#if REST_RES_CHUNKS
    rest_activate_resource(&resource_chunks);
#endif
#if defined (PLATFORM_HAS_BUTTON)
    SENSORS_ACTIVATE(button_sensor);
#endif
#if REST_RES_MODELS
    rest_activate_resource(&resource_models);
#endif
#if REST_RES_PUT
    rest_activate_resource(&resource_putData);
#endif
#if defined (PLATFORM_HAS_LEDS)
#if REST_RES_LEDS
    rest_activate_resource(&resource_leds);
#endif
#endif /* PLATFORM_HAS_LEDS */

  /* Define application-specific events here. */
    while(1)
    {
        PROCESS_WAIT_EVENT();


#if defined (PLATFORM_HAS_BUTTON)
        if (ev == sensors_event && data == &button_sensor) {
            PRINTF("BUTTON\n");
            print_local_addresses();

#if defined (COAP_CLIENT_ENABLED)
            coap_init_message(request, COAP_TYPE_CON, COAP_GET, 0);
            coap_set_header_uri_path(request, "/mavenresolver?group=org.kevoree.helloworld&name=hello_world&version=1.0&extension=.ce\n");


/* TODO call maven resolver paramètres const char*group,const char *group,const char *ext,const const char *urls[]
* copy in file system the file
*/
            printf("--Requesting /mavenresolver?group=org.kevoree.helloworld&name=hello_world&version=1.0&extension=.ce\n");
            /*printf("--Requesting /helloWorld\n");*/

            PRINT6ADDR(&server_ipaddr);
            PRINTF(" : %u\n", UIP_HTONS(REMOTE_PORT));

            COAP_BLOCKING_REQUEST(&server_ipaddr, REMOTE_PORT, request, client_chunk_handler);

            printf("\n--Done--\n");
#endif /* COAP_CLIENT_ENABLED */

        }
#endif /* PLATFORM_HAS_BUTTON */
  } /* while (1) */

  PROCESS_END();
}