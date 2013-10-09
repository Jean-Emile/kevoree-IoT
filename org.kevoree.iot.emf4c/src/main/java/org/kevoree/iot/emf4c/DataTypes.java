package org.kevoree.iot.emf4c;

import java.util.HashMap;

/**
 * Created with IntelliJ IDEA.
 * User: jed
 * Date: 09/10/13
 * Time: 11:47
 * To change this template use File | Settings | File Templates.
 */
public class DataTypes {

   static DataTypes singleton = null;


 public static    DataTypes getInstance(){
           if(singleton == null){
               singleton = new DataTypes();
           }
     return  singleton;
    }



     HashMap dataTypes = new java.util.HashMap<String, String>() ;

     public DataTypes(){

         dataTypes.put("EBigDecimal", "bigint")    ;
         dataTypes.put("EBigInteger", "bigint") ;
         dataTypes.put("EBoolean", "short")    ;
         dataTypes.put("EBooleanObject", "short") ;
         dataTypes.put("EByte", "unsigned char")                  ;
         dataTypes.put("EByteArray", "unsigned char[]");

         dataTypes.put("EChar", "char")   ;
         dataTypes.put("ECharacterObject", "char") ;
         dataTypes.put("EDate", "char")             ;
         dataTypes.put("EDiagnosticChain", "Any")    ;
         dataTypes.put("EDouble", "Double")           ;
         dataTypes.put("EDoubleObject", "Double")      ;
         dataTypes.put("EEList", "List")                ;
         dataTypes.put("EEnumerator", "Enum")            ;
         dataTypes.put("EFeatureMap", "Any")              ;
         dataTypes.put("EFeatureMapEntry", "Any");
         dataTypes.put("EFloat", "Float")                  ;
         dataTypes.put("EFloatObject", "Float")             ;
         dataTypes.put("EInt", "int")                        ;
         dataTypes.put("EIntegerObject", "int")               ;
         dataTypes.put("EJavaClass", "Class")                  ;
         dataTypes.put("EJavaObject", "Any")                    ;
         dataTypes.put("ELong", "Long")                          ;
         dataTypes.put("ELongObject", "Long")                     ;
         dataTypes.put("EMap", "Map")                              ;
         dataTypes.put("EResource", "Any") ;
         dataTypes.put("EResourceSet", "Any")                       ;
         dataTypes.put("EShort", "short")                            ;
         dataTypes.put("EShortObject", "Short")                       ;
         dataTypes.put("EString", "char *")                            ;
         dataTypes.put("EStringToStringMapEntry", "Any")                ;
         dataTypes.put("ETreeIterator", "Any")                           ;
         dataTypes.put("EInvocationTargetException", "Any")               ;

    }




}
