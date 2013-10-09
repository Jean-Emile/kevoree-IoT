#ifndef H_TypeLibrary
#define H_TypeLibrary
 #include <stdlib.h>
 #include <stdio.h>
#include "TypeDefinition.h"

typedef struct _TypeLibrary { 
	char * name;
	int count_subTypes;
	struct TypeDefinition **subTypes;
} TypeLibrary ;

#endif