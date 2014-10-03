import java.util.Random;
import java.util.Scanner;

/**
 * Created by renaud on 01/10/14.
 */
public class Tamagotchi {

    private int maxEnergie;
    private int energie;
    private String nom;

    public Tamagotchi(String nom){
        this.nom = nom;
        Random r = new Random(System.currentTimeMillis());
        maxEnergie = 5 + r.nextInt(5);
        energie = 2 + r.nextInt(3);
    }

    public void parler() {
        if (this.energie > 5) System.out.println(nom + " heureux");
        else System.out.println(nom + " affamé");
    }

    public void manger(){

        if (this.maxEnergie != this.energie){
            Random r = new Random(System.currentTimeMillis());
            this.energie += 1 + r.nextInt(2);
            System.out.println("hum!!");
        }
        else System.out.println("Je n'ai pas faim!");

    }

    public boolean vivre (){

        if (this.energie > 0){
            this.energie--;
            return true;
        }
        System.out.println(this.nom + " : Je meurs!!!");
        return false;
    }

    public static void main(String [] args){
        int n = Integer.parseInt(args[0]);
        Scanner sc = new Scanner(System.in);
        Tamagotchi[] tam = new Tamagotchi[n];
        for(int i = 0; i< tam.length; i++){
            System.out.print("Quel est le nom pour le nouveau tmagotchi :");
            String nom = sc.nextLine();
            tam[i] = new Tamagotchi(nom);
        }
        int tour = 0;
        boolean vie = true;
        while (vie){
            System.out.println("\n\n\n------Cycle no"+tour+" -------");
            for(Tamagotchi t: tam){

                vie = vie && t.vivre();
                t.parler();
            }
            for(int i = 0; i< tam.length; i++){
                System.out.print("("+i+") "+tam[i].nom+"\t");
            }
            System.out.println("\n Nourir quel Tamagotchi");
            n = sc.nextInt();
            tam[n].manger();
            tour++;


        }
    }


}
