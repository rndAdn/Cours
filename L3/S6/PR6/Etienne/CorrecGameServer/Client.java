import java.io.*;
import java.net.*;
import java.util.Scanner;

public class Client {
public static void main(String[] args) {
								String servAddr = "0.0.0.0";
								int servPort = 4213;
								String	name = "";
								if (args.length > 0)
																name = args[0];
								if (args.length == 3) {
																servAddr = args[1];
																try {
																								servPort = Integer.parseInt(args[2]);
																} catch (NumberFormatException e) {
																								System.out.println("The right call to this programme is:");
																								System.out.println("java GuessClient <server name> <server port>");
																								System.out.println("where <server port> should be an integer.");
																}
								}
								Scanner sc = new Scanner(System.in);
								System.out.println("Connecting to server...");
								try {
																Socket sock = new Socket(servAddr, servPort);
																System.out.println("Connection established.");
																System.out.println("Trying to communicate...");
																try {
																								BufferedReader br = new BufferedReader(
																																new InputStreamReader(
																																								sock.getInputStream()));
																								PrintWriter pw = new PrintWriter(
																																new OutputStreamWriter(
																																								sock.getOutputStream()));
																								System.out.println("Communication established.");
																								System.out.println("Identification underway...");
																								if(name.equals("")) {
																									System.out.println("Quel est votre nom ?");
																									BufferedReader brStd = new BufferedReader(new InputStreamReader(System.in));
																									name = brStd.readLine();
																								}
																								pw.println(name);
																								pw.flush();
																								System.out.println("Waiting for the game to start...");
																								String msg = br.readLine();
																								if (!msg.equals("!")) {
																																System.out.println("Server is acting weird. Quitting...");
																																br.close();
																																pw.close();
																																sock.close();
																																System.out.println("Connection closed. Try again later.");
																																System.exit(0);
																								}
																								System.out.println("Go!");
																								System.out.print("Start guessing.   ");
																								while (true) {
																																String guess = sc.nextLine();
																																pw.println(guess);
																																pw.flush();
																																msg = br.readLine();
																																if (msg.equals("+"))
																																								System.out.print("Guess higher.     ");
																																else if (msg.equals("-"))
																																								System.out.print("Guess lower.      ");
																																else if (msg.equals("."))
																																								break;
																																else if (msg.equals("="))
																																								break;
																																else if (msg.equals("?"))
																																								System.out.print("Guess again.      ");
																																else if (msg.equals("*"))
																																								break;
																																else {
																																								System.out.println("Server seems not to be respecting the protocol.");
																																								System.out.println("Disconnecting...");
																																								pw.close();
																																								br.close();
																																								sock.close();
																																								System.out.println("Connection closed. Try again later.");
																																								break;
																																}
																								}
																								if (msg.equals(".")) {
																																msg = br.readLine();
																																String winner = br.readLine();
																																System.out.println("Game over. The number was " + msg +
																																																			" and the winner, " + winner + ".");
																								}
																								else if (msg.equals("="))
																																System.out.println("Correct! You win.");
																								else if (msg.equals("*"))
																																System.out.println("Server is not happy with us.");
																								else {
																																System.out.println("Something unexpected happend.");
																								}
																								System.out.println("Thanks for playing, goodbye.");
																								System.out.println("Disconnecting...");
																								pw.close();
																								br.close();
																								sock.close();
																								System.out.println("Connection closed.");
																} catch (Exception e) {
																								System.out.println("Communication failed. Quitting...");
																								sock.close();
																								System.out.println("Connection closed. Try again later.");
																								System.exit(0);
																}
								} catch (Exception e) {
																e.printStackTrace();
																System.out.println("Connection failed. Try again later.");
								}
								sc.close();
}
}
