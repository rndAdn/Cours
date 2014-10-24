
public class Immeuble extends Batiment{
	private int nbAppart;
	private Appartement[] apparts;
	
	public Immeuble(String adresse, double surface,int nbAppart) {
		super(adresse, surface);
		this.nbAppart = nbAppart;
		this.apparts = new Appartement[nbAppart];
		for (int j = 0; j < nbAppart; j++) {
			this.apparts[j] = new Appartement(j, this);
		}
	}
	public String toString(){
		return super.toString() + " nombre d'appartements : " + nbAppart;
	}
}
