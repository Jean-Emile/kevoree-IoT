#ifndef H_ComponentInstance
#define H_ComponentInstance
#include <stdlib.h>
#include <stdio.h>
#include "tools.h"
#include "HashMap.h"
#include <string.h>
#include "TypeDefinition.h"

#define ID_TYPE_ComponentInstance 232 
typedef struct _ComponentInstance { 
	char name[8];
	struct TypeDefinition *typedefinition;
	int (*accept)(struct _ComponentInstance*,char *parent,Visitor*);
} ComponentInstance ;

int _acceptComponentInstance(ComponentInstance* this,char *parent,Visitor* visitor) {
int i=0; char path[128];
sprintf(path,"%s/name",parent);
visitor->action((void*)this->name,path,ID_TYPE_CHAR);
hashmap_map* m_s;
}
#endif