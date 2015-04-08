import java.net.*;
import java.io.*;

public class ServerCons extends Thread{

  BufferConcurrent buf;
  public ServerCons(BufferConcurrent buf){
    this.buf = buf;
  }

  public void run(){
    try {
      System.out.println("Stablishing the server socket...");
      ServerSocket srvSock = new ServerSocket(4313);
      System.out.println("Server socket stablished to " +
      srvSock.getInetAddress().getHostName() +
      " at port number " +
      srvSock.getLocalPort() + ".\n");
      while (true) {
        try {
          Socket comSock = srvSock.accept();
          System.out.println("New connection stablished with " +
          comSock.getInetAddress().getHostName() +
          " (port " + comSock.getPort() +
          "), trying to communicate...");
          new ThreadCons(buf,comSock).start();

        } catch (Exception e) {
          e.printStackTrace();
          System.out.println("Problem with client.\n");
        }
      }
    } catch (Exception e) {
      System.out.println("Failed to create server socket:");
      e.printStackTrace();
    }
  }
}
