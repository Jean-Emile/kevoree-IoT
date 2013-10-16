#ifndef H_ContainerNode
#define H_ContainerNode
#include <stdlib.h>
#include <stdio.h>
#include "tools.h"
#include <string.h>
#include "ComponentInstance.h"
#include "TypeDefinition.h"
#include "NodeNetwork.h"

typedef struct _ContainerNode { 
	char name[8];
	int started;
	int count_components;
	struct ComponentInstance **components;
	struct TypeDefinition *typedefintion;
	int count_nodeNetworks;
	struct NodeNetwork **nodeNetworks;
	int (*accept)(struct _ContainerNode*,struct _ContainerNode*, Visitor*);
} ContainerNode ;

int _acceptContainerNode(ContainerNode* this,ContainerNode* c,Visitor* visitor) {
int i;
visitor->action((void*)this->name,(void*)c->name,0);
visitor->action((void*)this->started,(void*)c->started,0);
for(i=0;i<this->count_components;i++){
visitor->action((void*)this->components,(void*)c->components,0);
}
visitor->action((void*)this->typedefintion,(void*)c->typedefintion,0);
for(i=0;i<this->count_nodeNetworks;i++){
visitor->action((void*)this->nodeNetworks,(void*)c->nodeNetworks,0);
}
}
#endif