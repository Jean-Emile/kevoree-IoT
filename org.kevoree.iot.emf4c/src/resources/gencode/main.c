#include "DefaultFactorykevoree.h"
#include "Helperkevoree.h"


 #include <stdlib.h>
 #include <stdio.h>



int main(void){
     int i=0,j;

ContainerRoot *root = createContainerRoot();



ContainerNode *node0 = createContainerNode();
node0->name = "powet";
node0->started = 0;


ComponentInstance *instance = createComponentInstance();
instance->name= "FakeConsole";
instance->started = 0;


addcomponentsContainerNode(node0,instance);



addnodesContainerRoot(root,node0);





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