import javax.print.Doc;

/**
 * Created by renaud on 14/10/14.
 */
public class EtudiantAbonne extends Abonne {

    private final int empruntsMax = 2;

    private Media emprunt1 = null;
    private Media emprunt2 = null;

    public EtudiantAbonne(String nom, String prenom){
        super(nom,prenom);
    }


    public void emprunter(Media doc){
        if(doc.isEmprunter()) {
            System.out.println(this.getNom()+" "+this.getPrenom()+" ne peut pas emprunter le livre :"+doc+" car il est déjà emprunter YOU MAD BRO!!!");
            return;
        }
        if(emprunt1 != null &&emprunt2 != null ){
            System.out.println(this.getNom()+" "+this.getPrenom()+" ne peut pas emprunter le livre :"+doc+" car il a déjà emprunter "+emprunt1+" et "+emprunt2);
            return;
        }

        if(emprunt1 == null){
            this.emprunt1 = doc;
            doc.setEmprunter(true);
        }
        else{
            this.emprunt2 = doc;
            doc.setEmprunter(true);
        }
        System.out.println(this.getNom()+" "+this.getPrenom()+" a emprunter le livre :"+doc);


    }

    public void rendre(Media doc){
        if(emprunt1 == null &&emprunt2 == null ){
            System.out.println(this.getNom()+" "+this.getPrenom()+" ne peut pas rendre le livre :"+doc+" car il ne l'a pas emprunter ET OUAI GROS !!!");
            return;
        }

        if(emprunt1 == doc){
            this.emprunt1 = null;
            doc.setEmprunter(false);
        }
        else if(emprunt1 == doc){
            this.emprunt2 = null;
            doc.setEmprunter(false);
        }
        else{
            System.out.println(this.getNom()+" "+this.getPrenom()+" ne peut pas rendre le livre :"+doc+" car il ne l'a pas emprunter ET OUAI GROS !!!");
            return;
        }
        System.out.println(this.getNom()+" "+this.getPrenom()+" a rendu le livre :"+doc);

    }


}
