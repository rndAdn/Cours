import java.lang.System;
import java.io.*;
import java.applet.*;

public class MaSec extends Applet{
  public static void main(String[] args){
    System.out.println("JRE VERSION : "+System.getProperty("java.version"));
    System.out.println("JRE PATH : "+System.getProperty("java.home"));
    System.out.println("CLASS PATH : "+System.getProperty("java.class.path"));
    System.out.println("USER NAME : "+System.getProperty("user.name"));
    System.out.println("HOME DIRECTORY : "+System.getProperty("user.home"));
    System.out.println("WORKING DIRECTORY : "+System.getProperty("user.dir"));
    
    System.out.println("FILE SEPARATOR : "+System.getProperty("file.separator"));
    System.out.println("REP SEPARATOR : "+System.getProperty("path.separator"));
    System.out.println("LINE SEPARATOR : "+System.getProperty("line.separator"));
    
    try{
      BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(args[0])));
      System.out.println(br.readLine());
      br.close();
    }
    catch(Exception e){
			System.err.println(e.toString());
		}



  }
}
