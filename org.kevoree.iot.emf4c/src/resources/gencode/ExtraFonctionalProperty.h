#ifndef H_ExtraFonctionalProperty
#define H_ExtraFonctionalProperty
 #include <stdlib.h>
 #include <stdio.h>
#include "PortTypeRef.h"

typedef struct _ExtraFonctionalProperty { 
	int count_portTypes;
	struct PortTypeRef **portTypes;
} ExtraFonctionalProperty ;

#endif