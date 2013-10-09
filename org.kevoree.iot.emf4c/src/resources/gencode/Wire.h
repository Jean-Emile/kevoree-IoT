#ifndef H_Wire
#define H_Wire
 #include <stdlib.h>
 #include <stdio.h>
#include "PortTypeRef.h"

typedef struct _Wire { 
	struct PortTypeRef *ports;
} Wire ;

#endif