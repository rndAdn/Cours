/**
 * Created by renaud on 14/10/14.
 */
public class Livre extends Media {

    private final String auteur;
    private final int nb_pages;

    public Livre(String titre, String auteur, int nb_pages) {
        super(titre);
        this.auteur = auteur;
        this.nb_pages = nb_pages;
    }

    public String toString(){
        return super.toString()+" Auteur: "+auteur+" Nombre de page: "+nb_pages;
    }

    public boolean plusPetit(Media doc){


        if (doc instanceof Livre){
            return super.plusPetit(doc);
        }
        else {
           return false;
        }
    }



    public String getAuteur() {
        return auteur;
    }

    public int getNb_pages() {
        return nb_pages;
    }
}
