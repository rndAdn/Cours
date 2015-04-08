
public class Appartement {
	private int numero;
	private Immeuble immeuble;
	
	public Appartement(int numero,Immeuble immeuble){
		this.numero = numero;
		this.immeuble =immeuble;
	}
	
	public String toString(){
		return "Appartement numero :" + numero + " de l'immeuble : " + immeuble.toString();
	}
}
