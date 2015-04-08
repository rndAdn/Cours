
public class Batiment {
	private String adresse;
 	private double surfaceHabitable;
 	private Personne proprietaire;
 	private double TauxA = 5.6;
 	
 	public Batiment(String adresse, double surface){
 		this.adresse = adresse;
 		this.surfaceHabitable = surface;
 	}
 	
 	public String toString(){
 		return "adresse :" + adresse+ "surface :"+ surfaceHabitable;
 	}
 	
 	public double getSurfaceHabitable(){
 		return surfaceHabitable;
 	}
 	
 	public Personne getProprietaire(){
 		return proprietaire;
 	}
 	
 	public double impot(){
 		return TauxA*this.surfaceHabitable;
 	}
 	
 	void setProprietaire(Personne prop){
 		this.proprietaire = prop;
 	}
}
