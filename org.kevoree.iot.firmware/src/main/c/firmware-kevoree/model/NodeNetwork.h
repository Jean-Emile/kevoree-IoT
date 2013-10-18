#ifndef H_NodeNetwork
#define H_NodeNetwork
#include <stdlib.h>
#include <stdio.h>
#include "tools.h"
#include "HashMap.h"
#include <string.h>

#define ID_TYPE_NodeNetwork 112 
typedef struct _NodeNetwork { 
	char networkType[8];
	char value[8];
	int (*accept)(struct _NodeNetwork*,char *parent,Visitor*);
} NodeNetwork ;

int _acceptNodeNetwork(NodeNetwork* this,char *parent,Visitor* visitor) {
int i=0; char path[128];
sprintf(path,"%s/networkType",parent);
visitor->action((void*)this->networkType,path,ID_TYPE_CHAR);
sprintf(path,"%s/value",parent);
visitor->action((void*)this->value,path,ID_TYPE_CHAR);
hashmap_map* m_s;
}
#endif