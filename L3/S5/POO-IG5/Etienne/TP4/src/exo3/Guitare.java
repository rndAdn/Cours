package exo3;

public class Guitare extends InstrumentCordes{
	private boolean droitier;
	private Tirant tirant;
	
	
	public Guitare(String nom, int prixAchat, int prixVente, int largeur,
			int longueur,boolean droitier,Tirant tirant) {
		super(nom, prixAchat, prixVente, largeur, longueur);
		this.tirant = tirant;
		this.droitier= droitier;
		// TODO Auto-generated constructor stub
	}
	
}
