package org.kevoree.iot.modelTransform.ast

/**
 * Created by jed
 * User: jedartois@gmail.com
 * Date: 29/03/12
 * Time: 16:53
 */

case class GlobalDefintions(properties : java.util.List[String],typedefinition : java.util.List[String],portdefinition : java.util.List[String]) extends  Adaptation{

  def getPropertieById(id : Int) : String = {
    try {
      properties.get(id)
    }catch {
      case _ @ e => " "
    }

  }

  def getTypedefinitionById(id : Int): String = {
    try {
      typedefinition.get(id)
    }catch {
      case _ @ e => " "
    }
  }

  def getPortdefinitionById(id : Int) : String = {
    try {
      portdefinition.get(id)
    }catch {
      case _ @ e => " "
    }
  }

}