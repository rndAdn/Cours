import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.Socket;
import java.net.UnknownHostException;

public class port {

    void ex1(String [] args){

        int deb = Integer.parseInt(args[0]);
        int fin = Integer.parseInt(args[1]);
        String machine = args[0];
        Socket socket;
        for(int i = deb ; i<=fin ; i++){
            try{
                socket = new Socket(machine, i);
                System.out.println(i);
                socket.close();
            }catch (Exception e){
            }


        }
    }

    public static void ex2(String [] args){
        String machine = args[0];

        try{
            Socket socket = new Socket(machine, 13);
            BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            System.out.println(reader.readLine());
        }catch (Exception e){
        }
    }
    public static void main(String[] args){

        ex2(args);
    }
}
