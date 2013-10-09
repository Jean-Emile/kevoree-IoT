#ifndef H_Port
#define H_Port
 #include <stdlib.h>
 #include <stdio.h>
#include "MBinding.h"
#include "PortTypeRef.h"

typedef struct _Port { 
	int count_bindings;
	struct MBinding **bindings;
	struct PortTypeRef *portTypeRef;
} Port ;

#endif