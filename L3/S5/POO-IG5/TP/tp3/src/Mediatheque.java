import java.util.LinkedList;

/**
 * Created by renaud on 14/10/14.
 */
public class Mediatheque {

    private LinkedList<Media> baseDeDonnees;

    public Mediatheque(){
        this.baseDeDonnees = new LinkedList<Media>();
    }

    public String toString(){
        String s = "";
        for(Media m: baseDeDonnees){
            s+=m+"\n";
        }
        return s;
    }

    public void ajouter(Media doc){
        for(Media m: baseDeDonnees){
            if(m instanceof Livre){
                if(doc.plusPetit((Livre)m)){
                    baseDeDonnees.add(baseDeDonnees.indexOf(m),doc);
                    return;
                }

            }
            else{
                if(doc.plusPetit(m)){
                    baseDeDonnees.add(baseDeDonnees.indexOf(m),doc);
                    return;
                }
            }

        }
        baseDeDonnees.addLast(doc);
    }





    public static void main(String[] args){


        Media livre1 = new Livre("livre1", "J. K. Rowling", 240);
        Media dico1 = new Dictionnaires("dico1", "fr", 1);
        Media livre2 = new Livre("livre2", "George R.R. Martin", 789);
        Media livre3 = new Livre("livre3", "J. K. Rowling", 240);
        Media dico2 = new Dictionnaires("dico2", "fr", 1);
        Media livre4 = new Livre("livre4", "George R.R. Martin", 789);


        Abonne r = new Abonne("Bertrand", "Guillaume");
        EtudiantAbonne re = new EtudiantAbonne("Adequin", "Renaud");

        Mediatheque m = new Mediatheque();
        m.ajouter(livre2);
        m.ajouter(dico1);
        m.ajouter(livre1);
        m.ajouter(livre3);
        m.ajouter(livre4);
        m.ajouter(dico2);

        System.out.println("DEPART");
        System.out.println(m);
        // EX3.4 NON



        /*r.emprunter(hp);
        re.emprunter(hp);
        System.out.println("---BU---");
        System.out.println(m);
        System.out.println("---UB---");
        re.emprunter(ltf);
        System.out.println("---BU---");
        System.out.println(m);
        System.out.println("---UB---");
        re.rendre(ll);
        System.out.println("---BU---");
        System.out.println(m);
        System.out.println("---UB---");
        re.rendre(ltf);
        System.out.println("---BU---");
        System.out.println(m);
        System.out.println("---UB---");
        r.rendre(hp);
        System.out.println("---BU---");
        System.out.println(m);
        System.out.println("---UB---");
        */

    }
}
