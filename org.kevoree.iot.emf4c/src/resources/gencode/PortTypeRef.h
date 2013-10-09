#ifndef H_PortTypeRef
#define H_PortTypeRef
 #include <stdlib.h>
 #include <stdio.h>
#include "PortType.h"
#include "PortTypeMapping.h"

typedef struct _PortTypeRef { 
	char * name;
	short optional;
	short noDependency;
	struct PortType *ref;
	int count_mappings;
	struct PortTypeMapping **mappings;
} PortTypeRef ;

#endif