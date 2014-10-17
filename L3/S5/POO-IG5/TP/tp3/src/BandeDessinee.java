/**
 * Created by renaud on 14/10/14.
 */
public class BandeDessinee extends Livre {

    private final String dessinateur;

    public BandeDessinee(String titre, String langue, int nb_tome, String dessinateur) {
        super(titre,langue, nb_tome);
        this.dessinateur=dessinateur;
    }


    public String toString(){
        return super.toString()+" Dessinateur: "+this.dessinateur;
    }

}
