import java.net.*;
import java.io.*;
import java.util.Random;
import java.util.HashSet;

public class GameServer {
  Random rand;
  int number;
  HashSet<PlayerThread> set;

  public GameServer(){
    this.rand = new Random();
    this.number = rand.nextInt(100) + 1;
    this.set = new HashSet<PlayerThread>();
  }

  public void ajouterPlayer(Socket comSock){
    PlayerThread pt = new PlayerThread(this.number,comSock,this);
    set.add(pt);
    pt.start();
  }

  public void win(){
    for (PlayerThread pt : set) {
      pt.interrupt();
      pt.setLoose();
    }
    this.set = new HashSet<PlayerThread>();
    this.number = rand.nextInt(100) + 1;
  }

}
