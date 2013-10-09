#ifndef H_DeployUnit
#define H_DeployUnit
 #include <stdlib.h>
 #include <stdio.h>
#include "DeployUnit.h"
#include "NodeType.h"

typedef struct _DeployUnit { 
	char * name;
	char * groupName;
	char * unitName;
	char * version;
	char * url;
	char * hashcode;
	char * type;
	int count_requiredLibs;
	struct DeployUnit **requiredLibs;
	struct NodeType *targetNodeType;
} DeployUnit ;

#endif