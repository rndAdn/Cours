import java.util.*;

public class BufferConcurrent{
  private LinkedList<String> list = new LinkedList<String>();
  public synchronized void ajouter(String s){
    list.add(s);
    try{
      notifyAll();
    }
    catch (Exception e) {
      //System.out.println("Failed to create server socket:");
      //e.printStackTrace();
    }
  }
  public synchronized String retirer(){
    while(list.isEmpty()){
      try{
        wait();
      }
      catch (Exception e) {
        //System.out.println("Failed to create server socket:");
        //e.printStackTrace();
      }
    }
    return list.pollFirst();
  }
}
