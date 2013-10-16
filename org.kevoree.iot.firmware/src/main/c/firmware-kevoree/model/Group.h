#ifndef H_Group
#define H_Group
#include <stdlib.h>
#include <stdio.h>
#include "tools.h"
#include <string.h>
#include "ContainerNode.h"

typedef struct _Group { 
	int count_subNodes;
	struct ContainerNode **subNodes;
	int (*accept)(struct _Group*,struct _Group*, Visitor*);
} Group ;

int _acceptGroup(Group* this,Group* c,Visitor* visitor) {
int i;
for(i=0;i<this->count_subNodes;i++){
visitor->action((void*)this->subNodes,(void*)c->subNodes,0);
}
}
#endif