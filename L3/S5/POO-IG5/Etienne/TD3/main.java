public class main {

  public static int comptePanthereNoires(Animal[] zoo){
    int i = 0;
    for (Animal ani : zoo){
      if(ani instanceof PanthereNoire)i++;
    }
    return i;
  }

  public static void main(String[] args) {
  }
}
