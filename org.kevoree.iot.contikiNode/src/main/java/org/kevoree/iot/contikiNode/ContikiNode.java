package org.kevoree.iot.contikiNode;

import org.kevoree.ContainerRoot;
import org.kevoree.api.PrimitiveCommand;
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

@org.kevoree.annotation.NodeType
@org.kevoree.annotation.Library(name = "Contiki")
@org.kevoree.annotation.DictionaryType({
        @org.kevoree.annotation.DictionaryAttribute(name = "type", defaultValue = "z1", optional = false, vals = {"z1"}),
        @org.kevoree.annotation.DictionaryAttribute(name = "border-router", defaultValue = "aaaa::1", optional = false)
})
@org.kevoree.annotation.PrimitiveCommands(values = {"StartThirdParty", "UpdateType", "UpdateDeployUnit", "AddType", "AddDeployUnit", "AddThirdParty", "RemoveType", "RemoveDeployUnit", "UpdateInstance", "UpdateBinding", "UpdateDictionaryInstance", "AddInstance", "RemoveInstance", "AddBinding", "RemoveBinding", "AddFragmentBinding", "RemoveFragmentBinding", "StartInstance", "StopInstance", "StartThirdParty"}, value = {})

public class ContikiNode extends AbstractNodeType {
    @Override
    public AdaptationModel kompare(ContainerRoot containerRoot, ContainerRoot containerRoot2) {
        return null;
    }

    @Override
    public PrimitiveCommand getPrimitive(AdaptationPrimitive adaptationPrimitive) {
        return null;
    }


    public  void push(final String targetNodeName, final ContainerRoot root, String boardPortName) throws IOException {


    }
}
