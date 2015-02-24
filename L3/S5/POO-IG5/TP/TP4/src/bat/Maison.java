package bat;

import bat.Batiment;
import bat.Personne;

/**
 * Created by renaud on 22/10/14.
 */
public class Maison extends Batiment {

    private int nbPieces;
    private int surfaceJardin;

    private static double TauxB = 1.5;

    public Maison(String adresse, int surfaceH, int surfaceJ, int nbPieces, Personne prop){
        super(adresse,surfaceH, prop);
        this.nbPieces = nbPieces;
        this.surfaceJardin = surfaceJ;
    }

    public String toString(){
        return super.toString()+" nombre de pièce :"+nbPieces+" surface jardin :"+surfaceJardin;
    }


    public int getSurfaceJardin(){
        return this.surfaceJardin;
    }


    public double impot(){
        return super.impot()+TauxB*surfaceJardin;
    }


}
