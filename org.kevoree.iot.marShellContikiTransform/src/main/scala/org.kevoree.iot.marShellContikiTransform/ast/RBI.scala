package org.kevoree.iot.modelTransform.ast

/**
 * Created by jed
 * User: jedartois@gmail.com
 * Date: 28/03/12
 * Time: 17:41
 */

class RBI(id : IDPredicate, chID :String, portIDB : Int) extends Adaptation {
  def getIDPredicate() :  IDPredicate = {
     id
  }

  def getchID() : String ={
    chID
  }
  def getportIDB: Int = {
    portIDB
  }
}
