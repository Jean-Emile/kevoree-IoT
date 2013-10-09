#ifndef H_Parameter
#define H_Parameter
 #include <stdlib.h>
 #include <stdio.h>
#include "TypedElement.h"

typedef struct _Parameter { 
	char * name;
	int order;
	struct TypedElement *type;
} Parameter ;

#endif