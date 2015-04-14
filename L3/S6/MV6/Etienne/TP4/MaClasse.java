class MaClasse {
  int x;

  MaClasse(){
  this.x = 0;
  }
  void set(int i ){
    this.x = i;
  }
  void setIndirect(int i){
    set(i);
  }
  public static void main(String[] args){
    MaClasse m = new MaClasse();
    m.setIndirect(3);
  }
}
