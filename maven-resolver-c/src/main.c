
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "download.h"
#include "server.h"



#define DEBUG 1
#define N_URLS 1 

#if DEBUG
#include <stdio.h>
#define PRINTF(...) printf(__VA_ARGS__)
#else
#define PRINTF(...)
#endif

#include "maven.h"





int main(void){

	

/*	URL s[N_URLS];
	s[0].host = "oss.sonatype.org";
	s[0].query = "/content/groups/public";

	MAVEN_ARTEFACT_RESULT result = resolve("org.kevoree","org.kevoree.core","2.0.12","jar", s);
	
	printf("Result %d bytes \n",result.len);
*/
	init_server(9005);
	return 0;
}