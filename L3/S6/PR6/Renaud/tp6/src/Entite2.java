import java.io.*;
import java.net.Socket;

public class Entite2 {

    String servAddr = "lucien";
    int servPort = 48500;
    Socket sock;
    PrintWriter pw;
    String adresse = "";
    int port = 7;
    BufferedReader br;
    public Entite2(){
        try {

            sock = new Socket(servAddr, servPort);
            pw  = new PrintWriter(
                    new OutputStreamWriter(
                            sock.getOutputStream()));

        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public void run(){
        pw.println(adresse+" "+port);
        pw.flush();
        pw.close();
        try {
            sock.close();
            sock = new Socket(adresse, port);
            br = new BufferedReader(
                    new InputStreamReader(
                            sock.getInputStream()));
            String s = "";
            s = br.readLine();
            if (s.equals("CONFIRM"))System.out.println();
            pw  = new PrintWriter(
                    new OutputStreamWriter(
                            sock.getOutputStream()));
            pw.println("ACKCONFIRM");
            pw.flush();
            pw.close();
            sock.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

}
