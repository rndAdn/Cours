import java.io.*;
import java.net.*;

public class ClientProd{
  public static void main(String[] args) {
    try {
      Socket sock = new Socket("lucien", 4213);
      PrintWriter pw = new PrintWriter(new OutputStreamWriter(sock.getOutputStream()));
      BufferedReader brStd = new BufferedReader(new InputStreamReader(System.in));
      while(true){
        String s = brStd.readLine();
        pw.print(s+"\n");
        pw.flush();
        if(s.equals("Quit"))break;
      }
      pw.close();
      sock.close();
    } catch (Exception e) {
      e.printStackTrace();
      System.out.println("Connection failed. Try again later.");
    }
  }
}
