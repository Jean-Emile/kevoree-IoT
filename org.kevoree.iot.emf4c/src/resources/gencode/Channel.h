#ifndef H_Channel
#define H_Channel
 #include <stdlib.h>
 #include <stdio.h>
#include "TypeDefinition.h"
#include "Dictionary.h"
#include "MBinding.h"

typedef struct _Channel { 
	char * name;
	char * metaData;
	short started;
	struct TypeDefinition *typeDefinition;
	struct Dictionary *dictionary;
	int count_bindings;
	struct MBinding **bindings;
} Channel ;

#endif