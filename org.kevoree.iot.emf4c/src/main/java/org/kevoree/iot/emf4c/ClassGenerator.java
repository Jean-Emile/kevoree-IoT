package org.kevoree.iot.emf4c;

import org.eclipse.emf.ecore.EAttribute;
import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.EReference;
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
    StringBuilder methods = new StringBuilder();
    public ClassGenerator(String target_path){
        this.target_path = target_path;
    }

    public void execute(EClass eClass) throws IOException {
        StringBuilder body = new StringBuilder();
        StringBuilder header = new StringBuilder();

        StringBuilder result = new StringBuilder();

        header.append(" #include <stdlib.h>\n" +
                " #include <stdio.h>\n");

        String structname =  eClass.getName();
        body.append("typedef struct _" + structname + " { \n");



        for( EAttribute eAttribute : eClass.getEAllAttributes() ){
            body.append("\t" + DataTypes.getInstance().dataTypes.get(eAttribute.getEAttributeType().getName()) + " " + eAttribute.getName() + ";\n");
        }

        for( EReference eReference : eClass.getEAllReferences() ){

            String name =     eReference.getName();
            String type = eReference.getEReferenceType().getName();

            header.append(Helper.genInclude(eReference.getEReferenceType().getName()));



            // pointer on struct
            if(eReference.getUpperBound() == -1){
                body.append("\tint count_" + name + ";\n");
                body.append("\tstruct " + eReference.getEReferenceType().getName() + " **" + eReference.getName() + ";\n");
                methods.append("void add"+name+""+structname+"("+structname+"*root,struct "+type+" *val){\n" +
                        "if(root == NULL) { printf(\"ERROR\"); }"+
                        "if(val == NULL) { printf(\"ERROR\"); }"+
                        "if(root->"+name+"== NULL){\n"+
                        "root->count_"+name +"=0;\n" +
                        "root->"+name+" = malloc(sizeof("+type+"*));\n" +
                        "root->"+name+"[0] =val;\n"+
                        "root->count_"+name +"++;\n" +
                        "} else {\n"+
                        "root->"+name+" = realloc(root->"+name+",(root->count_"+name+"+1)*sizeof("+type+"*));\n" +
                        "root->"+name+"[root->count_"+name+"] =val;\n "+
                        "root->count_"+name +"++;\n" +
                        "}}\n");
            }else {
                body.append("\tstruct " + eReference.getEReferenceType().getName() + " *" + eReference.getName() + ";\n");
            }

        }


        body.append("} " + eClass.getName() + " ;\n");


        result.append(Helper.genifdefheader(eClass.getName())+"\n");
        result.append(header+"\n");
        result.append(body+"\n");
        // result.append(methods+"\n");

        result.append(Helper.genifdefbottom());


        FileManager.writeFile(target_path+eClass.getName()+".h",result.toString(),false);
    }


    public StringBuilder getMethods() {
        return methods;
    }
}
