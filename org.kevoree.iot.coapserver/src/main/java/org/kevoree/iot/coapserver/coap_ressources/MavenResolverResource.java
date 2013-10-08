package org.kevoree.iot.coapserver.coap_ressources;

import ch.ethz.inf.vs.californium.coap.BlockOption;
import ch.ethz.inf.vs.californium.coap.GETRequest;
import ch.ethz.inf.vs.californium.coap.registries.CodeRegistry;
import ch.ethz.inf.vs.californium.coap.registries.MediaTypeRegistry;
import ch.ethz.inf.vs.californium.endpoint.resources.LocalResource;
import org.kevoree.resolver.MavenResolver;

import java.io.File;
import java.util.ArrayList;
import java.util.List;


/**
 * Created with IntelliJ IDEA.
 * User: jed
 * Date: 04/10/13
 * Time: 11:10
 * To change this template use File | Settings | File Templates.
 */
public class MavenResolverResource extends LocalResource {

    private  MavenResolver resolver=null;

    public MavenResolverResource() {
        // set resource identifier
        super("/mavenresolver");
        resolver  = new MavenResolver();
        // set display name
        setTitle("Manven-Resolver ELF");

    }


    @Override
    public void performGET(GETRequest request) {

        try {

            List<String>  repos = new ArrayList<String>();


                  // TODO
            String group =	"";
            String name =	"";
            String version =    "";


            File  file = resolver.resolve(group, name, version, "ce", repos);



            if(file ==null){
                          System.out.println("NOT FOUND");
            }                                             else {
                System.out.println("FOUND");
            }

            System.out.println("group =" + group+" name "+name+" "+version);




            request.respond(CodeRegistry.RESP_CONTENT,file.getPath(), MediaTypeRegistry.APPLICATION_OCTET_STREAM);
        } catch (Exception e) {
            request.respond(CodeRegistry.RESP_BAD_REQUEST, "NULL", MediaTypeRegistry.TEXT_PLAIN);
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }

    }


}
