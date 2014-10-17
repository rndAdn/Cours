
public class EtudiantAbonne extends Abonne {
	private static final int empruntsMax = 2;
	
	public EtudiantAbonne(String nom, String prenom) {
		super(nom, prenom);
		//empruntsMax = 2;
		// TODO Auto-generated constructor stub
	}

	public  int getEmpruntsMax(){
		return empruntsMax;
	}
}
