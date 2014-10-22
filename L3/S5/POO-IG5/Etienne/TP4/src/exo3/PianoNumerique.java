package exo3;

public class PianoNumerique extends Piano{
	private boolean toucherLourd;
	private Qualite qualiteEchantillonnage;
	
	public PianoNumerique(String nom, int prixAchat, int prixVente,int largeur, int longueur,boolean toucherLourd,Qualite qualiteEch) {
		super(nom, prixAchat, prixVente, largeur, longueur);
		this.toucherLourd = toucherLourd;
		this.qualiteEchantillonnage = qualiteEch;
		// TODO Auto-generated constructor stub
	}
}
