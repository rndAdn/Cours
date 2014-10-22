
public class Maison extends Batiment {
	private int nbPieces;
	private int surfaceJardin;
	private double TauxB = 1.5;

	public Maison(String adresse, int surfaceH, int surfaceJ, int nbPieces) {
		super(adresse, (double)surfaceH);
		this.nbPieces = nbPieces;
		this.surfaceJardin = surfaceJ;
	}
	public String toString(){
		return super.toString() + " nombre de Piece : " + nbPieces + " surface jardin : " + surfaceJardin;
	}
	
	public int getSurfaceJardin(){
		return this.surfaceJardin;
	}
	
	public double impot(){
 		return super.impot() + TauxB*this.surfaceJardin;
 	}

}
