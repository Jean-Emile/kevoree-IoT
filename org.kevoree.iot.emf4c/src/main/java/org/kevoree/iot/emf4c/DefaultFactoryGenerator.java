package org.kevoree.iot.emf4c;

import org.eclipse.emf.ecore.EAttribute;
import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.EReference;
import org.kevoree.iot.emf4c.utils.Helper;

import java.io.IOException;

/**
 * Created with IntelliJ IDEA.
 * User: jed
 * Date: 09/10/13
 * Time: 14:30
 * To change this template use File | Settings | File Templates.
 */
public class DefaultFactoryGenerator {
    private  StringBuilder factory = new StringBuilder();
    private String package_name = "default";



    public void execute(EClass eClass) throws IOException {
        //ContainerRoot *root = (ContainerRoot*)malloc(sizeof(ContainerRoot));

        String name =eClass.getName();

        factory.append("struct "+name+" * create"+name+"(void){\n" +
                name+" *ptr = (struct "+name+"*)malloc(sizeof("+name+"));\n");
        factory.append("if(ptr == NULL){\n printf(\"Error malloc "+name+"\"); \n }else {\n");

        for(EAttribute at :  eClass.getEAllAttributes())
        {
            if(at.getEAttributeType().getName().equals("EString")){
                factory.append("ptr->"+at.getName()+"=NULL;\n");
            }
        }


        for( EReference eReference : eClass.getEAllReferences() ){
            if(eReference.getUpperBound() == -1){
                factory.append("ptr->count_"+eReference.getName()+"=0;\n");
            }
        }
        factory.append("}\n");

        factory.append("return ptr;\n") ;
        factory.append("}\n") ;


        factory.append("void free"+name+"("+name+" * ptr){\n");
      //  factory.append("int i;\n");

        for(EAttribute at :  eClass.getEAllAttributes())
        {

            if(DataTypes.getInstance().freeTypes.contains(at.getEAttributeType().getName())){
                factory.append("free(ptr->"+at.getName()+");\n\n");
            }
        }

        for( EReference eReference : eClass.getEAllReferences() ){
            // TODO
          //  factory.append("for(i=0;i<ptr->count_"+eReference.getName()+";i++){\n");
            factory.append("free(ptr->"+eReference.getName()+");\n");
            //factory.append("}\n");
        }
        factory.append("}\n");




    }

    public String getFactory() {
        return Helper.genifdefheader("DefaultFactory")+"\n"+
                Helper.genInclude(package_name)+"\n"+
                "#include <stdlib.h>\n" +
                factory.toString()+"\n"
                +Helper.genifdefbottom();
    }


    public void setPackage_name(String package_name) {
        this.package_name = package_name;
    }
}
