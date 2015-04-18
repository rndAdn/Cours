class MaClasse{
    int x;

    MaClasse(){
        this.x = 0;
    }
    void set(int i){
        this.x = i;
    }

    int setIndirect(int i){
        set(i);
        return 0;
    }

    public static void main(String []args){
        MaClasse m = new MaClasse();
        m.setIndirect(3);
    }
}
