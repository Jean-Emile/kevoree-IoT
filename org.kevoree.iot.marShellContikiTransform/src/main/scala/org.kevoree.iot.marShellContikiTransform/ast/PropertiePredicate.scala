package org.kevoree.iot.modelTransform.ast

/**
 * Created by jed
 * User: jedartois@gmail.com
 * Date: 28/03/12
 * Time: 13:07
 */

case class PropertiePredicate(dictionnaryID : Int,value :String) extends  Propertie {
  override  def getdictionnaryID() : Int =  {
      dictionnaryID
    }
}

