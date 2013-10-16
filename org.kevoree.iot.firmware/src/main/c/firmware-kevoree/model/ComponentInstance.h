#ifndef H_ComponentInstance
#define H_ComponentInstance
#include <stdlib.h>
#include <stdio.h>
#include "tools.h"
#include <string.h>
#include "TypeDefinition.h"

typedef struct _ComponentInstance { 
	char name[16];
	struct TypeDefinition *typedefinition;
	int (*accept)(struct _ComponentInstance*,struct _ComponentInstance*, Visitor*);
} ComponentInstance ;

int _acceptComponentInstance(ComponentInstance* this,ComponentInstance* c,Visitor* visitor) {
int i;
visitor->action((void*)this->name,(void*)c->name,0);
visitor->action((void*)this->typedefinition,(void*)c->typedefinition,0);
}
#endif