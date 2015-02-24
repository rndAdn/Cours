
public class Serv {



    public static void main(String[] args){
        ServerCons serverCons;
        ServerProd serverProd;
        BufferConcurrent bc;

        bc = new BufferConcurrent();
        serverCons = new ServerCons(bc);
        serverProd = new ServerProd(bc);
        Thread t = new Thread(serverProd);
        t.start();
        t = new Thread(serverCons);
        t.start();
    }


}
