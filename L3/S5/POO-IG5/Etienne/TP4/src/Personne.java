import java.util.ArrayList;

public class Personne {
	private String nom;
	private String prenom;
	private ArrayList<Batiment> proprietaire;
	private ArrayList<Appartement> locataire;
	
	public Personne(String nom, String prenom){
		this.nom = nom;
		this.prenom = prenom; 
		this.proprietaire = new ArrayList<Batiment>();
		this.locataire = new ArrayList<Appartement>();
	}
}
