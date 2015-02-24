import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Random;

public class CompetitivePlayerService implements Runnable {

    public static int user = 0;
    public Socket socket;
    static int number;
    public static final int MAX_PLAYER = 2;

    public CompetitivePlayerService(Socket s) {
        incUser();
        this.socket = s;
    }


    public synchronized void incUser(){
        user++;
    }


    public synchronized void decUser(){
        user--;
    }

    public void run() {
        try {
            BufferedReader comBR = new BufferedReader(
                    new InputStreamReader(
                            socket.getInputStream()));
            PrintWriter comPW = new PrintWriter(
                    new OutputStreamWriter(
                            socket.getOutputStream()));

            Random rand = new Random();
            if(user <2){
                number = rand.nextInt(100) + 1;
            }
            int guess = -1;
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
                } else if (guess > number)
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
            socket.close();
            decUser();
            System.out.println("Connection closed.\n");
        } catch (Exception e) {
            System.out.println("Problem with client.\n");
        }
    }
}
