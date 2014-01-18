package moteur;

public class Map {
	public static final String LEVEL_FOLDER = "data/level/";
	private Case[][] cases;
	private int width;
	private int height;
	private String name;

	public Map(){
		this.cases = null;
		this.width = 0;
		this.height = 0;
		this.name = "";
	}

	public Map(int level){
		initialisationMap(LEVEL_FOLDER+level+".lvl");
	}
	public Map(String path){
		initialisationMap(path);
	}

	private void initialisationMap(String path){
		Map map = FileManager.loadMap(path);
		this.cases = map.cases;
		this.width = map.getWidth();
		this.height = map.getHeight();
		this.name = map.getName();
		loadImages();
	}

	private void loadImages(){
		for(int i =0;i<this.getHeight(); i++){
			for(int j =0;j<this.getWidth(); j++){
				this.getCases()[i][j].setImage(FileManager.loadBgImg(0));
			}

		}
		for(int i =0;i<this.getHeight(); i++){
			for(int j =0;j<this.getWidth(); j++){
				if (this.getCases()[i][j].getBlock() != null){
					this.getCases()[i][j].getBlock().setImage(FileManager.loadBlockImg(0,0,0,0));
				}

			}

		}
		for(int i =0;i<this.getHeight(); i++){
			for(int j =0;j<this.getWidth(); j++){
				if (this.getCases()[i][j].getObstacle() != null){
					this.getCases()[i][j].getObstacle().setImage(FileManager.loadBlockImg(0,0,0,0));
				}

			}

		}
		checkFusionBlock();
		checkFusionObs();
	}

	private void checkFusionBlock(){


	}


	private void checkFusionObs(){
		for(int i =0;i<this.getHeight(); i++){
			for(int j =0;j<this.getWidth(); j++){
				if (this.getCases()[i][j].getObstacle() != null){
					if (i < this.getHeight()-1 && this.getCases()[i+1][j].getObstacle() != null){
						this.getCases()[i][j].getObstacle().setB_Bas(this.getCases()[i + 1][j].getObstacle()) ;
					}
					if (i>0 && this.getCases()[i-1][j].getObstacle() != null){
						this.getCases()[i][j].getObstacle().setB_Haut(this.getCases()[i - 1][j].getObstacle());
					}
					if (j < this.getWidth()-1 && this.getCases()[i][j+1].getObstacle() != null){
						this.getCases()[i][j].getObstacle().setB_Doite(this.getCases()[i][j + 1].getObstacle());
					}
					if (j>0 && this.getCases()[i][j-1].getObstacle() != null){
						this.getCases()[i][j].getObstacle().setB_Gauche(this.getCases()[i][j - 1].getObstacle());
					}
				}
			}
		}
		for(int i =0;i<this.getHeight(); i++){
			for(int j =0;j<this.getWidth(); j++){
				if (this.getCases()[i][j].getObstacle() != null){
					int h = getCases()[i][j].getObstacle().getB_Haut()!=null?1:0;
					int d = getCases()[i][j].getObstacle().getB_Doite()!=null?1:0;
					int b = getCases()[i][j].getObstacle().getB_Bas()!=null?1:0;
					int g = getCases()[i][j].getObstacle().getB_Gauche()!=null?1:0;
					this.getCases()[i][j].getObstacle().setImage(FileManager.loadObstacleImg(h,d,b,g));
				}

			}

		}
	}


	/*GET*/

	public Case[][] getCases() {
		return cases;
	}

	public int getWidth() {
		return width;
	}

	public int getHeight() {
		return height;
	}

	public String getName() {
		return name;
	}

	/*SET*/

	public void setCases(Case[][] cases) {
		this.cases = cases;
	}

	public void setWidth(int width) {
		this.width = width;
	}

	public void setHeight(int height) {
		this.height = height;
	}

	public void setName(String name) {
		this.name = name;
	}


}
