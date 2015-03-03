import java.net.*;
import java.io.*;

public class V4ServerV6Client{
  public static void main(String[] args) {
    String ipv4;
    try {
      System.out.println("Stablishing the server socket...");
      ServerSocket srvSock = new ServerSocket(4201);
      System.out.println("Server socket stablished to " +
      srvSock.getInetAddress().getHostName() +
      " at port number " +
      srvSock.getLocalPort() + ".\n");

      try {
        Socket comSock = srvSock.accept();
        System.out.println("New connection stablished with " +
        comSock.getInetAddress().getHostName() +
        " (port " + comSock.getPort() +
        "), trying to communicate...");
        //DO STUFF
        try {
          BufferedReader br = new BufferedReader(new InputStreamReader(comSock.getInputStream()));
          ipv4 = br.readLine();
          br.close();
          comSock.close();
          srvSock.close();
          Socket sock = new Socket(ipv4,4202);
          BufferedReader br2 = new BufferedReader(new InputStreamReader(sock.getInputStream()));
          System.out.println(br2.readLine());
          br2.close();
          sock.close();
          //System.out.println(ipv4);
        } catch (Exception e) {
          e.printStackTrace();
          System.out.println("Connection failed. Try again later.");
        }

      } catch (Exception e) {
        e.printStackTrace();
        System.out.println("Problem with client.\n");
      }

    } catch (Exception e) {
      System.out.println("Failed to create server socket:");
      e.printStackTrace();
    }
  }
}
