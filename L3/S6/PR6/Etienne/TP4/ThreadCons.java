import java.io.*;
import java.net.*;

public class ThreadCons extends Thread{
  Socket comSock;
  BufferConcurrent buf;
  public ThreadCons(BufferConcurrent buf, Socket comSock){
    this.buf = buf;
    this.comSock = comSock;
  }

  public void run(){
    try {
      PrintWriter pw = new PrintWriter(new OutputStreamWriter(comSock.getOutputStream()));
      BufferedReader br = new BufferedReader(new InputStreamReader(comSock.getInputStream()));
      while(true){
        String s = buf.retirer();
        pw.print(s+"\n");
        pw.flush();
        if(br.readLine().equals("Quit"))break;
      }
      br.close();
      pw.close();
      comSock.close();
    } catch (Exception e) {
      e.printStackTrace();
      System.out.println("Connection failed. Try again later.");
    }
  }
}
