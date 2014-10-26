
public class main {
	
	static public double surfaceHabitableTotale(Batiment[] tabBat){
		double result = 0;
		for (int i = 0; i < tabBat.length; i++) {
			if(tabBat[i] instanceof Batiment)
			result += tabBat[i].getSurfaceHabitable();
		}
		return result;
	}
	
	static public int surfaceJardinTotale(Batiment[] tabBat){
		int result = 0;
		for (int i = 0; i < tabBat.length; i++) {
			if(tabBat[i] instanceof Maison)
			result += ((Maison)tabBat[i]).getSurfaceJardin();
		}
		return result;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Batiment bat = new Batiment("20 chemin de la belle idée", 200);
		Maison mai = new Maison("11 rue henri dumond", 12, 0, 1);
		Immeuble im = new Immeuble("69 blvd vincent auriol", 13, 25);
		Batiment tab[] = new Batiment[10];
		tab[2] = im;
		tab[6] = mai;
		for (int i = 0; i < tab.length; i++) {
			System.out.println(tab[i]);
		}
	}

}
