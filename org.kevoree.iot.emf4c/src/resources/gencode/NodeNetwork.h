#ifndef H_NodeNetwork
#define H_NodeNetwork
 #include <stdlib.h>
 #include <stdio.h>
#include "NodeLink.h"
#include "ContainerNode.h"
#include "ContainerNode.h"

typedef struct _NodeNetwork { 
	int count_link;
	struct NodeLink **link;
	struct ContainerNode *initBy;
	struct ContainerNode *target;
} NodeNetwork ;

#endif