#ifndef H_TypeDefinition
#define H_TypeDefinition
#include <stdlib.h>
#include <stdio.h>
#include "tools.h"
#include <string.h>

typedef struct _TypeDefinition { 
	char query[8];
	int (*accept)(struct _TypeDefinition*,struct _TypeDefinition*, Visitor*);
} TypeDefinition ;

int _acceptTypeDefinition(TypeDefinition* this,TypeDefinition* c,Visitor* visitor) {
int i;
visitor->action((void*)this->query,(void*)c->query,0);
}
#endif