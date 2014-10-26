package bat;

/**
 * Created by renaud on 22/10/14.
 */
public class Immeuble extends Batiment {

    private int nbAppart;
    private Personne[] locataires;

    public Immeuble(String adresse, int surfaceH, int nbAppart, Personne prop){
        super(adresse,surfaceH, prop);
        this.nbAppart = nbAppart;
        this.locataires = new Personne[nbAppart];
    }


    public String toString(){
        return super.toString()+" nombre d'appart :"+nbAppart;
    }
    
    public Personne getlocataire(int n){
        return locataires[n-1];
    }
}
