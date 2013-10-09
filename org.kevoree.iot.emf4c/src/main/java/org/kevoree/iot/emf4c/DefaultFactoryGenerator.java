package org.kevoree.iot.emf4c;

import org.eclipse.emf.ecore.EClass;
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
                "return (struct "+name+"*)malloc(sizeof("+name+"));\n" +
                "}\n") ;


        factory.append("void free"+name+"(void){\n" +
                // TODO
                "}\n") ;

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
