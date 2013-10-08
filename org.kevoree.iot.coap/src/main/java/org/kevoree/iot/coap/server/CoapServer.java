package org.kevoree.iot.coap.server;

import ch.ethz.inf.vs.californium.endpoint.ServerEndpoint;
import org.kevoree.iot.coap.server.services.MavenResolverResource;


import java.net.SocketException;

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
