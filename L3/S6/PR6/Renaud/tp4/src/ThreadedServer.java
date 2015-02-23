import java.net.*;
import java.util.Random;

public class ThreadedServer{
    public static void main(String[] args){
        try{
            System.out.println("Stablishing the server socket...");
            ServerSocket srvSock = new ServerSocket(48500);
            System.out.println("Server socket stablished to " +
                    srvSock.getInetAddress().getHostName() +
                    " at port number " +
                    srvSock.getLocalPort() + ".\n");


            while(true){
                Socket socket=srvSock.accept();
                System.out.println("New connection stablished with " +
                        socket.getInetAddress().getHostName() +
                        " (port " + socket.getPort() +
                        "), trying to communicate...");

                PlayerService serv=new PlayerService(socket);
                Thread t=new Thread(serv);
                t.start();
            }
        }catch(Exception e){
            System.out.println(e);
            e.printStackTrace();
        }
    }
}