package bat;

/**
 * Created by renaud on 22/10/14.
 */
public class TestBatiment {

    public static void main(String [] args){
        Batiment b = new Batiment("11 rue henri dumont", 50);
        Immeuble i = new Immeuble("23 rue des aulnaies", 50, 30);
        Maison m = new Maison("1 rue de la gare", 50, 3, 100);


        System.out.println(b);
        System.out.println(i);
        System.out.println(m);


        Batiment[] tab = new Batiment[10];
        tab[2] = i;
        tab[5] = m;
        for (int j = 0; j < tab.length; j++) {
            System.out.println(tab[j]);
        }

        System.out.println(surfaceHabitableTotale(tab));
        System.out.println(surfaceJardinTotale(tab));
    }

    public static int surfaceHabitableTotale(Batiment[] tabBat){
        int ret = 0;
        for(Batiment b: tabBat){
            if (b instanceof Batiment)
                ret += b.getSurfaceHabitable();
        }
        return ret;
    }

    public static int surfaceJardinTotale(Batiment[] tabBat){
        int ret = 0;
        for(Batiment b: tabBat){
            if (b instanceof Maison)
                ret += ((Maison) b).getSurfaceJardin();
        }
        return ret;
    }


}
