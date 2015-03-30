package com.company;

import java.net.*;

public class Server {
	public static void main(String[] args) {
		try{
			GameServer gs = null;
			System.out.println("Stablishing the server socket...");
			ServerSocket srvSock = new ServerSocket(4213);
			System.out.println("Server socket stablished to " +
					srvSock.getInetAddress().getHostName() +
					" at port number " +
					srvSock.getLocalPort() + ".\n");
			while (true) {
				try {
					Socket comSock = srvSock.accept();
					System.out.println("New connection stablished with " +
							comSock.getInetAddress().getHostName() +
							" (port " + comSock.getPort() +
							"), trying to communicate...");
					if(gs == null)gs = new GameServer(comSock);
					else{
						gs.ajouterPlayer(comSock);
						gs.lunch();
						gs = null;
					}

				} catch (Exception e) {
					e.printStackTrace();
					System.out.println("Problem with client.\n");
				}
			}
		} catch (Exception e) {
			System.out.println("Failed to create server socket:");
			e.printStackTrace();
		}
	}
}
