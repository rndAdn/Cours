import java.net.*;
import java.io.*;
import java.util.Random;

public class SuperPlayerService implements Runnable {

public Socket comSock;
public int id;
public BufferedReader comBR;
PrintWriter comPW;

public SuperPlayerService(Socket comSock,int id){
        this.comSock = comSock;
        comBR = new BufferedReader(new InputStreamReader(comSock.getInputStream()));
        comPW = new PrintWriter(new OutputStreamWriter(comSock.getOutputStream()));
}

public void run(){
  try {
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
