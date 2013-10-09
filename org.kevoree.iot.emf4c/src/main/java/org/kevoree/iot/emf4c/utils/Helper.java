package org.kevoree.iot.emf4c.utils;



/**
 * Created with IntelliJ IDEA.
 * User: jed
 * Date: 09/10/13
 * Time: 13:29
 * To change this template use File | Settings | File Templates.
 */
public class Helper {

    public static String genInclude(String name){
        return             "#include \""+name+".h\"\n";
    }

    public static String genifdefheader(String name){
        return             "#ifndef H_"+name+"\n"+"" +
                "#define H_"+name+"";
    }

    public static String genifdefbottom() {
        return "#endif";
    }
}
