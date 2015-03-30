import java.util.Objects;

import static java.lang.Thread.sleep;

public class HorlogeDigitale implements Cloneable{

    public static class Digit implements Cloneable{
        private int val;
        private int max;

        public Digit(int max){
            this.max = max;
            this.val= 0;
        }
        public Digit(int max, int val){
            this(max);
            this.val = 0;
        }

        public int getValeur(){
            return this.val;
        }

        public void incremente(){
            if(! estALaValeurMax())
                this.val++;
            else {
                this.val=0;
            }
        }

        public boolean estALaValeurMax(){
            return this.val == this.max;
        }

        public String toString(){
            if(this.val<=9)return "0"+this.val;

            return ""+this.val;
        }

        protected Object clone()
                throws CloneNotSupportedException{
            return super.clone();
        }


    }


    private Digit horlogeD [];

    public HorlogeDigitale(){
        this.horlogeD = new Digit[2];
        this.horlogeD[0] = new Digit(23);
        this.horlogeD[1] = new Digit(59);
    };

    public void incremente(){
        horlogeD[1].incremente();
        if (horlogeD[1].getValeur() == 0){
            horlogeD[0].incremente();
        }

    }

    public String toString(){
        return ""+horlogeD[0]+":"+horlogeD[1];

    }

    protected Object clone()
            throws CloneNotSupportedException{

        HorlogeDigitale c = (HorlogeDigitale) super.clone();
        c.horlogeD = horlogeD.clone();
        c.horlogeD[0] = (Digit)horlogeD[0].clone();
        c.horlogeD[1] = (Digit)horlogeD[1].clone();
        return c;
    }

    public static void main(String[] args){
        HorlogeDigitale h = new HorlogeDigitale();
        HorlogeDigitale h2 = null;
        try {
            h2 = (HorlogeDigitale)h.clone();
        } catch (CloneNotSupportedException e) {
            e.printStackTrace();
        }
        int i = 0;
        while (true){

            h.incremente();
            System.out.println("h1 "+h);
            if (i % 5 == 0){
                h2.incremente();
                System.out.println("\th2 "+h2);
            }

            try {
                sleep(500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            i++;
        }
    }
}
