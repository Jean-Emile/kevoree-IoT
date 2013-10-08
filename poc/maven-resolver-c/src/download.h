

#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

typedef struct _HOST{
	char *host;
	char *query;
} HOST;

typedef struct _URLS {
	HOST hosts[32];
	int count;
} URLS ;
enum {
	N0T_FOUND_404,
	FOUND
};
typedef struct _MAVEN_ARTEFACT_FILE{
	char *data;
    int len;
    int state;
} MAVEN_ARTEFACT_RESULT;

int str_contains(const char *haystack, const char *needle)
{
	char *pos = (char*)strstr(haystack, needle);
	if(pos)
		return 1;
	else
		return 0;
}

MAVEN_ARTEFACT_RESULT download(HOST url,char *path){

	int sockfd, c;
	struct sockaddr_in addr;
	MAVEN_ARTEFACT_RESULT result;

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
		sleep(5);
		c = connect(sockfd, (struct sockaddr *)&addr, sizeof addr);
	}
	char packet[1024];

	sprintf(&packet[0],"GET %s/%s HTTP/1.0\r\n\r\n",url.query,path);

	send(sockfd, packet, strlen(packet), 0);

	char *buffer = (char*)malloc(56);
	char *data =  (char*)malloc(56);
	memset(data, 0, 56);

	ssize_t bytes_read_total = 0;
	ssize_t bytes_read = 1;

	while(bytes_read > 0)
	{
		bytes_read = recv(sockfd, buffer, 56, 0) ;

		if (bytes_read > 0)
		{
			data = (char *) realloc(data, bytes_read_total +bytes_read+1);
			memcpy(data + bytes_read_total, buffer, bytes_read);
			memset(buffer, 0, 56);
		}
		bytes_read_total +=bytes_read;
	}
	
	if(str_contains(data,"HTTP/1.1 404 Not Found") == 1 || str_contains(data,"HTTP/1.0 404 Not Found") ==1){
		printf("404 \n");
		free(buffer);
		free(data);
		bytes_read_total=0;
		result.data = NULL;
		result.len = 0;
		result.state = N0T_FOUND_404;
	}else {
		result.data = data;
		result.len = bytes_read_total;
		result.state = FOUND;
	}
	
	//HTTP/1.0 404 Not Found
	

	FILE *f = fopen("/tmp/test.jar","a");
	int i=0;
	for(i=0;i<bytes_read_total;i++){
		fprintf(f,"%c",data[i]);	
	}				
	fclose(f);



	// 
	return result;

}


