import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Rectangle;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionListener;
import java.awt.image.BufferedImage;
import java.awt.image.ColorModel;
import java.awt.image.Raster;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JMenuBar;
import javax.swing.JPanel;
import javax.swing.undo.UndoManager;


public class ImageEdit extends JFrame{
	JButton quitButton = new JButton("quit");
	JButton cutButton = new JButton("cut");
	JButton undoButton = new JButton("undo");
	JButton redoButton = new JButton("redo");
	ImagePane imagePane;
	UndoManager undoManager = new UndoManager();

	class ImagePane extends JPanel{
		BufferedImage image;
		Selection selection = new Selection();
		public ImagePane(){
			super();
			try {
				image = ImageIO.read(new File("/Users/ByTeK/Pictures/usless.jpg"));
			} catch (IOException e) {
				e.printStackTrace();
				System.exit(1);
			}
			setPreferredSize(new Dimension(image.getWidth(),image.getHeight()));
			//this.getGraphics().drawImage(image,0,0,200,200,null);
			//this.repaint();
			this.setVisible(true);
			addMouseListener(selection);
			addMouseMotionListener(selection);
		}
		@Override
		public void paintComponent(Graphics g){
			//System.out.println("COUCIU");
			super.paintComponents(g);
			g.drawImage(image,0,0,this);
		}
		
		void fillzone (Rectangle z, int[][] pixels){
			//getRaster() et getColorModel() 
			//getDataElements
			//de ColorModel et la methode ´ setDataElements de WritableRaster.
			Raster r = image.getRaster();
			ColorModel cm = image.getColorModel();
			cm.getDataElements(components, offset, obj)
			r.setDataElements();
		}
		class Selection extends MouseAdapter implements MouseMotionListener{
			int xA;
			int xB;
			int yA;
			int yB;
			@Override
			public void mouseDragged(MouseEvent e) {
				// TODO Auto-generated method stub
				xB = e.getX();
				yB = e.getY();
				
			}

			@Override
			public void mouseMoved(MouseEvent e) {
				// TODO Auto-generated method stub
			}
			@Override
			public void mousePressed(MouseEvent e) {
				// TODO Auto-generated method stub
				xA= e.getX();
				yA=e.getY();
				
			}
			Rectangle getRectangle(){
				return new Rectangle(xA,yA,xB-xA,yB-yA);
				
			}	
			
		}
		
	}

	public ImageEdit(){
		super();
		setTitle("Image Edit");
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		JMenuBar menu = new JMenuBar();
		menu.add(quitButton);
		menu.add(cutButton);
		menu.add(undoButton);
		menu.add(redoButton);
		undoButton.setEnabled(false);
		redoButton.setEnabled(false);
		cutButton.setEnabled(false);
		quitButton.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				System.exit(0);
			}
		});
		cutButton.addActionListener(new ActionListener(){
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub

			}
		});
		setJMenuBar(menu);
		imagePane = new ImagePane();
		setContentPane(imagePane);
		//imagePane.repaint();
	}
}
