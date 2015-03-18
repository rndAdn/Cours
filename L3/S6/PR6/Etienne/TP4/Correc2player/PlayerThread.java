package com.company;

import java.net.*;
import java.io.*;
import java.util.Random;
import java.util.HashSet;

public class PlayerThread extends Thread {
public int number;
public Socket comSock;
public BufferedReader comBR;
public PrintWriter comPW;
public GameServer gs;
//public boolean loose = false;
public PlayerThread(int number,Socket comSock,GameServer gs){
        this.gs = gs;
        this.number = number;
        this.comSock = comSock;
}

public void run(){
        try {
                this.comBR = new BufferedReader(
                        new InputStreamReader(
                                comSock.getInputStream()));
                this.comPW = new PrintWriter(
                        new OutputStreamWriter(
                                comSock.getOutputStream()));
                int guess = -1;
                System.out.println("The number chosen is " + number + ".");
                String str = "";
                String name = comBR.readLine();
                System.out.println("Player identified as " + name + ".");
                comPW.println("!");
                comPW.flush();
                while (!isInterrupted()) {
                        System.out.print("Waiting for a guess...");
                        str = comBR.readLine();
                        System.out.println(" " + str + ".");
                        if (str.equals("quit")) break;
                        try {
                                guess = Integer.parseInt(str);
                        } catch (NumberFormatException nfe) {
                                comPW.println("?");
                                comPW.flush();
                                continue;
                        }
                        if (guess < number) {
                                comPW.println("+");
                        }
                        else if (guess > number)
                                comPW.println("-");
                        else if (guess == number)
                                break;
                        comPW.flush();
                }
                if (guess == number) {
                        System.out.println("The guess was correct.");
                        comPW.println("=");
                        gs.win(name);
                } else if (str.toUpperCase().equals("QUIT") || isInterrupted()) {
                        comPW.println(".");
                        comPW.println(number);
                        comPW.println(gs.winner);
                } else {
                        System.out.println("Bad input.");
                        comPW.println("*");
                }
                comPW.flush();
                System.out.println("Closing connection...");
                comBR.close();
                comPW.close();
                comSock.close();
                System.out.println("Connection closed.\n");
        } catch (Exception e) {
                System.out.println("Failed to create server socket:");
                e.printStackTrace();
        }
}
}
