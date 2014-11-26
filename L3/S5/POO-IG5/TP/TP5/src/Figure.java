public abstract class Figure {

    private int posX;
    private int posY;

    public Figure(int x, int y) {
        posX = x;
        posY = y;
    }



    public abstract void affiche();

    public int getPosX() {
        return posX;
    }

    public int getPosY() {
        return posY;
    }
}