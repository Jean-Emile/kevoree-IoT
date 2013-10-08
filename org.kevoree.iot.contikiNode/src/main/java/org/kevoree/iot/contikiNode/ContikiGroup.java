package org.kevoree.iot.contikiNode;

import org.kevoree.ContainerRoot;
import org.kevoree.annotation.GroupType;
import org.kevoree.annotation.Library;
import org.kevoree.framework.AbstractGroupType;

/**
 * Created with IntelliJ IDEA.
 * User: jed
 * Date: 08/10/13
 * Time: 14:56
 * To change this template use File | Settings | File Templates.
 */
@Library(name = "Contiki")
@GroupType
public class ContikiGroup extends AbstractGroupType {

    @Override
    public void triggerModelUpdate() {

    }

    @Override
    public void push(ContainerRoot containerRoot, String s) throws Exception {

    }

    @Override
    public ContainerRoot pull(String s) throws Exception {
        return null;
    }
}
