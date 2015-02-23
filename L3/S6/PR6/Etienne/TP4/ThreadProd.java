import java.io.*;
import java.net.*;

public class ThreadProd extends Thread{
  Socket comSock;
  BufferConcurrent buf;
  public ThreadProd(BufferConcurrent buf, Socket comSock){
    this.buf = buf;
    this.comSock = comSock;
  }

  public void run(){
    try {
      BufferedReader br = new BufferedReader(new InputStreamReader(comSock.getInputStream()));
      while(true){
        String s = br.readLine();
        buf.ajouter(s);
        if(s.equals("Quit"))break;
      }
      br.close();
      comSock.close();
    } catch (Exception e) {
      e.printStackTrace();
      System.out.println("Connection failed. Try again later.");
    }
  }
}
