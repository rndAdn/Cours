import java.net.*;
import java.io.*;
import java.util.Random;

public class PlayerService implements Runnable {
private Socket comSock;
public PlayerService(Socket comSock){
        this.comSock = comSock;
}

public void run(){
  try {
        Random rand = new Random();
        System.out.println("New connection stablished with " +
                           comSock.getInetAddress().getHostName() +
                           " (port " + comSock.getPort() +
                           "), trying to communicate...");
        BufferedReader comBR = new BufferedReader(
                new InputStreamReader(
                        comSock.getInputStream()));
        PrintWriter comPW = new PrintWriter(
                new OutputStreamWriter(
                        comSock.getOutputStream()));
        int number = rand.nextInt(100) + 1, guess = -1;
        System.out.println("The number chosen is " + number + ".");
        String str = "";
        String name = comBR.readLine();
        System.out.println("Player identified as " + name + ".");
        comPW.println("!");
        comPW.flush();
        while (true) {
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
        } else if (str.toUpperCase().equals("QUIT")) {
                comPW.println(".");
                comPW.println(number);
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
