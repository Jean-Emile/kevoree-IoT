#include "../../../org.kevoree.iot.firmware/src/main/c/firmware-kevoree/model/DefaultFactorykevoree.h"
#include "../../../org.kevoree.iot.firmware/src/main/c/firmware-kevoree/model/Helperkevoree.h"


 #include <stdlib.h>
 #include <stdio.h>



int main(void){
     int i=0,j;

ContainerRoot *root = createContainerRoot();




ContainerNode *node0 = createContainerNode();
strcpy(node0->name , "node0");

ContainerNode *node1 = createContainerNode();
strcpy(node1->name , "node1");


addnodesContainerRoot(root,node0);


addnodesContainerRoot(root,node1);



for(i=0;i<root->count_nodes;i++){
      ContainerNode *current = root->nodes[i];
      if(current != NULL)
      {
        printf("NodeName %s count_components %d \n",current->name,current->count_components);

            for(j=0;j < current->count_components;j++){
                        ComponentInstance *instance =    current->components[j];
                        printf("Component Instance  %s\n",instance->name);

            }


      }

}



 return 0;
}