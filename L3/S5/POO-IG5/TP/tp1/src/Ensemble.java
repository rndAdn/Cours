import java.util.ArrayList;

/**
 * Created by renaud on 01/10/14.
 */
public class Ensemble {

    private ArrayList<Ratio> l;


    public Ensemble(){
        this.l = new ArrayList<Ratio>();
    }

    public void ajoute(Ratio a){
        for(Ratio e: this.l){
            if (e.egale(a)) return;
        }
        this.l.add(a);
    }

    public boolean retire(Ratio a){
        Ratio tmp = null;
        for(Ratio e: this.l){
            if (e.egale(a)) tmp = e;
        }
        if (tmp != null){
            this.l.remove(tmp);
            return true;
        }
        return false;

    }

    public boolean est_dans(Ratio a){
        for(Ratio e: this.l){
            if (e.egale(a)) return true;
        }
        return false;
    }

    @Override
    public String toString(){
        String s = "{";
        for(Ratio e: this.l){
            s+= e.toString()+", ";
        }
        return s= s.substring(0,s.length()-2)+"}";
    }

    public void union(Ensemble e1){
        for(Ratio e: e1.l){
            this.ajoute(e);
        }
    }

    public void inter(Ratio a){

    }




}
