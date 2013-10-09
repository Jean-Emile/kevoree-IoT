#ifndef H_MBinding
#define H_MBinding
 #include <stdlib.h>
 #include <stdio.h>
#include "Port.h"
#include "Channel.h"

typedef struct _MBinding { 
	struct Port *port;
	struct Channel *hub;
} MBinding ;

#endif