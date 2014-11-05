import java.awt.Dimension;

import javax.swing.JFrame;


public class Truc {
	static int n;
	private JFrame frame;
	public Truc(){
		n++;
		System.out.println(n + " Init");
		this.frame = new JFrame("Hey");
		frame.setSize(new Dimension(n*10, n*10));
	}
	protected void finalize(){
		try {
			super.finalize();
		} catch (Throwable e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		n--;
		if (n == 1)System.exit(0);
		System.out.println(n+"Destruction");
	}
}
