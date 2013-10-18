#ifndef H_ContainerNode
#define H_ContainerNode
#include <stdlib.h>
#include <stdio.h>
#include "tools.h"
#include "HashMap.h"
#include <string.h>
#include "ComponentInstance.h"
#include "TypeDefinition.h"
#include "NodeNetwork.h"

#define ID_TYPE_ContainerNode 41 
typedef struct _ContainerNode { 
	char name[8];
	int started;
	map_t components; // ComponentInstance
	struct TypeDefinition *typedefintion;
	map_t nodeNetworks; // NodeNetwork
	int (*accept)(struct _ContainerNode*,char *parent,Visitor*);
} ContainerNode ;

int _acceptContainerNode(ContainerNode* this,char *parent,Visitor* visitor) {
int i=0; char path[128];
sprintf(path,"%s/name",parent);
visitor->action((void*)this->name,path,ID_TYPE_CHAR);
sprintf(path,"%s/started",parent);
visitor->action((void*)this->started,path,ID_TYPE_INT);
hashmap_map* m_s;






if(this->components != NULL){
    m_s = (hashmap_map*) this->components;
    for(i = 0; i< m_s->table_size; i++)
    {
        if(m_s->data[i].in_use != 0) {
        ComponentInstance *s = m_s->data[i].data;
        if(parent == NULL){
            sprintf(path,"components[%s]",m_s->data[i].key);
        }else {
            sprintf(path,"%s/components[%s]",parent,m_s->data[i].key);
        }


        s->accept(s,path,visitor);
        }
    }
}








if(this->nodeNetworks != NULL){
    m_s = (hashmap_map*) this->nodeNetworks;
    for(i = 0; i< m_s->table_size; i++)
    {
        if(m_s->data[i].in_use != 0) {
        NodeNetwork *s = m_s->data[i].data;
        if(parent == NULL){
            sprintf(path,"nodeNetworks[%s]",m_s->data[i].key);
        }else {
            sprintf(path,"%s/nodeNetworks[%s]",parent,m_s->data[i].key);
        }


        s->accept(s,path,visitor);
        }
    }
}


}
#endif