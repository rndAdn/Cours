
public class Media {

    private static int i = 0;
    private final String titre;
    private final int numero;
    private boolean emprunter;

    public Media(String titre){
        this.titre = titre;
        this.numero = i;
        i++;
        this.emprunter = false;
    }

    public boolean plusPetit(Media doc){
        return this.numero < doc.numero;
    }

    public boolean plusPetit(Livre docu){
        if (!(this instanceof Livre)){
            return this.plusPetit((Media)docu);
        }
        else {
            return true;
        }
    }

    public String toString(){
        return "Dispo:"+!this.emprunter+" N°"+this.numero+" Titre : "+this.titre;
    }


    /**GET**/
    public String getTitre() {
        return titre;
    }

    public int getNumero() {
        return numero;
    }

    public boolean isEmprunter() {
        return emprunter;
    }

    public void setEmprunter(boolean emprunter) {
        this.emprunter = emprunter;
    }
}
