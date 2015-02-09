import java.awt.print.Printable;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Random;
import java.util.Scanner;

/**
 * Created by renaud on 09/02/15.
 */
public class server {

    public static void server1(){
        try {
            ServerSocket serverSocket = new ServerSocket(7070);
            while (true){
                Socket socket = serverSocket.accept();
                BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                PrintWriter writer = new PrintWriter(new OutputStreamWriter(socket.getOutputStream()));
                Random r = new Random();
                int nombre = r.nextInt(100);
                writer.print("Nombre:\n");
                writer.flush();
                String s = reader.readLine();
                int i = Integer.parseInt(s);
                while (i != nombre){
                    String mess = "";

                    if (i > nombre){
                        mess = "-";
                    }
                    else if (i < nombre){
                        mess = "+";
                    }

                    writer.print(mess+"\n");
                    writer.flush();
                    s = reader.readLine();
                    i = Integer.parseInt(s);
                }
                writer.print("==\n");
                writer.flush();
                writer.close();
                reader.close();
                socket.close();
            }
        }catch (Exception e){

        }
    }

    public static void server2(){
        try {
            ServerSocket serverSocket = new ServerSocket(7070);
            while (true){
                Socket socket = serverSocket.accept();
                BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                PrintWriter writer = new PrintWriter(new OutputStreamWriter(socket.getOutputStream()));

                String s = reader.readLine();
                while (!s.equals(".")){
                    System.out.println("s1");
                    s = s.toUpperCase();
                    writer.print(s);
                    writer.flush();
                    System.out.println("s2");
                    s = reader.readLine();
                    System.out.println("s3");
                }
                writer.print(".");
                writer.flush();
                writer.close();
                reader.close();
                socket.close();
            }
        }catch (Exception e){

        }
    }



    public static void main(String[] args){
        server2();
    }
}
