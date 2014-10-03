/**
 * Created by renaud on 01/10/14.
 */
public class Ratio {

    private int numera;
    private int denomi;

    public Ratio(int n, int d){
        this.numera = n;
        this.denomi = d;
    }

    public Ratio produit(Ratio a){
        return new Ratio(a.numera*this.numera, a.denomi*this.denomi);
    }

    public Ratio addition(Ratio a){
        int num = this.numera*a.denomi + this.denomi*a.numera;
        int dem = this.denomi*a.denomi;
        return new Ratio(num, dem);
    }

    public boolean egale(Ratio a){
        return this.numera*a.denomi == this.denomi*a.numera;
    }

    public boolean plusGrand(Ratio a){
        return this.numera*a.denomi < this.denomi*a.numera;

    }

    @Override
    public String toString(){
        return this.numera+"/"+this.denomi;
    }
}
