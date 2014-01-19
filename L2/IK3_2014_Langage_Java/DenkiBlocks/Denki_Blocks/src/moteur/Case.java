package moteur;

import java.awt.*;
import java.util.Objects;

public class Case {

	private Image image_bg;
	private Block block = null;
	private Obstacle  obstacle = null;

	public Case(int type){
		// type : 0 case Vide
		// type : 1 case Obstacle
		// type : 2 case Vide & Block
		initialisationCase(type);

	}
	public Case(){
		new Case(0);

	}

	private void initialisationCase(int type){
		switch (type){
			case 0 :
				this.image_bg = null;
				this.block = null;
				this.obstacle = null;
				break;
			case 1 :
				this.image_bg = null;
				this.block = null;
				this.obstacle = new Obstacle();
				break;
			case 2 :
				this.image_bg = null;
				this.block = new Block();
				this.block.setID(Block.getNombre_Blocks());
				Block.setNombre_blockspIncr();
				break;
		}
	}

	/*GET*/

	public Image getImage() {
		return image_bg;
	}

	public Block getBlock() {
		return block;
	}
	public Obstacle getObstacle() {
		return obstacle;
	}

	/*SET*/

	public void setImage(Image image) {
		this.image_bg = image;
	}

	public void setBlock(Block block) {
		this.block = block;
	}
}
