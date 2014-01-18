import java.util.ArrayList;

/**
 * Created by renaud on 12/01/14.
 */
public class Main {

    public static void main(String [] args){
        ArrayList<String> s = new ArrayList<>();
        s.add("1");
        s.add("2");
        s.add("3");
        ArrayList<String> s2 = gene(s,s.size());
        print(s2);

    }



    public static void print(ArrayList<String> tab){
        System.out.print("{ ");
        for (String s : tab){
            System.out.print(s+", ");
        }
        System.out.println("}");
    }
    public static ArrayList<String> gene(ArrayList<String> tab, int n){
        ArrayList<String> liste;
        if(n<=0){
            liste = new ArrayList<>();
            liste.add("");
            return liste;
        }
        else {
            liste = gene(tab,n-1);
            ArrayList <String>copie = new ArrayList<>(liste);
            for (int i = 0; i<copie.size();i++){
                copie.set(i, copie.get(i) + n);
            }
            liste.addAll(copie);
            return liste;
        }
    }
}
