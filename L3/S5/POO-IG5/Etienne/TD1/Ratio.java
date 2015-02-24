public class Ratio{
		int numera;
    int denomi;

		public Ratio(int numera,int denomi){
      if (denomi>0){
			this.numera = numera;
			this.denomi = denomi;
      }
      else{
        System.out.print("Le denomi doit être strictement positif");
        System.exit(1);
      }
		}

    public Ratio produit(Ratio a){
      return new Ratio(a.numera*this.numera,a.denomi*this.denomi);
    }

    public Ratio addition(Ratio a){
      return new Ratio(a.numera*this.denomi + this.numera*a.denomi,a.denomi*this.denomi);
    }

    public boolean egale(Ratio a){
      return a.numera*this.denomi == this.numera*a.denomi;
    }

    public boolean plusGrand(Ratio a){
      return a.numera*this.denomi > this.numera*a.denomi;
    }
    public String toString(){
      return this.numera+"/"+this.denomi;
    }
}
