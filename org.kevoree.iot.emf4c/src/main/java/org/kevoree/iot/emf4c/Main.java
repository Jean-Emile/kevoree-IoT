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
import org.eclipse.emf.ecore.EcoreFactory;
import org.eclipse.emf.ecore.impl.EClassImpl;
import org.eclipse.emf.ecore.resource.Resource;
import org.eclipse.emf.ecore.resource.impl.ResourceSetImpl;
import org.eclipse.emf.ecore.util.EcoreUtil;
import org.eclipse.emf.ecore.xmi.XMIResource;
import org.eclipse.emf.ecore.xmi.impl.EcoreResourceFactoryImpl;
import org.kevoree.iot.emf4c.utils.FileManager;
import org.kevoree.iot.emf4c.utils.Helper;


public class Main {



    public static void main(String[] args) throws Exception {

        String targetpath = "/home/jed/KEVOREE_PROJECT/kevoree-IoT/org.kevoree.iot.firmware/src/main/c/firmware-kevoree/model/";
        File ecoreFile = new File("/home/jed/KEVOREE_PROJECT/kevoree-IoT/org.kevoree.iot.emf4c/src/main/resources/kevoree.ecore");

        URI fileUri =  URI.createFileURI(ecoreFile.getAbsolutePath());


        Resource.Factory.Registry.INSTANCE.getExtensionToFactoryMap().put("ecore", new EcoreResourceFactoryImpl());
        ResourceSetImpl rs = new ResourceSetImpl();

        XMIResource resource = (XMIResource) rs.createResource(fileUri);


        resource.load(null) ;
        EcoreUtil.resolveAll(resource);

        resource.load(null) ;
        EcoreUtil.resolveAll(resource);

        String package_name ="default";
        StringBuilder   list_file_h = new StringBuilder();


        DefaultFactoryGenerator factory = new DefaultFactoryGenerator();
        CompareGenerator  compareGenerator = new CompareGenerator();
        ClassGenerator classGenerator =new ClassGenerator(targetpath);


        for (Iterator i = resource.getAllContents(); i.hasNext();) {
            EObject eo = (EObject)i.next();


            if(eo instanceof EClass){
                classGenerator.execute((EClass) eo);
                list_file_h.append(Helper.genInclude(((EClass) eo).getName()));

                factory.execute((EClass) eo);
                compareGenerator.execute((EClass) eo);


            }  else if(eo instanceof EPackage){
                package_name =     ((EPackage) eo).getNsPrefix();
                factory.setPackage_name(package_name);

                System.out.println(((EClassImpl)EcoreUtil.getRootContainer(eo).eContents().get(0)).getName());

            }

        }

        // create
        FileManager.writeFile(targetpath+"Compare"+package_name+".h",compareGenerator.getheader()+"\n"+compareGenerator.getbody().toString(),false);

        FileManager.writeFile(targetpath+package_name+".h",list_file_h.toString(),false);
        FileManager.copyFileFromStream(DefaultFactoryGenerator.class.getClassLoader().getResourceAsStream("templates/tools.h"),targetpath,"tools.h",true);
        FileManager.writeFile(targetpath+"DefaultFactory"+package_name+".h",factory.getFactory().toString(),false);



    }
}
