#ifndef H_DefaultFactory
#define H_DefaultFactory
#include "Kevoree.h"

#include "tools.h"
#include <stdlib.h>






int addContainerRootGroup(ContainerRoot *root,Group *val)
{
    if(root->groups== NULL)
    {
        root->groups = hashmap_new();
        if(root->groups == NULL)
        {
            printf("FATAL ALLOCATE HASHMAP Group \n");
            return -1;
        }
    }
    if(hashmap_put(root->groups,val->name,val) != MAP_OK)
    {
        printf("ERROR ADD  Group \n");
    }

    return 0;
}


Group* findByIDContainerRootGroup(ContainerRoot *root,void *id)
{
    if(root->groups!= NULL)
    {
        Group  *result=NULL;
        if(hashmap_get(root->groups,id, (void**)(&result)) == MAP_OK){
            return result;
        }
         return NULL;
    }else
    {
        return NULL;
    }
}





int addContainerRootContainerNode(ContainerRoot *root,ContainerNode *val)
{
    if(root->nodes== NULL)
    {
        root->nodes = hashmap_new();
        if(root->nodes == NULL)
        {
            printf("FATAL ALLOCATE HASHMAP ContainerNode \n");
            return -1;
        }
    }
    if(hashmap_put(root->nodes,val->name,val) != MAP_OK)
    {
        printf("ERROR ADD  ContainerNode \n");
    }

    return 0;
}


ContainerNode* findByIDContainerRootContainerNode(ContainerRoot *root,void *id)
{
    if(root->nodes!= NULL)
    {
        ContainerNode  *result=NULL;
        if(hashmap_get(root->nodes,id, (void**)(&result)) == MAP_OK){
            return result;
        }
         return NULL;
    }else
    {
        return NULL;
    }
}





int addContainerRootNodeNetwork(ContainerRoot *root,NodeNetwork *val)
{
    if(root->nodeNetworks== NULL)
    {
        root->nodeNetworks = hashmap_new();
        if(root->nodeNetworks == NULL)
        {
            printf("FATAL ALLOCATE HASHMAP NodeNetwork \n");
            return -1;
        }
    }
    if(hashmap_put(root->nodeNetworks,val->value,val) != MAP_OK)
    {
        printf("ERROR ADD  NodeNetwork \n");
    }

    return 0;
}


NodeNetwork* findByIDContainerRootNodeNetwork(ContainerRoot *root,void *id)
{
    if(root->nodeNetworks!= NULL)
    {
        NodeNetwork  *result=NULL;
        if(hashmap_get(root->nodeNetworks,id, (void**)(&result)) == MAP_OK){
            return result;
        }
         return NULL;
    }else
    {
        return NULL;
    }
}





int addContainerRootTypeDefinition(ContainerRoot *root,TypeDefinition *val)
{
    if(root->typedefintions== NULL)
    {
        root->typedefintions = hashmap_new();
        if(root->typedefintions == NULL)
        {
            printf("FATAL ALLOCATE HASHMAP TypeDefinition \n");
            return -1;
        }
    }
    if(hashmap_put(root->typedefintions,val->query,val) != MAP_OK)
    {
        printf("ERROR ADD  TypeDefinition \n");
    }

    return 0;
}


TypeDefinition* findByIDContainerRootTypeDefinition(ContainerRoot *root,void *id)
{
    if(root->typedefintions!= NULL)
    {
        TypeDefinition  *result=NULL;
        if(hashmap_get(root->typedefintions,id, (void**)(&result)) == MAP_OK){
            return result;
        }
         return NULL;
    }else
    {
        return NULL;
    }
}



ContainerRoot * createContainerRoot(void)
{
    ContainerRoot *ptr = (ContainerRoot*)malloc(sizeof(ContainerRoot));
    if(ptr == NULL)
    {
        printf("FATAL can't allocate ContainerRoot \n");
        return NULL;
    }
    else
    {
        ptr->accept = _acceptContainerRoot;
        ptr->groups=NULL;
ptr->nodes=NULL;
ptr->nodeNetworks=NULL;
ptr->typedefintions=NULL;

    }
    return ptr;
}





int addContainerNodeComponentInstance(ContainerNode *root,ComponentInstance *val)
{
    if(root->components== NULL)
    {
        root->components = hashmap_new();
        if(root->components == NULL)
        {
            printf("FATAL ALLOCATE HASHMAP ComponentInstance \n");
            return -1;
        }
    }
    if(hashmap_put(root->components,val->name,val) != MAP_OK)
    {
        printf("ERROR ADD  ComponentInstance \n");
    }

    return 0;
}


ComponentInstance* findByIDContainerNodeComponentInstance(ContainerNode *root,void *id)
{
    if(root->components!= NULL)
    {
        ComponentInstance  *result=NULL;
        if(hashmap_get(root->components,id, (void**)(&result)) == MAP_OK){
            return result;
        }
         return NULL;
    }else
    {
        return NULL;
    }
}





int addContainerNodeNodeNetwork(ContainerNode *root,NodeNetwork *val)
{
    if(root->nodeNetworks== NULL)
    {
        root->nodeNetworks = hashmap_new();
        if(root->nodeNetworks == NULL)
        {
            printf("FATAL ALLOCATE HASHMAP NodeNetwork \n");
            return -1;
        }
    }
    if(hashmap_put(root->nodeNetworks,val->value,val) != MAP_OK)
    {
        printf("ERROR ADD  NodeNetwork \n");
    }

    return 0;
}


NodeNetwork* findByIDContainerNodeNodeNetwork(ContainerNode *root,void *id)
{
    if(root->nodeNetworks!= NULL)
    {
        NodeNetwork  *result=NULL;
        if(hashmap_get(root->nodeNetworks,id, (void**)(&result)) == MAP_OK){
            return result;
        }
         return NULL;
    }else
    {
        return NULL;
    }
}



ContainerNode * createContainerNode(void)
{
    ContainerNode *ptr = (ContainerNode*)malloc(sizeof(ContainerNode));
    if(ptr == NULL)
    {
        printf("FATAL can't allocate ContainerNode \n");
        return NULL;
    }
    else
    {
        ptr->accept = _acceptContainerNode;
        ptr->started=0;
ptr->components=NULL;
ptr->typedefintion=NULL;
ptr->nodeNetworks=NULL;

    }
    return ptr;
}



ComponentInstance * createComponentInstance(void)
{
    ComponentInstance *ptr = (ComponentInstance*)malloc(sizeof(ComponentInstance));
    if(ptr == NULL)
    {
        printf("FATAL can't allocate ComponentInstance \n");
        return NULL;
    }
    else
    {
        ptr->accept = _acceptComponentInstance;
        ptr->typedefinition=NULL;

    }
    return ptr;
}





int addGroupContainerNode(Group *root,ContainerNode *val)
{
    if(root->subNodes== NULL)
    {
        root->subNodes = hashmap_new();
        if(root->subNodes == NULL)
        {
            printf("FATAL ALLOCATE HASHMAP ContainerNode \n");
            return -1;
        }
    }
    if(hashmap_put(root->subNodes,val->name,val) != MAP_OK)
    {
        printf("ERROR ADD  ContainerNode \n");
    }

    return 0;
}


ContainerNode* findByIDGroupContainerNode(Group *root,void *id)
{
    if(root->subNodes!= NULL)
    {
        ContainerNode  *result=NULL;
        if(hashmap_get(root->subNodes,id, (void**)(&result)) == MAP_OK){
            return result;
        }
         return NULL;
    }else
    {
        return NULL;
    }
}



Group * createGroup(void)
{
    Group *ptr = (Group*)malloc(sizeof(Group));
    if(ptr == NULL)
    {
        printf("FATAL can't allocate Group \n");
        return NULL;
    }
    else
    {
        ptr->accept = _acceptGroup;
        ptr->subNodes=NULL;

    }
    return ptr;
}



TypeDefinition * createTypeDefinition(void)
{
    TypeDefinition *ptr = (TypeDefinition*)malloc(sizeof(TypeDefinition));
    if(ptr == NULL)
    {
        printf("FATAL can't allocate TypeDefinition \n");
        return NULL;
    }
    else
    {
        ptr->accept = _acceptTypeDefinition;
        
    }
    return ptr;
}



NodeNetwork * createNodeNetwork(void)
{
    NodeNetwork *ptr = (NodeNetwork*)malloc(sizeof(NodeNetwork));
    if(ptr == NULL)
    {
        printf("FATAL can't allocate NodeNetwork \n");
        return NULL;
    }
    else
    {
        ptr->accept = _acceptNodeNetwork;
        
    }
    return ptr;
}
#endif