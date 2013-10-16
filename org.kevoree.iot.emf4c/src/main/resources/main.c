#include "/home/jed/KEVOREE_PROJECT/kevoree-IoT/org.kevoree.iot.firmware/src/main/c/firmware-kevoree/model/DefaultFactorykevoree.h"
//#include "/home/jed/KEVOREE_PROJECT/kevoree-IoT/org.kevoree.iot.firmware/src/main/c/firmware-kevoree/model/Comparekevoree.h"


 #include <stdlib.h>
 #include <stdio.h>


void actionprintf(void *val,void *val2,int type)
{

    switch(type){

              case 0:
                    if(val != NULL){
                                        printf("%s - %s \n",(char*)val,(char*)val2);
                    }
                    break;

                    case 1:
                                    printf("%d\n",(int)val);
                    break;


    }

}
int main(void){
     int i=0,j;
   /*
ContainerRoot *root = createContainerRoot();

ContainerRoot *root2 = createContainerRoot();




ContainerNode *node0 = createContainerNode();
strcpy(node0->name , "node0");

ContainerNode *node1 = createContainerNode();
strcpy(node1->name , "node1");

addContainerRootContainerNode(root,node0);

Visitor *visitor = (Visitor*)malloc(sizeof(Visitor));
visitor->action = actionprintf;

root->accept(root,root2,visitor);
*/




 return 0;
}