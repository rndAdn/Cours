/**
 * Created by renaud on 14/10/14.
 */
public class Dictionnaires extends Media {

    private final String langue;
    private final int nb_tome;

    public Dictionnaires(String titre, String langue, int nb_tome) {
        super(titre);
        this.langue = langue;
        this.nb_tome = nb_tome;
    }

    public String toString(){
        return super.toString()+" Langue: "+langue+" Nombre de tome: "+nb_tome;
    }

    public String getLangue() {
        return langue;
    }

    public int getNb_tome() {
        return nb_tome;
    }
}
