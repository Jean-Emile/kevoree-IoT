


#include <netdb.h>
#include <string.h>

#include <arpa/inet.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

//http://draft.scyphus.co.jp/lang/c/url_parser.html

struct parsed_url {
	char *scheme;               /* mandatory */
	char *host;                 /* mandatory */
	char *port;                 /* optional */
	char *path;                 /* optional */
	char *query;                /* optional */
	char *fragment;             /* optional */
	char *username;             /* optional */
	char *password;             /* optional */
};

typedef struct _URL{
	char *host;
	char *query;
} URL;


void download(URL url,char *path){

	int sockfd, c;
	struct sockaddr_in addr;

	struct hostent *host = gethostbyname(url.host);

	printf("name: %s\n", host->h_name);

	sockfd = socket(PF_INET, SOCK_STREAM, 0);

	addr.sin_family = AF_INET;
	addr.sin_port = htons(80);
	addr.sin_addr = *((struct in_addr *)host->h_addr);
	memset(addr.sin_zero, '\0', sizeof addr.sin_zero);

	c = connect(sockfd, (struct sockaddr *)&addr, sizeof addr);

	while(c == -1)
	{
		//	sleep(5);
		c = connect(sockfd, (struct sockaddr *)&addr, sizeof addr);
	}
	char packet[1024];

	sprintf(&packet,"GET %s/%s HTTP/1.0\r\n\r\n",url.query,path);
	printf("%s \n",packet);

	send(sockfd, packet, strlen(packet), 0);

    char *buffer = (char*)malloc(56);

    char *response = (char*)malloc(4000);


	ssize_t bytes_read_total = 0;
	ssize_t bytes_read = 1;
	char *end_of_data = response;
	while(bytes_read > 0)
	{
	    bytes_read = recv(sockfd, buffer, 56, 0) ;
	    bytes_read_total +=bytes_read;
	    if (bytes_read > 0)
	    {
	    	
	        memcpy(end_of_data, buffer, bytes_read);
	        end_of_data += bytes_read;

	        //strcat(response, buffer);
	      //  memset(buffer, NULL, 56);
	    }
	}
	printf("%d \n",bytes_read_total);
	


	// 

}


