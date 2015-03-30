
public class Animal {
  private final String nom;
  private final String espece;
  protected int age;
  //private int ageEnfant;
  protected int ageAdulte;
  protected int ageMort;

  public Animal(String nom,String espece,int age){
    this.nom = nom;
    this.espece = espece;
    this.age = age;
    this.ageAdulte = 9;
    this.ageMort = 41;
  }

  public Animal(String nom,String espece,int age,int ageAdulte,int ageMort){
    this(nom,espece,age);
    this.ageAdulte = ageAdulte;
    this.ageMort = ageMort;
  }

  public String getNom(){
    return this.nom;
  }

  public String getEspece(){
    return this.espece;
  }

  public boolean carnivore(){
    return false;
  }

  public boolean nourirAvecViande(boolean bool){
    return (bool || !carnivore());
  }

}
