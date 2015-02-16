package com.company;

import java.net.*;
import java.io.*;
import java.util.Random;
import java.util.HashSet;

public class GameServer{
  Random rand;
  int number;
  HashSet<PlayerThread> set;
  public String winner = "";

  public GameServer(Socket comSock){
    this.rand = new Random();
    this.number = rand.nextInt(100) + 1;
    this.set = new HashSet<PlayerThread>();
    this.ajouterPlayer(comSock);
  }

  public void ajouterPlayer(Socket comSock){
    PlayerThread pt = new PlayerThread(this.number,comSock,this);
    set.add(pt);
    //pt.start();
  }

  public void lunch(){
    for (PlayerThread pt : set){
      pt.start();
    }
  }

  public void win(String winner){
    this.winner = winner;
    for (PlayerThread pt : set) {
      pt.interrupt();
      //pt.setLoose();
    }
    this.set = new HashSet<PlayerThread>();
    this.number = rand.nextInt(100) + 1;
  }

}
