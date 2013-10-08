package org.kevoree.iot.coap.client;

import ch.ethz.inf.vs.californium.coap.GETRequest;
import ch.ethz.inf.vs.californium.coap.Request;
import ch.ethz.inf.vs.californium.coap.Response;
import ch.ethz.inf.vs.californium.coap.TokenManager;
import ch.ethz.inf.vs.californium.coap.registries.MediaTypeRegistry;
import ch.ethz.inf.vs.californium.endpoint.resources.RemoteResource;
import ch.ethz.inf.vs.californium.endpoint.resources.Resource;

import java.io.IOException;
import java.net.URI;
import java.net.URISyntaxException;
import java.net.UnknownHostException;

/**
 * Created with IntelliJ IDEA.
 * User: jed
 * Date: 08/10/13
 * Time: 11:33
 * To change this template use File | Settings | File Templates.
 */
public class ClientCoap {


    public static void main(String[] args) throws URISyntaxException {


        String model="";
        // Create the request   get model

        Request request = new GETRequest();

        URI uri = 	uri = new URI("coap://aaaa::1/getmodel");


        request.setURI(uri);

        request.setToken( TokenManager.getInstance().acquireToken() );

        // enable response queue in order to use blocking I/O
        request.enableResponseQueue(true);

        //
        request.prettyPrint();

        // execute request
        try {
            request.execute();

                // receive response

                System.out.println("Receiving response...");
                Response response = null;
                try {
                    response = request.receiveResponse();
                } catch (InterruptedException e) {
                    System.err.println("Failed to receive response: " + e.getMessage());

                }

                // output response

                if (response != null) {

                    response.prettyPrint();
                    System.out.println("Time elapsed (ms): " + response.getRTT());

                    // check of response contains resources
                    if (response.getContentType()== MediaTypeRegistry.APPLICATION_LINK_FORMAT) {

                        String linkFormat = response.getPayloadString();

                        // create resource three from link format
                        Resource root = RemoteResource.newRoot(linkFormat);
                        if (root != null) {

                            // output discovered resources
                            System.out.println("\nDiscovered resources:");
                            root.prettyPrint();

                        } else {
                            System.err.println("Failed to parse link format");

                        }
                    } else {


                    }

                } else {

                    // no response received
                    System.err.println("Request timed out");

                }



        } catch (UnknownHostException e) {
            System.err.println("Unknown host: " + e.getMessage());

        } catch (IOException e) {
            System.err.println("Failed to execute request: " + e.getMessage());

        }





        System.out.println(model);


    }
}
