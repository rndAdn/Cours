import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import java.awt.*;

public class Palette {

    class PanelChoix extends JPanel{
        JSlider[] tab;
        public PanelChoix(){
            super();
            this.setLayout(new GridLayout(3,1));
            tab = new JSlider[3];
            for(int i = 0; i< tab.length;i++){

                tab[i] = new JSlider();
                tab[i].setMajorTickSpacing(25);
                tab[i].setMinorTickSpacing(5);
                tab[i].setPaintTicks(true);
                tab[i].setPaintLabels(true);
                this.add(tab[i]);
            }
            tab[0].setBorder(BorderFactory.createTitledBorder("Rouge"));
            tab[1].setBorder(BorderFactory.createTitledBorder("Vert"));
            tab[2].setBorder(BorderFactory.createTitledBorder("Bleu"));
        }
    }


    class Vue extends JFrame{

        PanelChoix choix;
        JPanel couleur;
        Model model;

        public Vue(Model m){
            super();
            this.setPreferredSize(new Dimension(800, 640));
            this.getContentPane().setLayout(new GridLayout(1,2));
            choix = new PanelChoix();
            couleur = new JPanel();
            choix.setBackground(Color.BLUE);
            couleur.setBackground(Color.CYAN);
            this.add(choix);
            this.add(couleur);
            this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            model = m;
        }

        public void miseAJour(){
            this.couleur.setBackground(new Color(model.getRouge()/100f,model.getVert()/100f,model.getBleu()/100f));

        }
    }

    public class Model{
        private int rouge;
        private int vert;
        private int bleu;

        public Model(int r, int v, int b){
            this.rouge = r;
            this.vert = v;
            this.bleu = b;
        }

        public int getRouge() {
            return rouge;
        }

        public void setRouge(int rouge) {
            this.rouge = rouge;
        }

        public int getVert() {
            return vert;
        }

        public void setVert(int vert) {
            this.vert = vert;
        }

        public int getBleu() {
            return bleu;
        }

        public void setBleu(int bleu) {
            this.bleu = bleu;
        }
    }

    public class Controleur implements ChangeListener{

        Model m;
        Vue v;

        public Controleur(Model m, Vue v){
            this.m = m;
            this.v = v;
        }
        @Override
        public void stateChanged(ChangeEvent changeEvent) {
            this.m.setRouge(this.v.choix.tab[0].getValue());
            this.m.setVert(this.v.choix.tab[1].getValue());
            this.m.setBleu(this.v.choix.tab[2].getValue());
            this.v.miseAJour();
        }
    }



    private Vue vue;
    private Model model;
    private Controleur controleur;

    public Palette(){
        model = new Model(50,50,50);
        vue = new Vue(model);

        controleur = new Controleur(model,vue);

        vue.choix.tab[0].addChangeListener(controleur);
        vue.choix.tab[1].addChangeListener(controleur);
        vue.choix.tab[2].addChangeListener(controleur);
        vue.pack(); // pour mettre en place la vue
        vue.setVisible(true);

    }



    public static void main(String [] args){
        Palette p = new Palette();
    }
}
