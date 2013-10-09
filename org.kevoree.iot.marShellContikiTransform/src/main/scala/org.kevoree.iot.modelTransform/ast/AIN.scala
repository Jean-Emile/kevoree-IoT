package org.kevoree.iot.modelTransform.ast


/**
 * Created by jed
 * User: jedartois@gmail.com
 * Date: 28/03/12
 * Time: 17:36
 */

case class AIN(id : IDPredicate, typeIDB : Int,params : Option[List[Propertie]]) extends  Adaptation {

  def getIDPredicate() :  IDPredicate = {
      id
   }

  def getTypeIDB() : Int = {
    typeIDB
  }

  def getParams: java.util.List[Propertie] = {
    val jl = new java.util.ArrayList [Propertie] (params.size)
    params.get.foreach (jl.add(_))
    return jl
  }


}