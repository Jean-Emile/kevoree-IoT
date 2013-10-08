package org.kevoree.iot.modelTransform


import ast._
import util.parsing.combinator.syntactical.StandardTokenParsers

import collection.JavaConversions._


/**
 * Created by jed
 * User: jedartois@gmail.com
 * Date: 28/03/12
 * Time: 16:57
 **/

class ParserPush extends StandardTokenParsers {

  lexical.delimiters ++= List("/", ":", ",", "=", "{", "}", "@","+","!","*")


  def operation = numericLit ^^ {
    case s => s
  }

  def value = numericLit ^^ {
    case s => s
  }

  def instanceID = ident ^^ {
    case s => s
  }


  def nodeName = ident ^^ {
    case s => s
  }

  def nodeTypeName = ident ^^ {
    case s => s
  }

  def propertie = ident ^^ {
    case s => s
  }


  def portID = ident ^^ {
    case s => s
  }

  def chID = ident ^^ {
    case s => s
  }

  def typeIDB = numericLit ^^ {
    case s => s
  }

  def portIDB = numericLit ^^ {
    case s => s
  }

  def checksum = numericLit ^^ {
    case s => s
  }

  // 3:T1
  def parseIDPredicate: Parser[IDPredicate] = operation ~ ":" ~ instanceID ^^ {
    case d ~ _ ~ t => new IDPredicate(d.toInt, t)
  }

  def parseSerialAll : Parser[String]  = "*" ^^ {
    case s => s
  }
  // 0=100, ...
  def parsePropertiesPredicate: Parser[PropertiePredicate] = operation ~ "=" ~ (value | ident | parseSerialAll) ^^ {
    case d ~ _ ~ t => new PropertiePredicate(d.toInt, t.toString)
  }

  //0:T1:period=1000
  def parseUDI: Parser[Adaptation] =
    parseIDPredicate ~ ":" ~ rep1sep(parsePropertiesPredicate, ",") ^^ {
      case a ~ _ ~ b => new UDI(a, Some(b))
    }

  //1:T1:0:0=50000
  //"1:D1:0/
  def parseAIN: Parser[Adaptation] =
    parseIDPredicate ~ opt (":") ~ typeIDB ~ opt (":") ~ opt(rep1sep(parsePropertiesPredicate, ",")) ^^ {
      case a ~ _ ~ b ~ _ ~ c => { new AIN(a, b.toInt, c) }
    }

  //2:S1
  def parseRIN: Parser[Adaptation] = value ~ ":" ~ instanceID ^^ {
    case a ~ _ ~ b => new RIN(a.toInt, b)
  }

  //3:T1: S1:0$
  def parseABI: Parser[Adaptation] =
    parseIDPredicate ~ ":" ~ chID ~ ":" ~ portIDB ^^ {
      case a ~ _ ~ b ~ _ ~ c => new ABI(a, b, c.toInt)
    }

  //
  def parseRBI: Parser[Adaptation] = parseIDPredicate ~ ":" ~ chID ~ ":" ~ portIDB ^^ {
    case a ~ _ ~ b ~ _ ~ c => new RBI(a, b, c.toInt)
  }


  //    "period:serialport,period:serialport,Timer:SerialCT,tick/ " +
  def parseGlobalDefinitions: Parser[GlobalDefintions] = rep1sep(propertie, ":") ~ opt(":") ~ "," ~ rep1sep(propertie, ":") ~ opt(":") ~ "," ~ rep1sep(propertie, ":") ~ opt(":") ~ "/" ^^ {
    case properties ~ _ ~ _ ~ typedefinition ~ _ ~ _ ~ portdefinition ~ _ ~ _ => {
      new GlobalDefintions(properties, typedefinition, portdefinition)
    }
  }

  //  global
  def requestParse: Parser[Adaptations] = nodeName ~ ":" ~ nodeTypeName ~ "@" ~ "{" ~ opt(parseGlobalDefinitions) ~ repsep(( parseABI | parseUDI | parseAIN | parseRIN ), "/") ~ opt("/") ~ "}" ~ "+" ~checksum~ "!" ^^ {
    case nodename ~ _ ~ nodeTypeName ~ _ ~ _ ~ definitions ~ adaptations ~ _ ~ _~ _ ~ checksum~ _=> new Adaptations(nodename, nodeTypeName, definitions, adaptations,checksum.toLong)
  }


  def parseAdaptations(chaine: String): Adaptations =
  {
    requestParse(new lexical.Scanner(chaine)) match {
      case Success(_rules, _) => _rules
      case Failure(msg, _) => throw new Exception("Bad syntax: " + msg)
      case Error(msg, _) => throw new Exception("Bad syntax: " + msg)
    }


  }

}