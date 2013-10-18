#ifndef H_ContainerRoot
#define H_ContainerRoot
#include <stdlib.h>
#include <stdio.h>
#include "tools.h"
#include "HashMap.h"
#include <string.h>
#include "Group.h"
#include "ContainerNode.h"
#include "NodeNetwork.h"
#include "TypeDefinition.h"

#define ID_TYPE_ContainerRoot 71 
typedef struct _ContainerRoot { 
	map_t groups; // Group
	map_t nodes; // ContainerNode
	map_t nodeNetworks; // NodeNetwork
	map_t typedefintions; // TypeDefinition
	int (*accept)(struct _ContainerRoot*,char *parent,Visitor*);
} ContainerRoot ;

int _acceptContainerRoot(ContainerRoot* this,char *parent,Visitor* visitor) {
int i=0; char path[128];
hashmap_map* m_s;






if(this->groups != NULL){
    m_s = (hashmap_map*) this->groups;
    for(i = 0; i< m_s->table_size; i++)
    {
        if(m_s->data[i].in_use != 0) {
        Group *s = m_s->data[i].data;
        if(parent == NULL){
            sprintf(path,"groups[%s]",m_s->data[i].key);
        }else {
            sprintf(path,"%s/groups[%s]",parent,m_s->data[i].key);
        }


        s->accept(s,path,visitor);
        }
    }
}








if(this->nodes != NULL){
    m_s = (hashmap_map*) this->nodes;
    for(i = 0; i< m_s->table_size; i++)
    {
        if(m_s->data[i].in_use != 0) {
        ContainerNode *s = m_s->data[i].data;
        if(parent == NULL){
            sprintf(path,"nodes[%s]",m_s->data[i].key);
        }else {
            sprintf(path,"%s/nodes[%s]",parent,m_s->data[i].key);
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








if(this->typedefintions != NULL){
    m_s = (hashmap_map*) this->typedefintions;
    for(i = 0; i< m_s->table_size; i++)
    {
        if(m_s->data[i].in_use != 0) {
        TypeDefinition *s = m_s->data[i].data;
        if(parent == NULL){
            sprintf(path,"typedefintions[%s]",m_s->data[i].key);
        }else {
            sprintf(path,"%s/typedefintions[%s]",parent,m_s->data[i].key);
        }


        s->accept(s,path,visitor);
        }
    }
}


}
#endif