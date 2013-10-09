#ifndef H_AdaptationPrimitiveTypeRef
#define H_AdaptationPrimitiveTypeRef
 #include <stdlib.h>
 #include <stdio.h>
#include "AdaptationPrimitiveType.h"

typedef struct _AdaptationPrimitiveTypeRef { 
	char * maxTime;
	struct AdaptationPrimitiveType *ref;
} AdaptationPrimitiveTypeRef ;

#endif