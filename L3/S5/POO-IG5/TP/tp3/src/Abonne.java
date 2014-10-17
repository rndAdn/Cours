/**
 * Created by renaud on 14/10/14.
 */
public class Abonne {

    private final String nom;
    private final String prenom;
    private final int empruntsMax = 1;

    private Media emprunt = null;

    public Abonne(String nom, String prenom){
        this.nom = nom;
        this.prenom = prenom;
    }

    public void emprunter(Media doc){
        if(emprunt != null){
            System.out.println(this.nom+" "+this.prenom+" ne peut pas emprunter le livre :"+doc+" car il a déjà emprunter "+emprunt);
            return;
        }
        if(doc.isEmprunter()) {
            System.out.println(this.nom+" "+this.prenom+" ne peut pas emprunter le livre :"+doc+" car il est déjà emprunter YOU MAD BRO!!!");
            return;
        }

        this.emprunt = doc;
        doc.setEmprunter(true);
        System.out.println(this.nom+" "+this.prenom+" a emprunter le livre :"+doc);
    }

    public void rendre(Media doc){
        if(emprunt != doc){
            System.out.println(this.nom+" "+this.prenom+" ne peut pas rendre de livre car il n'en n'a pas");
            return;
        }
        this.emprunt.setEmprunter(false);
        this.emprunt = null;
        System.out.println(this.getNom()+" "+this.getPrenom()+" a rendu le livre :"+doc);

    }

    public String getNom() {
        return nom;
    }

    public String getPrenom() {
        return prenom;
    }
}
