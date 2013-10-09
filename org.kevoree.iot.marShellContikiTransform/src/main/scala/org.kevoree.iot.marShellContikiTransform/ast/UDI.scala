package org.kevoree.iot.modelTransform.ast

/**
 * Created by jed
 * User: jedartois@gmail.com
 * Date: 28/03/12
 * Time: 16:40
 */



case class UDI(id : IDPredicate, params : Option[List[Propertie]])  extends  Adaptation
{
  def getIDPredicate() :  IDPredicate = {
    return  id
  }

  def getParams: java.util.List[Propertie] = {
    val jl = new java.util.ArrayList [Propertie] (params.size)
    params.get.foreach (jl.add(_))
    return jl
  }
}
