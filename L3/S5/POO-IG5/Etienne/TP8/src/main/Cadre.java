package main;

import oracle.jrockit.jfr.JFR;

import javax.swing.*;
import java.awt.*;

/**
 * Created by ByTeK on 19/11/2014.
 */
public class Cadre extends JFrame {
    public Cadre(){
        this.setTitle("Palette");
        this.setPreferredSize(new Dimension(600, 600));
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLayout(null);
        //this.addMouseListener(null);
        int alea = (int)(Math.random()*10+1);
        //System.out.println(alea);
        for(int i = 0;i<alea;i++) {
            this.add(new Carre());
        }

        this.pack();
        this.setVisible(true);
        //repaint();
    }

    boolean gagne(){
        for (Component c : this.getComponents()){
            Carre c1 = (Carre)c;
            if(c1.getBackground() != Color.red)return false;
        }
        return true;
    }
    public void gagne2(){
        if (gagne())this.dispose();
    }
}
