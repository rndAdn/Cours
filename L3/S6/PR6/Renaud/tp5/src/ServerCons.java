import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerCons implements Runnable{

    BufferConcurrent bc;
    ServerSocket srvSock;

    public ServerCons(BufferConcurrent bc){
        this.bc = bc;
        try {
            srvSock= new ServerSocket(48500);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public void runServCons() {
        while (true) {
            try {
                Socket clientSock = srvSock.accept();
                PrintWriter comPW = new PrintWriter(
                        new OutputStreamWriter(
                                clientSock.getOutputStream()));
                while (true) {
                    comPW.println(bc.retirer());
                    comPW.flush();
                }
                //comPW.close();
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
