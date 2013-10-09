#ifndef H_ComponentInstance
#define H_ComponentInstance
 #include <stdlib.h>
 #include <stdio.h>
#include "TypeDefinition.h"
#include "Dictionary.h"
#include "Port.h"
#include "Port.h"
#include "Namespace.h"

typedef struct _ComponentInstance { 
	char * name;
	char * metaData;
	short started;
	struct TypeDefinition *typeDefinition;
	struct Dictionary *dictionary;
	int count_provided;
	struct Port **provided;
	int count_required;
	struct Port **required;
	struct Namespace *namespace;
} ComponentInstance ;

#endif