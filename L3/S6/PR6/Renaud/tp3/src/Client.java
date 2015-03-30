import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

/**
 * Created by renaud on 09/02/15.
 */
public class Client {

    public static void client1(){
        try{
            Socket socket = new Socket("lucien", 7070);
            BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter writer = new PrintWriter(new OutputStreamWriter(socket.getOutputStream()));
            Scanner sc = new Scanner(System.in);

            String mess = "";
            mess = reader.readLine();
            while (!mess.equals("==")){

                System.out.print(mess+"\n");

                String nb = sc.nextLine();
                writer.print(nb+"\n");
                writer.flush();
                mess = reader.readLine();
            }
            System.out.println(mess + " fini");
            reader.close();
            writer.close();
            socket.close();
            //System.out.println(reader.readLine());
        }catch (Exception e){
        }
    }

    public static void client2(){
        try{
            Socket socket = new Socket("lucien", 7070);
            BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter writer = new PrintWriter(new OutputStreamWriter(socket.getOutputStream()));
            Scanner sc = new Scanner(System.in);

            String ret;
            ret = reader.readLine();
            while (!ret.equals(".")){
                System.out.println("ret : "+ret);
                String mess = sc.nextLine();
                writer.print(mess+"\n");
                writer.flush();
                ret = reader.readLine();

            }
            //System.out.println(ret + " fini");
            reader.close();
            writer.close();
            socket.close();
            //System.out.println(reader.readLine());
        }catch (Exception e){
        }
    }


    public static void main(String [] args) {
        client2();
    }
}
