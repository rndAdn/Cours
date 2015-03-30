import java.io.*;
import java.net.Socket;

/**
 * Created by renaud on 09/03/15.
 */
public class Entite1 {

    String servAddr = "lucien";
    int servPort = 48500;
    Socket sock;
    BufferedReader br;
    PrintWriter pw;
    public Entite1(){

        try {
            sock = new Socket(servAddr, servPort);
            br = new BufferedReader(
                    new InputStreamReader(
                            sock.getInputStream()));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public void run(){
        String s = "";
        try {
            s = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        String [] tab = s.split(" ");
        try {
            br.close();
            sock.close();
            sock = new Socket(tab[0], Integer.parseInt(tab[1]));
            sock = new Socket(servAddr, servPort);
            pw  = new PrintWriter(
                    new OutputStreamWriter(
                            sock.getOutputStream()));
        } catch (IOException e) {
            e.printStackTrace();
        }
        pw.println("CONFIRM");
        pw.flush();
        try {
            s = br.readLine();
            if (s.equals("ACKCONFIRM"))System.out.println();
            pw.close();
            br.close();
            sock.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
