import java.io.*;

public class Hook extends Thread{
  PrintWriter pw;
  public Hook(PrintWriter pw){
    this.pw = pw;
  }
  public void run(){
      pw.print("Quit\n");
      pw.flush();
      System.exit(0);
  }
}
