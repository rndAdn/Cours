import java.net.*;
import java.io.*;
import java.util.Random;

public class Server {
  public static void main(String[] args) {

    int nbJoueur = 0;
    GameServer game;

    try {
      System.out.println("Stablishing the server socket...");
      ServerSocket srvSock = new ServerSocket(4213);
      System.out.println("Server socket stablished to " +
      srvSock.getInetAddress().getHostName() +
      " at port number " +
      srvSock.getLocalPort() + ".\n");
      Random rand = new Random();
      while (true) {
        try {
          Socket comSock = srvSock.accept();
          if(nbJoueur==0){
            game = new GameServer(comSock);
            new Thread(game).start();
          }
          else{
            game.join(comSock);
          }
          nbJoueur++;
        } catch (Exception e) {
          System.out.println("Problem with client.\n");
        }
      }
    } catch (Exception e) {
      System.out.println("Failed to create server socket:");
      e.printStackTrace();
    }
  }
}
