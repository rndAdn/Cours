package moteur;

import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;


public class FileManager {
	private static final String BG_IMAGE_PATH = "data/images/";

	/**
	 * Cette fonction charge le fichier dans une ArrayList :
	 * @param path Fichier a charger
	 * @return ArrayList_File
	 */
	private static ArrayList<String> fileToArrayList(String path){
		BufferedReader reader;
		ArrayList<String> list  = new ArrayList<>();
		File file= new File(path);
		String ligne;
		try {
			reader = new BufferedReader(new FileReader(file));
		} catch (FileNotFoundException e) {
			System.err.println("error fichier 'FileManager -> fileToArrayList' initialisation reader");
			return null;
		}
		do{
			try {
				ligne = reader.readLine();
			} catch (IOException e) {
				System.err.println("error fichier 'FileManager -> fileToArrayList' readline");
				return null;
			}
			if (ligne != null && !(ligne.startsWith("#") ||ligne.equalsIgnoreCase("")))list.add(ligne.trim());
		} while(ligne != null);
		return list;
	}


	/**
	 * Cette fonction charge un profile à partir de son chemin (dossier profiles : "data/profile/"):
	 * @param name Profile a charger
	 * @return loaded_Profil
	 */
	public static Profile loadProfile(String name){
		 return null;
	}

	public static Image loadBgImg(int type) {
		Image img = null;
		if (type == 1) {
			try {
				img = ImageIO.read(new File(BG_IMAGE_PATH+"obs.png"));
			} catch (IOException e){}
		}
		else {
			try {
				img =  ImageIO.read(new File(BG_IMAGE_PATH+"sol.png"));
			} catch (IOException e){}
		}
		return img ;
	}


	public static Image loadBlockImg(int h,int d,int b, int g) {
		Image img = null;
		try {
			img =  ImageIO.read(new File(BG_IMAGE_PATH+"/blocks/blue/"+h+""+d+""+b+""+g+".png"));
		} catch (IOException e) {
			e.printStackTrace();
		}
		return img ;
	}
	public static Image loadObstacleImg(int h,int d,int b, int g) {
		Image img = null;
		try {
			img =  ImageIO.read(new File(BG_IMAGE_PATH+"/obstacle/"+h+""+d+""+b+""+g+".png"));
		} catch (IOException e) {
			e.printStackTrace();
		}
		return img ;
	}

	/**
	 * Cette fonction charge un niveau à partir de son chemin :
	 * @param path Niveau a charger
	 * @return loaded_Map
	 */
	public static Map loadMap(String path){
		Map map = new Map();

		ArrayList<String> map_List = fileToArrayList(path);

		map.setName(map_List.get(0));

		String size[] = map_List.get(1).split(" ");

		if (size.length !=2){
			System.err.println("error fichier 'FileManager -> loadMap' initialisation reader");
			return null;
		}
		Case[][] tmp_Cases;
		try{
			map.setHeight(Integer.parseInt(size[0]));
			map.setWidth(Integer.parseInt(size[1]));

		}catch (NumberFormatException e){
			System.err.println("error fichier 'FileManager -> loadMap' parsInt width & height");
			return null;
		}

		ArrayList<String> subMap = new ArrayList<>(map_List.subList(2,map.getHeight()+2));
		tmp_Cases = arrayToCases(subMap);
		map.setCases(tmp_Cases);

		return map;
	}


	private static Case[][] arrayToCases(ArrayList<String> liste){

		Case casesTab[][] = new Case[liste.size()][];
		for(int i =0;i<liste.size(); i++){
			String [] tmp = liste.get(i).split(" ");
			casesTab[i] = new Case[tmp.length];
			for(int j =0;j<casesTab[i].length; j++){
				casesTab[i][j] = new Case(Integer.parseInt(tmp[j]));
			}

		}

		return casesTab;

	}

	/*Test main open map*/

	public static void main(String [] args){
		String path = "data/level/1.lvl";
		int lvl = 1;
		Map map = new Map(path);

		/*for(int i =0;i<map.getHeight(); i++){
			for(int j =0;j<map.getWidth(); j++){
				System.out.print(map.getCases()[i][j]+" ");
			}
			System.out.println();

		}*/
		Fenetre jFrame = new Fenetre();
		jFrame.setVisible(true);
		Pan p;
		p = new Pan(map);
		jFrame.add(p);
		Scanner sc = new Scanner(System.in);


	}

	public static class Fenetre extends JFrame{

		public Fenetre() {
			initialisation();
		}


		private void initialisation(){
			this.setTitle("TortueGenial");
			setSize(32*21,32*21);


			setVisible(true);

		}
	}

	public static class Pan extends JPanel{
		public Map map;

		public Pan(Map map){this.map = map;}
		@Override
		public void paintComponent(Graphics g) {
			super.paintComponent(g);
			Graphics2D g2 = (Graphics2D) g;
			for(int i =0;i<map.getHeight(); i++){
				for(int j =0;j<map.getWidth(); j++){
					g2.drawImage(map.getCases()[i][j].getImage(),j*32,i*32,32,32,null);
				}

			}
			for(int i =0;i<map.getHeight(); i++){
				for(int j =0;j<map.getWidth(); j++){
					if (map.getCases()[i][j].getBlock() != null)g2.drawImage(map.getCases()[i][j].getBlock().getImage(),j*32,i*32,32,32,null);
				}

			}
			for(int i =0;i<map.getHeight(); i++){
				for(int j =0;j<map.getWidth(); j++){
					if (map.getCases()[i][j].getObstacle() != null)g2.drawImage(map.getCases()[i][j].getObstacle().getImage(),j*32,i*32,32,32,null);
				}

			}

		}

	}
}
