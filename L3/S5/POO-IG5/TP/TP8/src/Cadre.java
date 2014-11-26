import javax.swing.*;
import javax.swing.event.MouseInputListener;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.sql.Time;
import java.util.Random;

/**
 * Created by renaud on 19/11/14.
 */
public class Cadre extends JFrame{

    public class Carre extends JPanel implements MouseInputListener{

        int lastX;
        int lastY;

        public Carre(){
            Random r = new Random();
            this.setBounds(r.nextInt(550),r.nextInt(550),50,50);
            setBackground(new Color(r.nextInt(255),r.nextInt(255),r.nextInt(255)));

            this.addMouseListener(this);
            this.addMouseMotionListener(this);
        }


        @Override
        public void mouseClicked(MouseEvent mouseEvent) {

        }

        @Override
        public void mousePressed(MouseEvent mouseEvent) {
            this.lastX = mouseEvent.getX();
            this.lastY = mouseEvent.getY();
        }

        @Override
        public void mouseReleased(MouseEvent mouseEvent) {
            setBackground(Color.RED);
        }

        @Override
        public void mouseEntered(MouseEvent mouseEvent) {

        }

        @Override
        public void mouseExited(MouseEvent mouseEvent) {

        }

        @Override
        public void mouseDragged(MouseEvent mouseEvent) {
            this.setBounds(getX()+ mouseEvent.getX() - lastX,getY()+mouseEvent.getY()-lastY,50,50);
            //this.lastX += mouseEvent.getX();
            //this.lastY += mouseEvent.getY();
            System.out.println(lastX + "  "+lastY);
            //this.repaint();


        }

        @Override
        public void mouseMoved(MouseEvent mouseEvent) {
        }
    }

    Container container;
    Carre tab;
    Cadre(){
        Random r = new Random();
        this.setTitle("TP8");
        this.setPreferredSize(new Dimension(600, 600));
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.container = this.getContentPane();
        this.container.setLayout(null);
        this.pack();
        this.setVisible(true);
        this.getDefaultCloseOperation();
        int max = r.nextInt(10);
        for (int i = 0;i<max; i++){
            this.add(new Carre());
        }
    }





    public static void main(String [] args){

        new Cadre();
    }
}
