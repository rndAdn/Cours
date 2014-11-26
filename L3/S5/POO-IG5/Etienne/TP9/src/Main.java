
public class Main {

	public static void main(String [] args) {
		javax.swing.SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				ImageEdit view = new ImageEdit();
				view.pack();
				view.setVisible(true);
				view.repaint();
			}
		});
	}

}
