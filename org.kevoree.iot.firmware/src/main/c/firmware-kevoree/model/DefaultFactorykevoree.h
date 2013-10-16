#ifndef H_DefaultFactory
#define H_DefaultFactory
#include "kevoree.h"

#include "tools.h"
#include <stdlib.h>





int addContainerRootGroup(ContainerRoot *root,Group *val){
    if(root->count_groups== 0)
    {
        /* printf("DEBUG -- FIRST ADD Group -> ContainerRoot %d \n",root->count_groups);  */
        root->groups = malloc(1*sizeof(struct Group*));
        if(root->groups == NULL)
        {
            printf("FATAL can't allocate Group \n");
            return -1;
        }
        root->groups[root->count_groups] =(struct Group*)val;
        root->count_groups++;
        }
        else
        {
            root->groups = realloc(root->groups,(root->count_groups+1)*sizeof(struct Group*));
            if(root->groups == NULL)
            {
                printf("FATAL can't allocate Group \n");
                return -1;
            }
            root->groups[root->count_groups] =(struct Group*)val;
            root->count_groups++;
        }

    return 0;
}




int addContainerRootContainerNode(ContainerRoot *root,ContainerNode *val){
    if(root->count_nodes== 0)
    {
        /* printf("DEBUG -- FIRST ADD ContainerNode -> ContainerRoot %d \n",root->count_nodes);  */
        root->nodes = malloc(1*sizeof(struct ContainerNode*));
        if(root->nodes == NULL)
        {
            printf("FATAL can't allocate ContainerNode \n");
            return -1;
        }
        root->nodes[root->count_nodes] =(struct ContainerNode*)val;
        root->count_nodes++;
        }
        else
        {
            root->nodes = realloc(root->nodes,(root->count_nodes+1)*sizeof(struct ContainerNode*));
            if(root->nodes == NULL)
            {
                printf("FATAL can't allocate ContainerNode \n");
                return -1;
            }
            root->nodes[root->count_nodes] =(struct ContainerNode*)val;
            root->count_nodes++;
        }

    return 0;
}




int addContainerRootNodeNetwork(ContainerRoot *root,NodeNetwork *val){
    if(root->count_nodeNetworks== 0)
    {
        /* printf("DEBUG -- FIRST ADD NodeNetwork -> ContainerRoot %d \n",root->count_nodeNetworks);  */
        root->nodeNetworks = malloc(1*sizeof(struct NodeNetwork*));
        if(root->nodeNetworks == NULL)
        {
            printf("FATAL can't allocate NodeNetwork \n");
            return -1;
        }
        root->nodeNetworks[root->count_nodeNetworks] =(struct NodeNetwork*)val;
        root->count_nodeNetworks++;
        }
        else
        {
            root->nodeNetworks = realloc(root->nodeNetworks,(root->count_nodeNetworks+1)*sizeof(struct NodeNetwork*));
            if(root->nodeNetworks == NULL)
            {
                printf("FATAL can't allocate NodeNetwork \n");
                return -1;
            }
            root->nodeNetworks[root->count_nodeNetworks] =(struct NodeNetwork*)val;
            root->count_nodeNetworks++;
        }

    return 0;
}




int addContainerRootTypeDefinition(ContainerRoot *root,TypeDefinition *val){
    if(root->count_typedefintions== 0)
    {
        /* printf("DEBUG -- FIRST ADD TypeDefinition -> ContainerRoot %d \n",root->count_typedefintions);  */
        root->typedefintions = malloc(1*sizeof(struct TypeDefinition*));
        if(root->typedefintions == NULL)
        {
            printf("FATAL can't allocate TypeDefinition \n");
            return -1;
        }
        root->typedefintions[root->count_typedefintions] =(struct TypeDefinition*)val;
        root->count_typedefintions++;
        }
        else
        {
            root->typedefintions = realloc(root->typedefintions,(root->count_typedefintions+1)*sizeof(struct TypeDefinition*));
            if(root->typedefintions == NULL)
            {
                printf("FATAL can't allocate TypeDefinition \n");
                return -1;
            }
            root->typedefintions[root->count_typedefintions] =(struct TypeDefinition*)val;
            root->count_typedefintions++;
        }

    return 0;
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
        ptr->count_groups=0;
ptr->groups=NULL;
ptr->count_nodes=0;
ptr->nodes=NULL;
ptr->count_nodeNetworks=0;
ptr->nodeNetworks=NULL;
ptr->count_typedefintions=0;
ptr->typedefintions=NULL;

    }
    return ptr;
}




int addContainerNodeComponentInstance(ContainerNode *root,ComponentInstance *val){
    if(root->count_components== 0)
    {
        /* printf("DEBUG -- FIRST ADD ComponentInstance -> ContainerNode %d \n",root->count_components);  */
        root->components = malloc(1*sizeof(struct ComponentInstance*));
        if(root->components == NULL)
        {
            printf("FATAL can't allocate ComponentInstance \n");
            return -1;
        }
        root->components[root->count_components] =(struct ComponentInstance*)val;
        root->count_components++;
        }
        else
        {
            root->components = realloc(root->components,(root->count_components+1)*sizeof(struct ComponentInstance*));
            if(root->components == NULL)
            {
                printf("FATAL can't allocate ComponentInstance \n");
                return -1;
            }
            root->components[root->count_components] =(struct ComponentInstance*)val;
            root->count_components++;
        }

    return 0;
}




int addContainerNodeNodeNetwork(ContainerNode *root,NodeNetwork *val){
    if(root->count_nodeNetworks== 0)
    {
        /* printf("DEBUG -- FIRST ADD NodeNetwork -> ContainerNode %d \n",root->count_nodeNetworks);  */
        root->nodeNetworks = malloc(1*sizeof(struct NodeNetwork*));
        if(root->nodeNetworks == NULL)
        {
            printf("FATAL can't allocate NodeNetwork \n");
            return -1;
        }
        root->nodeNetworks[root->count_nodeNetworks] =(struct NodeNetwork*)val;
        root->count_nodeNetworks++;
        }
        else
        {
            root->nodeNetworks = realloc(root->nodeNetworks,(root->count_nodeNetworks+1)*sizeof(struct NodeNetwork*));
            if(root->nodeNetworks == NULL)
            {
                printf("FATAL can't allocate NodeNetwork \n");
                return -1;
            }
            root->nodeNetworks[root->count_nodeNetworks] =(struct NodeNetwork*)val;
            root->count_nodeNetworks++;
        }

    return 0;
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
ptr->count_components=0;
ptr->components=NULL;
ptr->typedefintion=NULL;
ptr->count_nodeNetworks=0;
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




int addGroupContainerNode(Group *root,ContainerNode *val){
    if(root->count_subNodes== 0)
    {
        /* printf("DEBUG -- FIRST ADD ContainerNode -> Group %d \n",root->count_subNodes);  */
        root->subNodes = malloc(1*sizeof(struct ContainerNode*));
        if(root->subNodes == NULL)
        {
            printf("FATAL can't allocate ContainerNode \n");
            return -1;
        }
        root->subNodes[root->count_subNodes] =(struct ContainerNode*)val;
        root->count_subNodes++;
        }
        else
        {
            root->subNodes = realloc(root->subNodes,(root->count_subNodes+1)*sizeof(struct ContainerNode*));
            if(root->subNodes == NULL)
            {
                printf("FATAL can't allocate ContainerNode \n");
                return -1;
            }
            root->subNodes[root->count_subNodes] =(struct ContainerNode*)val;
            root->count_subNodes++;
        }

    return 0;
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
        ptr->count_subNodes=0;
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