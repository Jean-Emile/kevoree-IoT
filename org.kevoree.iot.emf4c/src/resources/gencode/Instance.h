#ifndef H_Instance
#define H_Instance
 #include <stdlib.h>
 #include <stdio.h>
#include "TypeDefinition.h"
#include "Dictionary.h"

typedef struct _Instance { 
	char * name;
	char * metaData;
	short started;
	struct TypeDefinition *typeDefinition;
	struct Dictionary *dictionary;
} Instance ;

#endif