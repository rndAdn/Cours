package main;

import javax.swing.*;
import javax.swing.event.MouseInputListener;
import java.awt.*;
import java.awt.event.MouseEvent;

/**
 * Created by ByTeK on 19/11/2014.
 */
public class Carre extends JPanel implements MouseInputListener {
    public Carre(){
        double alea =  Math.random();
        double alea2 =  Math.random();
        //double alea3 = Math.random();
        Color col = new Color((int)(Math.random()*255),(int)(Math.random()*255),(int)(Math.random()*255));
        this.setBounds((int)(alea*600),(int)(alea2*600),50,50);
        this.addMouseMotionListener(this);
        this.addMouseListener(this);
        this.setBackground(col);
    }
    int lastX;
    int lastY;

    @Override
    public void mouseClicked(MouseEvent e) {

    }

    @Override
    public void mousePressed(MouseEvent e) {

    }

    @Override
    public void mouseReleased(MouseEvent e) {
        this.setBackground(Color.red);
    }

    @Override
    public void mouseEntered(MouseEvent e) {

    }

    @Override
    public void mouseExited(MouseEvent e) {

    }

    @Override
    public void mouseDragged(MouseEvent e) {
        //System.out.println("JHETE");
        this.setBounds(getX()+e.getX()-lastX,getY()+e.getY()-lastY,50,50);
        //lastX = e.getX();
        //lastY = e.getY();
        //this.repaint();
        //((JFrame)this.getParent()).pack();
    }

    @Override
    public void mouseMoved(MouseEvent e) {
        //System.out.println("JHETEefefefe");
        lastX = e.getX();
        lastY = e.getY();
    }
}
