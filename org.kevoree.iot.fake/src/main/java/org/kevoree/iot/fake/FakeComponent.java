package org.kevoree.iot.fake;

import org.kevoree.ContainerRoot;
import org.kevoree.annotation.ComponentType;
import org.kevoree.annotation.Start;
import org.kevoree.annotation.Stop;
import org.kevoree.annotation.Update;
import org.kevoree.api.PrimitiveCommand;
import org.kevoree.framework.AbstractComponentType;
import org.kevoree.framework.AbstractNodeType;
import org.kevoreeadaptation.AdaptationModel;
import org.kevoreeadaptation.AdaptationPrimitive;

import java.io.IOException;

/**
 * Created with IntelliJ IDEA.
 * User: jed
 * Date: 08/10/13
 * Time: 14:48
 * To change this template use File | Settings | File Templates.
 */


@org.kevoree.annotation.Library(name = "Contiki")
@ComponentType
@org.kevoree.annotation.DictionaryType({
        @org.kevoree.annotation.DictionaryAttribute(name = "type", defaultValue = "z1", optional = false, vals = {"z1"}),
        @org.kevoree.annotation.DictionaryAttribute(name = "borderrouter", defaultValue = "aaaa::1", optional = false)
})
public class FakeComponent extends AbstractComponentType {


    @Start
    public void start(){

    }

    @Stop
    public void stop(){

    }

    @Update
    public void update(){

    }

}
