import javax.swing.*;
import javax.swing.undo.UndoManager;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.image.BufferedImage;

/**
 * Created by renaud on 26/11/14.
 */
public class ImageEdit  extends JFrame{

    class ImagePane extends JPanel{

        BufferedImage image;

    }


    JButton quitButton, cutButton, undoButton, redoButton;
    ImagePane imagePane;
    UndoManager undoManager = new UndoManager();

    public ImageEdit(){
        super();
        this.setTitle("TP9");
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        quitButton = new JButton("quitter");
        quitButton.addActionListener(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                System.exit(0);
            }
        });

        cutButton = new JButton("cut");
        cutButton.addActionListener(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                //System.exit(0);
            }
        });
        cutButton.setEnabled(false);

        undoButton = new JButton("undo");
        undoButton.addActionListener(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                //System.exit(0);
            }
        });
        undoButton.setEnabled(false);

        redoButton = new JButton("redo");
        redoButton.addActionListener(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                //System.exit(0);
            }
        });
        redoButton.setEnabled(false);

        JMenuBar menuBar = new JMenuBar();

        menuBar.add(quitButton);
        menuBar.add(cutButton);
        menuBar.add(undoButton);
        menuBar.add(redoButton);

        imagePane = new ImagePane();
        this.setPreferredSize(new Dimension(600, 600));
        this.pack();
        this.setVisible(true);

    }



    public static void main(String [] args){
        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new ImageEdit();
            }
        });
    }

}
