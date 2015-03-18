import java.io.*;
import java.net.*;

public class Client {
  public static void main(String[] args){
    try{
      //La socket d'envoye de paquet
      DatagramSocket dso=new DatagramSocket();
      byte[]data;
      for(int i=0;i <= 10; i++){
        //Thread.sleep(1000);
        String s="MESSAGE "+i+" \n";
        //convertit s en byte et le place dans date
        data=s.getBytes();
        //alternative
        //DatagramPacket paquet=newDatagramPacket(data,data.length,InetAddress.getByName("localhost"),5555);
        //Creer l'adresse ou envoyer le paquet
        InetSocketAddress ia=new InetSocketAddress("localhost",5555);
        //Creer le paquet a envoyer
        DatagramPacket paquet= new DatagramPacket(data,data.length,ia);
        //Fonction envoyant le paquet a l'adresse
        dso.send(paquet);
      }
    } catch(Exception e){
      e.printStackTrace();
    }
  }
}
