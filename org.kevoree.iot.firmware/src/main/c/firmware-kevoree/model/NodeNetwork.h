#ifndef H_NodeNetwork
#define H_NodeNetwork
#include <stdlib.h>
#include <stdio.h>
#include "tools.h"
#include <string.h>

typedef struct _NodeNetwork { 
	char networkType[8];
	char value[8];
	int (*accept)(struct _NodeNetwork*,struct _NodeNetwork*, Visitor*);
} NodeNetwork ;

int _acceptNodeNetwork(NodeNetwork* this,NodeNetwork* c,Visitor* visitor) {
int i;
visitor->action((void*)this->networkType,(void*)c->networkType,0);
visitor->action((void*)this->value,(void*)c->value,0);
}
#endif