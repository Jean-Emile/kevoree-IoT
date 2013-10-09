#ifndef H_Operation
#define H_Operation
 #include <stdlib.h>
 #include <stdio.h>
#include "Parameter.h"
#include "TypedElement.h"

typedef struct _Operation { 
	char * name;
	int count_parameters;
	struct Parameter **parameters;
	struct TypedElement *returnType;
} Operation ;

#endif