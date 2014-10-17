
public class BandeDessinee extends Livre {
	private final String illustrateur;
	public BandeDessinee(String titre, String auteur,String illustrateur, int nbrePages) {
		super(titre, auteur, nbrePages);
		this.illustrateur = illustrateur;
		// TODO Auto-generated constructor stub
	}
	public String toString(){
		return super.toString()+illustrateur;
	}
}
