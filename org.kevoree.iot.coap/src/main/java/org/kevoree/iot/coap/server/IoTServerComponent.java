package org.kevoree.iot.coap.server;

import org.kevoree.annotation.*;
import org.kevoree.framework.AbstractComponentType;

import java.net.SocketException;

/**
 * Created with IntelliJ IDEA.
 * User: jed
 * Date: 08/10/13
 * Time: 10:06
 * To change this template use File | Settings | File Templates.
 */
@Library(name = "IoT")
@DictionaryType({
        @DictionaryAttribute(name = "port", defaultValue = "8080", optional = false)
})
@ComponentType
public class IoTServerComponent extends AbstractComponentType {

   private CoapServer server =null;
   private  int port=0;
   private final  int transferBlockSize = 64;
    @Start
    public void start() {
        try {

           port =    Integer.parseInt(getDictionary().get("port").toString());
            // create server
             server = new CoapServer(port,transferBlockSize);

            server.start();

            System.out.println("Server listening on port " + server.getPort());

        } catch (SocketException e) {

            System.err.println("Failed to initialize server: " + e.getMessage());
        }
    }


    @Stop
    public void stop() {

        if(server != null){
                // todo

        }

    }

    @Update
    public void update() {


    }
}
