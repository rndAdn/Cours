import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketException;

public class Udp {



    public static void main(String[] args){
        byte [] buff = new byte[1024];

        DatagramSocket socketudp;
        DatagramPacket datagramPacket=new DatagramPacket(buff,buff.length);
        try {
            socketudp = new DatagramSocket(7552); // n° port
            while (true){
                socketudp.receive(datagramPacket);
                String mess = new String(buff);
                System.out.println(datagramPacket.getAddress().getHostName()+":"+datagramPacket.getPort()+" "+mess);
                socketudp.send(datagramPacket);
            }
            //socketudp.close();
        } catch (SocketException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }


    }
}
