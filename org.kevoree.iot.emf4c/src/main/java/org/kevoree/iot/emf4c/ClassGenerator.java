package org.kevoree.iot.emf4c;

import org.apache.velocity.Template;
import org.apache.velocity.VelocityContext;
import org.apache.velocity.app.VelocityEngine;
import org.apache.velocity.runtime.resource.loader.ClasspathResourceLoader;
import org.eclipse.emf.ecore.EAttribute;
import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.EReference;
import org.kevoree.iot.emf4c.utils.DataTypes;
import org.kevoree.iot.emf4c.utils.FileManager;
import org.kevoree.iot.emf4c.utils.Helper;

import java.io.IOException;
import java.io.StringWriter;
import java.io.UnsupportedEncodingException;

/**
 * Created with IntelliJ IDEA.
 * User: jed
 * Date: 09/10/13
 * Time: 10:36
 * To change this template use File | Settings | File Templates.
 */
public class ClassGenerator  {

    private String target_path="";
    private VelocityEngine ve = new VelocityEngine();

    private Template template_factory;

    public ClassGenerator(String target_path){
        this.target_path = target_path;
        ve.setProperty("file.resource.loader.class", ClasspathResourceLoader.class.getName()) ;
        ve.init();
        template_factory = ve.getTemplate("templates/visitor.vm");
    }

    public static Integer hash(String value) throws UnsupportedEncodingException
    {
        byte[] data = value.getBytes("US-ASCII");
        long checksum = 0L;
        for( byte b : data )  {
            checksum += b;
        }
        checksum = checksum % 256;
        return new Long( checksum ).intValue();
    }

    public void execute(EClass eClass) throws IOException {

        StringBuilder body = new StringBuilder();
        StringBuilder header = new StringBuilder();

        StringBuilder result = new StringBuilder();

        header.append("#include <stdlib.h>\n" +
                      "#include <stdio.h>\n"+
                      "#include \"tools.h\"\n"+
                      "#include \"HashMap.h\"\n"+
                      "#include <string.h>\n");


        body.append("#define ID_TYPE_"+eClass.getName()+" "+hash(eClass.getName())+" \n");
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
                body.append("\tmap_t " + eReference.getName() + "; // "+eReference.getEReferenceType().getName()+"\n");
            }else {
                body.append("\tstruct " + eReference.getEReferenceType().getName() + " *" + eReference.getName() + ";\n");
            }

        }
        body.append("\tint (*accept)(struct _"+structname+"*,char *parent,Visitor*);\n");


        body.append("} " + eClass.getName() + " ;\n");


        result.append(Helper.genifdefheader(eClass.getName())+"\n");
        result.append(header+"\n");
        result.append(body+"\n");
        // result.append(methods+"\n");


        String var_s="this";

        result.append("int _accept"+structname+"("+structname+"* "+var_s+",char *parent,Visitor* visitor) {\n");
        result.append("int i=0; char path[128];\n");
        for( EAttribute eAttribute : eClass.getEAllAttributes() )
        {


            if(eAttribute.getEAttributeType().getName().equals("EString")){

                result.append("sprintf(path,\"%s/"+eAttribute.getName()+"\",parent);\n");


                result.append("visitor->action((void*)"+var_s+"->"+eAttribute.getName()+",path,ID_TYPE_CHAR);\n");
            }
            if(eAttribute.getEAttributeType().getName().equals("EInt")){
                result.append("sprintf(path,\"%s/"+eAttribute.getName()+"\",parent);\n");
                result.append("visitor->action((void*)"+var_s+"->"+eAttribute.getName()+",path,ID_TYPE_INT);\n");
            }


        }



        result.append("hashmap_map* m_s;\n");


        for( EReference eReference : eClass.getEAllReferences() )
        {
            String name = eReference.getName();
            String type = eReference.getEReferenceType().getName();


            if(eReference.getUpperBound() == -1)
            {
                 StringWriter gen_template = new StringWriter();
                VelocityContext helper_context = new VelocityContext();
                helper_context.put("var_s",var_s);
                helper_context.put("var_name",name);
                helper_context.put("var_type",type);
                helper_context.put("structname",structname);
                template_factory.merge(helper_context, gen_template);

                result.append(gen_template);


            }



        }

        result.append("}\n");
        result.append(Helper.genifdefbottom());




        FileManager.writeFile(target_path+eClass.getName()+".h",result.toString(),false);

    }



}
