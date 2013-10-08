package org.kevoree.iot.coapserver;

import ch.ethz.inf.vs.californium.coap.GETRequest;
import ch.ethz.inf.vs.californium.coap.registries.CodeRegistry;
import ch.ethz.inf.vs.californium.coap.registries.MediaTypeRegistry;
import ch.ethz.inf.vs.californium.endpoint.ServerEndpoint;
import ch.ethz.inf.vs.californium.endpoint.resources.LocalResource;
import org.kevoree.iot.coapserver.coap_ressources.MavenResolverResource;


import java.net.SocketException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * Created with IntelliJ IDEA.
 * User: jed
 * Date: 04/10/13
 * Time: 11:01
 * To change this template use File | Settings | File Templates.
 */
public class CoapServer  extends ServerEndpoint {

    public CoapServer(int port,int transferBlockSize) throws SocketException {
        super(port,transferBlockSize);
        addResource(new MavenResolverResource());


    }



    /*
     * Application entry point.

    public static void main(String[] args) {


    }
    */

}
