package exo3;

public class GuiatreElec extends Guitare {
	private boolean ampli;
	private boolean pedale;
	
	public GuiatreElec(String nom, int prixAchat, int prixVente, int largeur,
			int longueur, boolean droitier, Tirant tirant,boolean ampli, boolean pedale) {
		super(nom, prixAchat, prixVente, largeur, longueur, droitier, tirant);
		this.ampli = ampli;
		this.pedale = pedale;
		// TODO Auto-generated constructor stub
	}
	
}
