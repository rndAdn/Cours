package moteur;

import java.awt.*;

public class Obstacle {

	private Image image = null;
	private Obstacle b_Doite;
	private Obstacle b_Haut;
	private Obstacle b_Bas;
	private Obstacle b_Gauche;

	public Obstacle() {
		this.b_Haut = null;
		this.b_Doite = null;
		this.b_Bas = null;
		this.b_Gauche = null;
	}
	public Obstacle(Obstacle h,Obstacle d,Obstacle b,Obstacle g) {
		this.b_Haut = h;
		this.b_Doite = d;
		this.b_Bas = b;
		this.b_Gauche = g;
	}

	/*GET*/
	public Image getImage() {
		return image;
	}
	public Obstacle getB_Doite() {
		return b_Doite;
	}

	public Obstacle getB_Haut() {
		return b_Haut;
	}

	public Obstacle getB_Bas() {
		return b_Bas;
	}

	public Obstacle getB_Gauche() {
		return b_Gauche;
	}

	/*SET*/

	public void setImage(Image image) {
		this.image = image;
	}

	public void setB_Doite(Obstacle b_Doite) {
		this.b_Doite = b_Doite;
	}

	public void setB_Haut(Obstacle b_Haut) {
		this.b_Haut = b_Haut;
	}

	public void setB_Bas(Obstacle b_Bas) {
		this.b_Bas = b_Bas;
	}

	public void setB_Gauche(Obstacle b_Gauche) {
		this.b_Gauche = b_Gauche;
	}
}
