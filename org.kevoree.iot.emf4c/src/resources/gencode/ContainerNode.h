#ifndef H_ContainerNode
#define H_ContainerNode
 #include <stdlib.h>
 #include <stdio.h>
#include "TypeDefinition.h"
#include "Dictionary.h"
#include "ComponentInstance.h"
#include "ContainerNode.h"
#include "ContainerNode.h"

typedef struct _ContainerNode { 
	char * name;
	char * metaData;
	short started;
	struct TypeDefinition *typeDefinition;
	struct Dictionary *dictionary;
	int count_components;
	struct ComponentInstance **components;
	int count_hosts;
	struct ContainerNode **hosts;
	struct ContainerNode *host;
} ContainerNode ;

#endif