#ifndef H_Group
#define H_Group
 #include <stdlib.h>
 #include <stdio.h>
#include "TypeDefinition.h"
#include "Dictionary.h"
#include "ContainerNode.h"

typedef struct _Group { 
	char * name;
	char * metaData;
	short started;
	struct TypeDefinition *typeDefinition;
	struct Dictionary *dictionary;
	int count_subNodes;
	struct ContainerNode **subNodes;
} Group ;

#endif