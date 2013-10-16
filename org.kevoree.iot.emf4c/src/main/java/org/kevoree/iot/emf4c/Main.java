package org.kevoree.iot.emf4c;

import java.io.File;
import java.util.Iterator;

/**
 * Created with IntelliJ IDEA.
 * User: jed
 * Date: 09/10/13
 * Time: 10:34
 * To change this template use File | Settings | File Templates.
 */

import org.eclipse.emf.common.util.URI;
import org.eclipse.emf.ecore.EClass;
import org.eclipse.emf.ecore.EObject;
import org.eclipse.emf.ecore.EPackage;
import org.eclipse.emf.ecore.resource.Resource;
import org.eclipse.emf.ecore.resource.impl.ResourceSetImpl;
import org.eclipse.emf.ecore.util.EcoreUtil;
import org.eclipse.emf.ecore.xmi.XMIResource;
import org.eclipse.emf.ecore.xmi.impl.EcoreResourceFactoryImpl;
import org.kevoree.iot.emf4c.c.ClassGenerator;
import org.kevoree.iot.emf4c.c.DefaultFactoryGenerator;
import org.kevoree.iot.emf4c.utils.FileManager;
import org.kevoree.iot.emf4c.utils.Helper;


public class Main {


    public static void main(String[] args) throws Exception {

        String targetpath = "/home/jed/KEVOREE_PROJECT/kevoree-IoT/org.kevoree.iot.firmware/src/main/c/firmware-kevoree/model/";

        File ecoreFile = new File("/home/jed/KEVOREE_PROJECT/kevoree-IoT/org.kevoree.iot.emf4c/src/resources/kevoree.ecore");

        URI fileUri =  URI.createFileURI(ecoreFile.getAbsolutePath());


        Resource.Factory.Registry.INSTANCE.getExtensionToFactoryMap().put("ecore", new EcoreResourceFactoryImpl());
        ResourceSetImpl rs = new ResourceSetImpl();

        XMIResource resource = (XMIResource) rs.createResource(fileUri);


        resource.load(null) ;
        EcoreUtil.resolveAll(resource);

        String package_name ="default";
        StringBuilder   list_file_h = new StringBuilder();
        DefaultFactoryGenerator factory = new DefaultFactoryGenerator();
        ClassGenerator classGenerator =new ClassGenerator(targetpath);

        for (Iterator i = resource.getAllContents(); i.hasNext();) {
            EObject eo = (EObject)i.next();

            if(eo instanceof EClass){
                classGenerator.execute((EClass) eo);
                list_file_h.append(Helper.genInclude(((EClass) eo).getName()));
                factory.execute((EClass) eo);
            }  else if(eo instanceof EPackage){
                package_name =     ((EPackage) eo).getNsPrefix();
                factory.setPackage_name(package_name);
            }

        }
        String utils ="size_t getsize(void * p) {\n" +
                "    size_t * in = p;\n" +
                "    if (in) { --in; return *in; }\n" +
                "    return -1;\n" +
                "}\n" +
                "\n" +
                "void *realloc(void *ptr,size_t size) {\n" +
                "    void *newptr;\n" +
                "    int msize;\n" +
                "    msize=getsize(ptr);\n" +
                "    if (size <= msize) return ptr;\n" +
                "    newptr=malloc(size);\n" +
                "    memcpy(newptr,ptr,msize);\n" +
                "    free(ptr);\n" +
                "    return newptr;\n" +
                "}";
      // create
        FileManager.writeFile(targetpath+package_name+".h",list_file_h.toString(),false);
        FileManager.writeFile(targetpath+"Helper"+package_name+".h",utils+"\n"+classGenerator.getMethods().toString(),false);
        FileManager.writeFile(targetpath+"DefaultFactory"+package_name+".h",factory.getFactory().toString(),false);



    }
}
