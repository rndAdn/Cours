package exo3;

public class InstrumentCordes extends Instrument {
	private int largeur;
	private int longueur;
	
	public InstrumentCordes(String nom, int prixAchat, int prixVente, int largeur , int longueur) {
		super(nom, prixAchat, prixVente);
		this.largeur = largeur;
		this.longueur = longueur;
		// TODO Auto-generated constructor stub
	}
}
