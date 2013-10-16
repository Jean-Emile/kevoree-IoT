package org.kevoree.iot.emf4c;

import org.apache.velocity.Template;
import org.apache.velocity.VelocityContext;
import org.apache.velocity.app.VelocityEngine;
import org.apache.velocity.runtime.resource.loader.ClasspathResourceLoader;
import org.eclipse.emf.ecore.EAttribute;
import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.EReference;

import java.io.IOException;
import java.io.StringWriter;

/**
 * Created with IntelliJ IDEA.
 * User: jed
 * Date: 15/10/13
 * Time: 14:11
 * To change this template use File | Settings | File Templates.
 */
public class CompareGenerator {

    private VelocityEngine ve = new VelocityEngine();
    private Template template;
    private Template template_header;
    private StringWriter gen_body = new StringWriter();
    private StringWriter gen_header = new StringWriter();

    private final String var_s = "s";
    private final String var_t = "t";

    public CompareGenerator(){
        ve.setProperty("file.resource.loader.class", ClasspathResourceLoader.class.getName()) ;
        ve.init();
        template= ve.getTemplate("templates/comparestruct.vm");
        template_header= ve.getTemplate("templates/comparestructheader.vm");
    }

    public void execute(EClass eClass) throws IOException {

        VelocityContext context = new VelocityContext();
        StringWriter gen_attributes = new StringWriter();
        StringWriter gen_struct = new StringWriter();

        gen_attributes.write("int i,j;\n");
        for( EAttribute eAttribute : eClass.getEAllAttributes())
        {


            if(eAttribute.getEType().getName().equals("EString")){
                gen_attributes.write("if(strcmp("+var_s+"->"+eAttribute.getName()+","+var_t+"->"+eAttribute.getName()+")){\n");

                gen_attributes.write("printf(\"TRACE "+eAttribute.getName()+" %s \","+var_t+"->"+eAttribute.getName()+");");
                gen_attributes.write("}\n");
            }

            if(eAttribute.getEType().getName().equals("EInt")){
                gen_attributes.write("if("+var_s+"->"+eAttribute.getName()+" != "+var_t+"->"+eAttribute.getName()+"){\n");


                gen_attributes.write("}\n");
            }




        }

        for( EReference eReference : eClass.getEAllReferences() )
        {
            String ref_name =     eReference.getName();
            String ref_type = eReference.getEReferenceType().getName();
            if(eReference.getUpperBound() == -1)
            {


                gen_struct.write("for(i=0;i<"+var_s+"->count_"+ref_name+";i++){\n");
                gen_struct.write("for(j=0;j<"+var_t+"->count_"+ref_name+";j++){\n");

                gen_struct.write("compare"+ref_type+"("+var_s+"->"+ref_name+"[i],"+var_t+"->"+ref_name+"[j]);\n");
                gen_struct.write("}");
                gen_struct.write("}\n");

            } else {
                gen_struct.write("compare"+ref_type+"("+var_s+"->"+ref_name+","+var_t+"->"+ref_name+");\n");
            }

        }



        context.put("name",eClass.getName());

        context.put("var_s",var_s);
        context.put("var_t",var_t);


        context.put("compare_attributes",gen_attributes);
        context.put("compare_struct",gen_struct);

        template_header.merge(context, gen_header);
        template.merge(context, gen_body);


    }


    public StringWriter getbody() {
        return gen_body;
    }

    public StringWriter getheader() {
        return gen_header;
    }
}
