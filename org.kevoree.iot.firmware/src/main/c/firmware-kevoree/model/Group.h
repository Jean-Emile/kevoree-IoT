#ifndef H_Group
#define H_Group
#include <stdlib.h>
#include <stdio.h>
#include "tools.h"
#include "HashMap.h"
#include <string.h>
#include "ContainerNode.h"

#define ID_TYPE_Group 13 
typedef struct _Group { 
	char name[8];
	map_t subNodes; // ContainerNode
	int (*accept)(struct _Group*,char *parent,Visitor*);
} Group ;

int _acceptGroup(Group* this,char *parent,Visitor* visitor) {
int i=0; char path[128];
sprintf(path,"%s/name",parent);
visitor->action((void*)this->name,path,ID_TYPE_CHAR);
hashmap_map* m_s;






if(this->subNodes != NULL){
    m_s = (hashmap_map*) this->subNodes;
    for(i = 0; i< m_s->table_size; i++)
    {
        if(m_s->data[i].in_use != 0) {
        ContainerNode *s = m_s->data[i].data;
        if(parent == NULL){
            sprintf(path,"subNodes[%s]",m_s->data[i].key);
        }else {
            sprintf(path,"%s/subNodes[%s]",parent,m_s->data[i].key);
        }


        s->accept(s,path,visitor);
        }
    }
}


}
#endif