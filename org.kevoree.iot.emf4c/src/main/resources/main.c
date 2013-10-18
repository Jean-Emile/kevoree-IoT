#include "/home/jed/KEVOREE_PROJECT/kevoree-IoT/org.kevoree.iot.firmware/src/main/c/firmware-kevoree/model/DefaultFactoryKevoree.h"
//#include "/home/jed/KEVOREE_PROJECT/kevoree-IoT/org.kevoree.iot.firmware/src/main/c/firmware-kevoree/model/Comparekevoree.h"
#include "/home/jed/KEVOREE_PROJECT/kevoree-IoT/org.kevoree.iot.firmware/src/main/c/firmware-kevoree/model/HashMap.h"
#include "/home/jed/KEVOREE_PROJECT/kevoree-IoT/org.kevoree.iot.firmware/src/main/c/firmware-kevoree/model/tools.h"

 #include <stdlib.h>
 #include <stdio.h>

ContainerRoot *root;



  //nodes[node1]/name
void* findbyPath(void *root,char *_path)
{

         char *path = strdup(_path);
         char * pch;

         if(indexOf(path,"/") != -1)
         {
               pch = strtok (path,"/");
         } else
         {
            pch = path;
         }

         int i =indexOf(pch,"[")+2;
         int y =lastIndexOf(pch,"]")-i+1;

         char *relationName  =  substring(pch,0,i-2);
         char *queryID =  substring(pch,i,y);
          char *attribute = strtok (NULL,"/");


          if(attribute == NULL)
          {
                 if(!strcmp("nodes",relationName))
                   {

                      return  findByIDContainerRootContainerNode(root,queryID);
                   };


          } else {


                    if(!strcmp("nodes",relationName))
                   {

                      ContainerNode *node =  findByIDContainerRootContainerNode(root,queryID);
                      if(node != NULL)
                      {

                          if(!strcmp("name",attribute))
                          {

                               return node->name;
                          }



                      }
                   };

          }


}

void actionprintf(void *val,char *path,int type)
{
    switch(type){

              case ID_TYPE_CHAR:
                    if(val != NULL){
                                 //    printf("%s  {%s} \n",path,(char*)val);
                                             findbyPath(root,path);


                    }
                    break;

                    case ID_TYPE_INT:
                              //    printf("%s  {%d} \n",path,(int)val);
                                       findbyPath(root,path);

                    break;

    }

}





int main(void){
     int i=0,j;


root = createContainerRoot();


 printf("ContainerRoot %d\n",sizeof(ContainerRoot));

ContainerNode *node0 = createContainerNode();
strcpy(node0->name , "node0");


   printf("ContainerNode %d\n",sizeof(ContainerNode)+sizeof(NodeNetwork));


ComponentInstance *c1 = createComponentInstance();
strcpy(c1->name , "c1");


              printf("ComponentInstance %d\n",sizeof(ComponentInstance)+sizeof(TypeDefinition));



ComponentInstance *c2 = createComponentInstance();
strcpy(c2->name , "c2");


addContainerRootContainerNode(root,node0);



addContainerNodeComponentInstance(node0,c1);

 addContainerNodeComponentInstance(node0,c2);


 void *r = findbyPath(root,"nodes[node0]/components[fakeconsole]");

 if(r !=NULL){
    printf("OK\n");
 }





ContainerNode *result = findByIDContainerRootContainerNode(root,"node0") ;


     Visitor *visitor_print = (Visitor*)malloc(sizeof(Visitor));

     visitor_print->action =  actionprintf;





   /*


ContainerRoot *root2 = createContainerRoot();






ContainerNode *node1 = createContainerNode();
strcpy(node1->name , "node1");

addContainerRootContainerNode(root,node0);

Visitor *visitor = (Visitor*)malloc(sizeof(Visitor));
visitor->action = actionprintf;

root->accept(root,root2,visitor);
*/




 return 0;
}