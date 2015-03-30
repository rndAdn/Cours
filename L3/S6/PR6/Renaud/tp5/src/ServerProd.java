import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerProd implements Runnable{

    BufferConcurrent bc;
    ServerSocket srvSock;

    public ServerProd(BufferConcurrent bc){
        this.bc = bc;
        try {
            srvSock= new ServerSocket(48501);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public void runServCons() {
        while (true) {
            try {
                Socket clientSock = srvSock.accept();
                BufferedReader comBR = new BufferedReader(
                        new InputStreamReader(
                                clientSock.getInputStream()));
                String s;
                while (true) {
                    s = comBR.readLine();
                    bc.ajouter(s);
                }
                //comBR.close();
                //clientSock.close();


            } catch (Exception e) {
                //System.out.println("Problem with client.\n");
            }
        }
    }

    @Override
    public void run() {
        runServCons();
    }
}
