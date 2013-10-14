package org.kevoree.iot.coap.client;

import ch.ethz.inf.vs.californium.coap.*;
import ch.ethz.inf.vs.californium.coap.registries.MediaTypeRegistry;
//import ch.ethz.inf.vs.californium.coap.registries.OptionNumberRegistry;
import ch.ethz.inf.vs.californium.endpoint.resources.RemoteResource;
import ch.ethz.inf.vs.californium.endpoint.resources.Resource;
import ch.ethz.inf.vs.californium.util.Log;

import java.io.IOException;
import java.net.URI;
import java.net.URISyntaxException;
import java.net.UnknownHostException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.logging.Level;

/**
 * Created with IntelliJ IDEA.
 * User: jed
 * Date: 08/10/13
 * Time: 11:33
 * To change this template use File | Settings | File Templates.
 */
public class ClientCoap
{
    // resource URI path used for discovery
    private static final String DISCOVERY_RESOURCE = "/.well-known/core";

    // indices of command line parameters
    private static final int IDX_METHOD          = 0;
    private static final int IDX_URI             = 1;
    private static final int IDX_PAYLOAD         = 2;

    // exit codes for runtime errors
    private static final int ERR_MISSING_METHOD  = 1;
    private static final int ERR_UNKNOWN_METHOD  = 2;
    private static final int ERR_MISSING_URI     = 3;
    private static final int ERR_BAD_URI         = 4;
    private static final int ERR_REQUEST_FAILED  = 5;
    private static final int ERR_RESPONSE_FAILED = 6;
    private static final int ERR_BAD_LINK_FORMAT = 7;

    public static void main(String[] args) throws URISyntaxException, IOException
    {
        String method = "GET";
//        URI uri = null;
        URI uri = new URI("coap://[aaaa::c30c:0:0:194]:5683/models?modelname=current.kev");
//        String payload = null;
        boolean loop = false;
//        boolean fileArgs = false;
        Path filePath = Paths.get("/home/user/kevoree-IoT/org.kevoree.iot.firmware/src/main/c/firmware-kevoree/current.kev");
        byte[] fileArray = Files.readAllBytes(filePath);

        // display help if no parameters specified
//        if (args.length == 0)
//        {
//            printInfo();
//            return;
//        }

        Log.setLevel(Level.ALL);
        Log.init();
        //File file_ce;
        // input parameters
//        int idx = 0;
//        for (String arg : args) {
//            if (arg.startsWith("-")) {
//                if (arg.equals("-l")) {
//                    loop = true;
//                }
//                if (arg.equals("-f")) {
//                    fileArgs = true;
//                }
//                else {
//                    System.out.println("Unrecognized option: " + arg);
//                }
//            } else {
//                switch (idx) {
//                    case IDX_METHOD:
//                        method = arg.toUpperCase();
//                        break;
//                    case IDX_URI:
//                        try {
//                            uri = new URI(arg);
//                        } catch (URISyntaxException e) {
//                            System.err.println("Failed to parse URI: " + e.getMessage());
//                            System.exit(ERR_BAD_URI);
//                        }
//                        break;
//                    case IDX_PAYLOAD:
//                        if (fileArgs){
//                            System.out.println(Paths.get(arg.toString()).toString());
//                            filePath = Paths.get(arg.toString());
//                            fileArray = Files.readAllBytes(filePath);
//                            System.out.println("Path to file: " + arg.toString());
//                        }
//                        else
//                            payload = arg;
//                        break;
//                    default:
//                        System.out.println("Unexpected argument: " + arg);
//                }
//                ++idx;
//            }
//        }

        // check if mandatory parameters specified
        if (method == null) {
            System.err.println("Method not specified");
            System.exit(ERR_MISSING_METHOD);
        }
        if (uri == null) {
            System.err.println("URI not specified");
            System.exit(ERR_MISSING_URI);
        }

        // create request according to specified method
        Request request = newRequest(method);
        if (request == null) {
            System.err.println("Unknown method: " + method);
            System.exit(ERR_UNKNOWN_METHOD);
        }

        //if (method.equals("OBSERVE")) {
        //request.setOption(new Option(0, OptionNumberRegistry.OBSERVE));
        //loop = true;
        //}

        // set request URI
        if (method.equals("DISCOVER") && (uri.getPath() == null || uri.getPath().isEmpty() || uri.getPath().equals("/"))) {
            // add discovery resource path to URI
            try {
                uri = new URI(uri.getScheme(), uri.getAuthority(), DISCOVERY_RESOURCE, uri.getQuery());

            } catch (URISyntaxException e) {
                System.err.println("Failed to parse URI: " + e.getMessage());
                System.exit(ERR_BAD_URI);
            }
        }
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
                    System.out.println(response.getPayloadString());
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

    }

    public static void printInfo() {
        System.out.println("uKevoree Client to send and receive models and modules");
        System.out.println();
        System.out.println("Usage: " + ClientCoap.class.getSimpleName() + " [-f] METHOD URI [PAYLOAD] [PATH]");
        System.out.println("  METHOD  : {GET, PUT}");
        System.out.println("  URI     : The CoAP URI of the remote endpoint or resource");
        System.out.println("  PAYLOAD : The data to send with the request");
        System.out.println("  PATH : The path to file if model is a file (.kev)");
        System.out.println("Options:");
        System.out.println("  -l      : Loop for multiple responses");
        System.out.println("           (automatic for OBSERVE and separate responses)");
        System.out.println("  -f      : Send the model as a file");
        System.out.println();
        System.out.println("Examples:");
        System.out.println("  ExampleClient GET coap://aaaa::xxxx/models?modelname=current.kev");
        System.out.println("  ExampleClient PUT coap://aaaa::xxxx/models?modelname=newModel.kev");
    }

    private static Request newRequest(String method) {
        if (method.equals("GET")) {
            return new GETRequest();
        } else if (method.equals("PUT")) {
            return new PUTRequest();
        } else {
            return null;
        }
    }
}
