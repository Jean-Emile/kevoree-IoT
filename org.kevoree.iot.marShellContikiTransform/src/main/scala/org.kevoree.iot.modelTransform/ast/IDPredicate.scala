package org.kevoree.iot.modelTransform.ast

/**
 * Created by jed
 * User: jedartois@gmail.com
 * Date: 28/03/12
 * Time: 12:05
 */


case class IDPredicate(op : Int,instanceID :String) {

  def getOp: Int= {
      return op
    }

  def getinstanceID: String= {
      return instanceID
    }

  override def toString: String = {
    return " id=" + op + " T=" + instanceID
  }
}