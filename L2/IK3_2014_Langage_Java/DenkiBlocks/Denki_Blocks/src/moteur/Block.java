package moteur;

import java.awt.*;

public class Block {
	private static int nombre_blocks;
	private int ID;
	private Image image = null;
	private Block b_Doite;
	private Block b_Haut;
	private Block b_Bas;
	private Block b_Gauche;

	public Block() {
		this.b_Haut = null;
		this.b_Doite = null;
		this.b_Bas = null;
		this.b_Gauche = null;
	}
	public Block(Block h,Block d,Block b,Block g) {
		this.b_Haut = h;
		this.b_Doite = d;
		this.b_Bas = b;
		this.b_Gauche = g;
	}

	/*GET*/

	public static int getNombre_Blocks() {
		return nombre_blocks;
	}

	public int getID() {
		return ID;
	}

	public Image getImage() {
		return image;
	}
	public Block getB_Doite() {
		return b_Doite;
	}

	public Block getB_Haut() {
		return b_Haut;
	}

	public Block getB_Bas() {
		return b_Bas;
	}

	public Block getB_Gauche() {
		return b_Gauche;
	}

	/*SET*/

	public static void setNombre_blockspIncr() {
		Block.nombre_blocks++;
	}

	public void setID(int ID) {
		this.ID = ID;
	}

	public void setImage(Image image) {
		this.image = image;
	}

	public void setB_Doite(Block b_Doite) {
		this.b_Doite = b_Doite;
	}

	public void setB_Haut(Block b_Haut) {
		this.b_Haut = b_Haut;
	}

	public void setB_Bas(Block b_Bas) {
		this.b_Bas = b_Bas;
	}

	public void setB_Gauche(Block b_Gauche) {
		this.b_Gauche = b_Gauche;
	}
}
