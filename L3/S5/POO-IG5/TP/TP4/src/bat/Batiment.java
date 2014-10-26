package bat;

/**
 * Created by renaud on 22/10/14.
 */
public class Batiment {

    private String adresse;
    private int surfaceHabitable;
    private static double TauxA = 5.6;
    private Personne prop;


    public Batiment(String adresse, int surfaceHabitable, Personne prop){
        this.adresse = adresse;
        this.surfaceHabitable = surfaceHabitable;
        this.prop = prop;
    }

    public String toString(){
        return "Adresse :"+this.adresse+" surface habitable :"+this.surfaceHabitable;
    }


    public int getSurfaceHabitable(){
        return this.surfaceHabitable;
    }

    public double impot(){
        return TauxA*surfaceHabitable;
    }

    public Personne getProp(){
        return prop;
    }
}
