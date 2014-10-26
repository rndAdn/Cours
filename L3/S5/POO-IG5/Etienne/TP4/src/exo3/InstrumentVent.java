package exo3;

public class InstrumentVent extends Instrument {
	private Type type;
	public InstrumentVent(String nom, int prixAchat, int prixVente,Type type) {
		super(nom, prixAchat, prixVente);
		this.type= type;
		// TODO Auto-generated constructor stub
	}
}
