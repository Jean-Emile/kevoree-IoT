package org.kevoree.iot.modelTransform

import org.kevoree.ContainerRoot
import org.kevoree.framework.KevoreeXmiHelper
import org.kevoree.impl.DefaultKevoreeFactory
import org.kevoree.tools.marShell.parser.{ParserUtil, KevsParser}
import org.kevoree.tools.marShell.ast.Script
import org.kevoree.cloner.DefaultModelCloner
import org.kevoree.tools.marShell.interpreter.KevsInterpreterContext


/**
 * Created by jed
 * User: jedartois@gmail.com
 * Date: 28/03/12
 * Time: 13:29
 */

object TesterParser extends App {



  val test = "node0:ContikiNode@{" +
    "0:efef/" +
    "}+2138!"



  val test8 ="{0:http://maven.kevoree.org/archiva/repository/daum/snapshots\n" +
    "0:http://repo.maven.apache.org/maven2\n" +
    "0:http://maven.kevoree.org/daum/release\n" +
    "0:https://maven.itm.uni-luebeck.de/content/repositories/releases/\n" +
    "0:https://oss.sonatype.org/content/groups/public/\n" +
    "0:http://repository.jetbrains.com/all\n" +
    "0:https://github.com/mkovatsc/maven/raw/master/thirdparty/\n" +
    "0:https://github.com/mkovatsc/maven/raw/master/releases/\n" +
    "0:https://github.com/mkovatsc/maven/raw/master/snapshots/\n" +
    "14:node0:ContikiNode\n" +
    "14:node4:ContikiNode\n" +
    "14:node2:ContikiNode\n" +
    "14:node3:ContikiNode\n" +
    "8:group1706717330:ContikiGroup:{}\n" +
    "8:group1706717330:node0\n" +
    "8:group1706717330:node4\n" +
    "8:group1706717330:node2\n" +
    "8:group1706717330:node3\n}"



  try {



    val newModel = new DefaultKevoreeFactory().createContainerRoot()

    val parser =new KevsParser();

     val oscript = parser.parseScript("{" + ParserUtil.loadFile("/home/jed/KEVOREE_PROJECT/kevoree-IoT/org.kevoree.iot.org.kevoree.iot.marShellContikiTransform/src/resources/model.kev") + "}");

      ModelTransform.generateKevScriptCompressed(oscript.get,"node0");


    //GET SCRIPT FROM COM PORT
    val script: Script = ModelTransform.miniPlanKevScript(ModelTransform.generateKevScriptFromCompressed(test, newModel))
             //println(script)

    //APPLY TO BUILD A CURRENT MODEL
    import org.kevoree.tools.marShell.interpreter.KevsInterpreterAspects._
    val cc = new DefaultModelCloner
    val current = cc.clone(newModel)

    val result = script.interpret(KevsInterpreterContext(current))





  } catch {
    case _@e => println(e)
  }


}