import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;

public class ClientCons {

    String servAddr = "lucien";
    int servPort = 48500;
    Socket sock;
    BufferedReader br;
    public ClientCons(){

        try {
            sock = new Socket(servAddr, servPort);
            br = new BufferedReader(
                    new InputStreamReader(
                            sock.getInputStream()));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void runCons(){
        String message = "";
        while (true){
            try {
                message = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            System.out.println(message);
        }
    }

    public static void main(String[] args){
        ClientCons clientProd = new ClientCons();
        clientProd.runCons();
    }


}
