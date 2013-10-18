#ifndef H_TypeDefinition
#define H_TypeDefinition
#include <stdlib.h>
#include <stdio.h>
#include "tools.h"
#include "HashMap.h"
#include <string.h>

#define ID_TYPE_TypeDefinition 171 
typedef struct _TypeDefinition { 
	char query[8];
	int (*accept)(struct _TypeDefinition*,char *parent,Visitor*);
} TypeDefinition ;

int _acceptTypeDefinition(TypeDefinition* this,char *parent,Visitor* visitor) {
int i=0; char path[128];
sprintf(path,"%s/query",parent);
visitor->action((void*)this->query,path,ID_TYPE_CHAR);
hashmap_map* m_s;
}
#endif