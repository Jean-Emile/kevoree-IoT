package org.kevoree.iot.modelTransform



/**
 * Created with IntelliJ IDEA.
 * User: jed
 * Date: 08/10/13
 * Time: 17:56
 * To change this template use File | Settings | File Templates.
 */
import scala.util.parsing.combinator._

object NumberListParser extends RegexParsers {
  def number = """\d+(\.\d*)?""".r ^^ (_.toDouble)
  def numbers = rep1sep(number, ",")

  def itMatches(s: String): Boolean = parseAll(numbers, s).successful
}