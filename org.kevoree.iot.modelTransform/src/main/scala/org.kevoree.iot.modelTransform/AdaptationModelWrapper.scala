package org.kevoree.iot.modelTransform


import org.kevoreeadaptation._
import org.kevoree.kompare.JavaSePrimitive
import org.kevoree._
import scala.collection.JavaConversions._
import org.kevoree.log.Log
import org.kevoree.tools.marShell.ast._
import org.kevoree.tools.marShell.ast.MergeStatement
import org.kevoree.tools.marShell.ast.UpdateDictionaryStatement
import org.kevoree.tools.marShell.ast.Script
import scala.Some

object AdaptationModelWrapper {

  def generateScriptFromAdaptModel(model: AdaptationModel): Script = {
    var statments = List[Statment]()

    model.getAdaptations.foreach {
      adapt =>
        adapt.getPrimitiveType.getName match {
          case s if s == JavaSePrimitive.instance$.getAddDeployUnit => {
            val du = adapt.getRef.asInstanceOf[DeployUnit]
            statments = statments ++ List(MergeStatement("mvn:"+du.getGroupName+"/"+du.getUnitName+"/"+du.getVersion))
          }
          case _ =>
        }
    }
    model.getAdaptations.foreach {
      adapt =>
      adapt.getPrimitiveType.getName match {
        case s if s == JavaSePrimitive.instance$.getUpdateDictionaryInstance => {
          val dicMap = new java.util.HashMap[String,java.util.Properties]()
            if(adapt.getRef.asInstanceOf[Instance].getDictionary != null){
              adapt.getRef.asInstanceOf[Instance].getDictionary.getValues.foreach{value =>
                if(value.getTargetNode != null){
                  var previousDic = dicMap.get(value.getTargetNode.getName)
                  if(previousDic == null){previousDic =  new java.util.Properties }
                  previousDic.put(value.getAttribute.getName, value.getValue)
                  dicMap.put(value.getTargetNode.getName,previousDic)
                } else {
                  var previousDic = dicMap.get("*")
                  if(previousDic == null){previousDic =  new java.util.Properties }
                  previousDic.put(value.getAttribute.getName, value.getValue)
                  dicMap.put("*",previousDic)
                }
              }
            }

            adapt.getRef match {
              case ci : ComponentInstance => statments = statments ++ List(UpdateDictionaryStatement(ci.getName,Some(ci.eContainer.asInstanceOf[ContainerNode].getName),dicMap))
              case ci : Channel => statments = statments ++ List(UpdateDictionaryStatement(ci.getName,None,dicMap))
              case _ => //TODO GROUP
            }
          } //statments.add(UpdateDictionaryStatement(statement.getRef.g))
        case s if s ==  JavaSePrimitive.instance$.getAddBinding => statments = statments ++ List(AddBindingStatment(ComponentInstanceID(adapt.getRef.asInstanceOf[org.kevoree.MBinding].getPort.eContainer.asInstanceOf[ComponentInstance].getName, Some(adapt.getRef.asInstanceOf[MBinding].getPort.eContainer.eContainer.asInstanceOf[ContainerNode].getName)), adapt.getRef.asInstanceOf[MBinding].getPort.getPortTypeRef.getName, adapt.getRef.asInstanceOf[MBinding].getHub.getName))
        case s if s ==  JavaSePrimitive.instance$.getAddInstance => {

            val props = new java.util.Properties
            if (adapt.getRef.asInstanceOf[Instance].getDictionary != null) {
              adapt.getRef.asInstanceOf[Instance].getDictionary.getValues.foreach {
                value =>
                props.put(value.getAttribute.getName, value.getValue)
              }
            }

            adapt.getRef match {
              case c: Group => statments = statments ++ List(AddGroupStatment(c.getName, c.getTypeDefinition.getName, props))
              case c: Channel => statments = statments ++ List(AddChannelInstanceStatment(c.getName, c.getTypeDefinition.getName, props))
              case c: ComponentInstance => {
                  val cid = ComponentInstanceID(c.getName, Some(c.eContainer.asInstanceOf[ContainerNode].getName))
                  statments = statments ++ List(AddComponentInstanceStatment(cid, c.getTypeDefinition.getName, props))
                }
                //TODO
              case _@uncatchInstance => Log.warn("uncatched=" + uncatchInstance)
            }
          }
        case s if s ==  JavaSePrimitive.instance$.getRemoveBinding => statments = statments ++ List(RemoveBindingStatment(ComponentInstanceID(adapt.getRef.asInstanceOf[MBinding].getPort.eContainer.asInstanceOf[ComponentInstance].getName, Some(adapt.getRef.asInstanceOf[MBinding].getPort.eContainer.eContainer.asInstanceOf[ContainerNode].getName)), adapt.getRef.asInstanceOf[MBinding].getPort.getPortTypeRef.getName, adapt.getRef.asInstanceOf[MBinding].getHub.getName))
        case s if s ==  JavaSePrimitive.instance$.getRemoveInstance => {
            adapt.getRef match {
              case c: Group => statments = statments ++ List(RemoveGroupStatment(c.getName))
              case c: Channel => statments = statments ++ List(RemoveChannelInstanceStatment(c.getName))
              case c: ComponentInstance => {
                  val cid = ComponentInstanceID(c.getName, Some(c.eContainer.asInstanceOf[ContainerNode].getName))
                  statments = statments ++ List(RemoveComponentInstanceStatment(cid))
                }

              case _@uncatchInstance => Log.warn("uncatched=" + uncatchInstance)
            }
          }
        case s if s ==  JavaSePrimitive.instance$.getAddDeployUnit => {
          //already catched
        }
        case _@unCatched => Log.warn("uncatched=" + unCatched)
      }

    }
    Script(List(TransactionalBloc(statments)))
  }

}
