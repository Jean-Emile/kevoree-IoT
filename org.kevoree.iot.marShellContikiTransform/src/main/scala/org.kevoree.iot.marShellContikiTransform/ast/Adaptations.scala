package org.kevoree.iot.modelTransform.ast

/**
 * Created by jed
 * User: jedartois@gmail.com
 * Date: 28/03/12
 * Time: 16:40
 */

case class Adaptations(nodeName : String, nodeTypeName : String, definitions : Option[GlobalDefintions],adaptations : java.util.List[Adaptation],checksum : Long) {

}


