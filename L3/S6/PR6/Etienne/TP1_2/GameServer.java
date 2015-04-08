import java.net.*;
import java.io.*;
import java.util.*;
import java.lang.Math;

public class GameServer implements Runnable {

  int rand;
  int nbJoueur;
  HashSet<SuperPlayerService> setJoueur;

  public GameServer(Socket comSock){
    this.setJoueur = new HashSet();
    this.rand = (int)(Math.random()*100);:\
    System.out.println("The number chosen is " + rand + ".");
    setJoueur.add(new SuperPlayerService(comSock));
  }

  public boolean join(Socket comSock){s
    setJoueur.add(new SuperPlayerService(comSock));
  }

  public void run(){

    while (true) {
      for(SuperPlayerService sock : setJoueur){
        String str = sock.comBR;
        int guess;
        if (str.equals("quit")) break;
        try{
          guess = Integer.parseInt(str);
        }catch(NumberFormatException nfe){
          System.out.println("FAUTE !");
          continue;
        }
        if (guess < number) {
          comPW.println("+");
        }
        else if (guess > number)
          comPW.println("-");
        else if (guess == number){
          //Victory
        }
        comPW.flush();


      }
    }
  }

}
