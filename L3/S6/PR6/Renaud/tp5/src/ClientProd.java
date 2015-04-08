import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

public class ClientProd {

    Scanner sc;
    String servAddr = "lucien";
    int servPort = 48501;
    Socket socket;
    PrintWriter pw;

    public ClientProd(){
        sc = new Scanner(System.in);
        try {
            socket = new Socket(servAddr, servPort);
            pw  = new PrintWriter(
                    new OutputStreamWriter(
                            socket.getOutputStream()));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public void runProd(){
        String message = "";
        while (true){
            message = sc.nextLine();
            pw.println(message);
            pw.flush();

        }
    }


    public static void main(String[] args){


        ClientProd clientProd = new ClientProd();
        clientProd.runProd();
    }

}
