#ifndef H_NodeLink
#define H_NodeLink
 #include <stdlib.h>
 #include <stdio.h>
#include "NetworkProperty.h"

typedef struct _NodeLink { 
	char * networkType;
	int estimatedRate;
	char * lastCheck;
	char * zoneID;
	int count_networkProperties;
	struct NetworkProperty **networkProperties;
} NodeLink ;

#endif