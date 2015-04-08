import java.io.*;
import java.net.*;

public class ClientCons{
  public static void main(String[] args) {
    try {
      Socket sock = new Socket("lucien", 4313);
      BufferedReader br = new BufferedReader(new InputStreamReader(sock.getInputStream()));
      PrintWriter pw = new PrintWriter(new OutputStreamWriter(sock.getOutputStream()));
      //Runtime.getRuntime().addShutdownHook(new Hook(pw));
      while(true){
          String s = br.readLine();
          System.out.println(s);
          pw.print("ok\n");
          pw.flush();
          if(s.equals("Quit"))break;
      }
      pw.close();
      br.close();
      sock.close();
    } catch (Exception e) {
      e.printStackTrace();
      System.out.println("Connection failed. Try again later.");
    }
  }
}
