package mag;

/**
 * Created by renaud on 22/10/14.
 */
public class Cordes extends Instruments{

    private int longueur;
    private int largeur;

    public Cordes(String nom, double prixAchat, double prixVente, int largeur, int longueur){
        super(nom, prixAchat, prixVente);
        this.largeur = largeur;
        this.longueur = longueur;
    }


}
