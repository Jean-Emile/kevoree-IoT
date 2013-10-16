package org.kevoree.iot.emf4c;

import org.apache.velocity.Template;
import org.apache.velocity.VelocityContext;
import org.apache.velocity.app.VelocityEngine;
import org.apache.velocity.runtime.resource.loader.ClasspathResourceLoader;
import org.eclipse.emf.ecore.EAttribute;
import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.EReference;
import org.eclipse.emf.ecore.util.EcoreUtil;
import org.kevoree.iot.emf4c.utils.Helper;

import java.io.IOException;
import java.io.StringWriter;

/**
 * Created with IntelliJ IDEA.
 * User: jed
 * Date: 09/10/13
 * Time: 14:30
 * To change this template_factory use File | Settings | File Templates.
 */
public class DefaultFactoryGenerator {


    private String package_name = "default";
    private VelocityEngine ve = new VelocityEngine();
    private Template template_factory;
    private Template template_helper;
    StringWriter gen_template = new StringWriter();


    public DefaultFactoryGenerator(){
        ve.setProperty("file.resource.loader.class", ClasspathResourceLoader.class.getName()) ;
        ve.init();
        template_factory = ve.getTemplate("templates/factory.vm");
        template_helper = ve.getTemplate("templates/helper.vm");
    }


    public void execute(EClass eClass) throws IOException {
        VelocityContext factory_context = new VelocityContext();

        StringWriter init_attributes = new StringWriter();
        String baseclass =eClass.getName();
        String varname = "ptr";

        for( EAttribute eAttribute : eClass.getEAllAttributes() )
        {
            if(eAttribute.getEAttributeType().getName().equals("EInt")){
                init_attributes.append(varname+"->"+eAttribute.getName()+"=0;\n");
            } else if(!eAttribute.getEAttributeType().getName().equals("EString")){

                init_attributes.append(varname+"->"+eAttribute.getName()+"=NULL;\n");
            }
        }


        for( EReference eReference : eClass.getEAllReferences() ){

            if(eReference.getUpperBound() == -1)
            {
                init_attributes.append(varname+"->count_"+eReference.getName()+"=0;\n");

                VelocityContext helper_context = new VelocityContext();
                String ref_name =     eReference.getName();
                String ref_type = eReference.getEReferenceType().getName();


                helper_context.put("baseclass",baseclass);
                helper_context.put("targetclass",ref_type);
                helper_context.put("var",ref_name);

                template_helper.merge(helper_context, gen_template);

            }
            init_attributes.append(varname+"->"+eReference.getName()+"=NULL;\n");

        }



        factory_context.put("name", baseclass);
        factory_context.put("attributes", init_attributes);
        factory_context.put("varname", varname);


        template_factory.merge(factory_context, gen_template);

       // System.out.println(gen_template);
    }

    public String getFactory() {
        return Helper.genifdefheader("DefaultFactory")+"\n"+
                Helper.genInclude(package_name)+"\n"+
                "#include \"tools.h\"\n" +
                "#include <stdlib.h>\n" +
                gen_template.toString()+"\n"
                +Helper.genifdefbottom();
    }


    public void setPackage_name(String package_name) {
        this.package_name = package_name;
    }
}
