package org.kevoree.iot.emf4c;

import org.eclipse.emf.ecore.EAttribute;
import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.EReference;
import org.kevoree.iot.emf4c.utils.DataTypes;
import org.kevoree.iot.emf4c.utils.FileManager;
import org.kevoree.iot.emf4c.utils.Helper;

import java.io.IOException;

/**
 * Created with IntelliJ IDEA.
 * User: jed
 * Date: 09/10/13
 * Time: 10:36
 * To change this template use File | Settings | File Templates.
 */
public class ClassGenerator  {

    private String target_path="";

    public ClassGenerator(String target_path){
        this.target_path = target_path;
    }

    public void execute(EClass eClass) throws IOException {
        StringBuilder body = new StringBuilder();
        StringBuilder header = new StringBuilder();

        StringBuilder result = new StringBuilder();

        header.append("#include <stdlib.h>\n" +
                      "#include <stdio.h>\n"+
                      "#include \"tools.h\"\n"+
                      "#include <string.h>\n");

        String structname =  eClass.getName();
        body.append("typedef struct _" + structname + " { \n");


        for( EAttribute eAttribute : eClass.getEAllAttributes() )
        {
            if(eAttribute.getEAttributeType().getName().equals("EString")){
                int size = 8;
                if(eAttribute.getDefaultValueLiteral() != null){
                    size = Integer.parseInt(eAttribute.getDefaultValueLiteral());
                }
                body.append("\t" +"char " + eAttribute.getName() + "["+size+"];\n");

            }      else {
                body.append("\t" + DataTypes.getInstance().dataTypes.get(eAttribute.getEAttributeType().getName()) + " " + eAttribute.getName() + ";\n");
            }
        }

        for( EReference eReference : eClass.getEAllReferences() )
        {

            String name = eReference.getName();
            String type = eReference.getEReferenceType().getName();

            header.append(Helper.genInclude(eReference.getEReferenceType().getName()));

            // pointer on a struct
            if(eReference.getUpperBound() == -1)
            {
                body.append("\tint count_" + name + ";\n");
                body.append("\tstruct " + eReference.getEReferenceType().getName() + " **" + eReference.getName() + ";\n");

            }else {
                body.append("\tstruct " + eReference.getEReferenceType().getName() + " *" + eReference.getName() + ";\n");
            }

        }
        body.append("\tint (*accept)(struct _"+structname+"*,struct _"+structname+"*, Visitor*);\n");


        body.append("} " + eClass.getName() + " ;\n");


        result.append(Helper.genifdefheader(eClass.getName())+"\n");
        result.append(header+"\n");
        result.append(body+"\n");
        // result.append(methods+"\n");


        result.append("int _accept"+structname+"("+structname+"* this,"+structname+"* c,Visitor* visitor) {\n");
        result.append("int i;\n");
        for( EAttribute eAttribute : eClass.getEAllAttributes() )
        {

            result.append("visitor->action((void*)this->"+eAttribute.getName()+",(void*)c->"+eAttribute.getName()+",0);\n");

        }

        for( EReference eReference : eClass.getEAllReferences() )
        {
            String name = eReference.getName();
            if(eReference.getUpperBound() == -1)
            {

                result.append("for(i=0;i<this->count_"+name+";i++){\n");
                result.append("visitor->action((void*)this->"+name+",(void*)c->"+name+",0);\n");
                result.append("}\n");
            }else {
                result.append("visitor->action((void*)this->"+name+",(void*)c->"+name+",0);\n");
            }

        }



            result.append("}\n");

        result.append(Helper.genifdefbottom());





        FileManager.writeFile(target_path+eClass.getName()+".h",result.toString(),false);
    }



}
