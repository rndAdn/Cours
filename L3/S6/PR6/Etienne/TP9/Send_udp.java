
import java.io.*;
import java.net.*;
import java.util.Scanner;

public class Send_udp {
  public static void main(String[] args){
    try{
      //Ouverture de la "socket" d'écoute
      DatagramSocket dso=new DatagramSocket(4243);
      //Tableau pour stocker les données du paquet recu
      byte[]data=new byte[100];
      Scanner sc = new Scanner(System.in);
      //Le paquet en question
      data = sc.nextLine().getBytes();
      DatagramPacket paquet= new DatagramPacket(data,data.length,InetAddress.getByName("localhost"),4242);
      dso.send(paquet);
      DatagramPacket paquet_recv=new DatagramPacket(data,data.length);
      dso.receive(paquet);
      System.out.println(new String(paquet.getData()));
        //Commande bloquante attendant la réception d'un paquet 
        /* dso.receive(paquet); */
        //Convertion des data du paquet en string
        /* String st=new String(paquet.getData(),0,paquet.getLength()); */
        //Recuperation des info de l'expediteur
        /* InetSocketAddress ia=(InetSocketAddress) paquet.getSocketAddress(); */
        /* System.out.println(ia.getHostName()+":"+ia.getPort()+" "+st); */
        /* DatagramPacket paquet2= new DatagramPacket(paquet.getData(),paquet.getData().length,ia); */
        //Fonction envoyant le paquet a l'adresse
        

      
    } catch(Exception e){
      e.printStackTrace();
    }
  }
}

