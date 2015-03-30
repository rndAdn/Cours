import java.util.LinkedList;

public class BufferConcurrent {

    LinkedList<String> liste;

    public BufferConcurrent(){
        liste = new LinkedList<String>();
    }

    public synchronized void ajouter(String s){
        liste.add(s);
        notifyAll();
    }

    public synchronized String retirer(){
        while(liste.isEmpty()){
            try {
                wait();
            } catch (InterruptedException e) {/*e.printStackTrace();*/}
        }

        return liste.pop();
    }

}
