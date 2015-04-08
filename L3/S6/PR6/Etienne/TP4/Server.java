import java.io.*;
public class Server{

  public static void main(String[] args) {
    BufferConcurrent buf = new BufferConcurrent();
    new ServerCons(buf).start();
    new ServerProd(buf).start();
  }

}
