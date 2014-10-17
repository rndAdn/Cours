
public class Livre extends Media{
	private final String auteur;
	private final int nbrePages;

	public Livre(String titre,String auteur,int nbrePages) {
		super(titre);
		this.auteur=auteur;
		this.nbrePages = nbrePages;
		// TODO Auto-generated constructor stub
	}
	public String toString(){
		return super.toString()+" "+auteur+ "tomes: "+nbrePages;
	}
	public boolean plusPetit(Media doc){
		if(!(doc instanceof Livre))return false;
		return getNumero()<doc.getNumero();
	}
}
