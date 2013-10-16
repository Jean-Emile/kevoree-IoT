#ifndef H_ContainerRoot
#define H_ContainerRoot
#include <stdlib.h>
#include <stdio.h>
#include "tools.h"
#include <string.h>
#include "Group.h"
#include "ContainerNode.h"
#include "NodeNetwork.h"
#include "TypeDefinition.h"

typedef struct _ContainerRoot { 
	int count_groups;
	struct Group **groups;
	int count_nodes;
	struct ContainerNode **nodes;
	int count_nodeNetworks;
	struct NodeNetwork **nodeNetworks;
	int count_typedefintions;
	struct TypeDefinition **typedefintions;
	int (*accept)(struct _ContainerRoot*,struct _ContainerRoot*, Visitor*);
} ContainerRoot ;

int _acceptContainerRoot(ContainerRoot* this,ContainerRoot* c,Visitor* visitor) {
int i;
for(i=0;i<this->count_groups;i++)
{
    visitor->action((void*)this->groups,(void*)c->groups,0);
}
for(i=0;i<this->count_nodes;i++){
visitor->action((void*)this->nodes,(void*)c->nodes,0);
}
for(i=0;i<this->count_nodeNetworks;i++){
visitor->action((void*)this->nodeNetworks,(void*)c->nodeNetworks,0);
}
for(i=0;i<this->count_typedefintions;i++){
visitor->action((void*)this->typedefintions,(void*)c->typedefintions,0);
}
}
#endif