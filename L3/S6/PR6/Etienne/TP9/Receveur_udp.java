
import java.io.*;
import java.net.*;

public class Receveur_udp {
  public static void main(String[] args){
    try{
      //Ouverture de la "socket" d'écoute
      DatagramSocket dso=new DatagramSocket(4242);
      //Tableau pour stocker les données du paquet recu
      byte[]data=new byte[100];
      //Le paquet en question
      DatagramPacket paquet=new DatagramPacket(data,data.length);
      while(true){
        //Commande bloquante attendant la réception d'un paquet 
        dso.receive(paquet);
        //Convertion des data du paquet en string
        String st=new String(paquet.getData(),0,paquet.getLength());
        //Recuperation des info de l'expediteur
        InetSocketAddress ia=(InetSocketAddress) paquet.getSocketAddress();
        /* System.out.println(ia.getHostName()+":"+ia.getPort()+" "+st); */
        DatagramPacket paquet2= new DatagramPacket(paquet.getData(),paquet.getData().length,ia);
        //Fonction envoyant le paquet a l'adresse
        dso.send(paquet2);


      }
    } catch(Exception e){
      e.printStackTrace();
    }
  }
}
