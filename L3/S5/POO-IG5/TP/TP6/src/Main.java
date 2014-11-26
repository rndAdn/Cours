/**
 * Created by renaud on 05/11/14.
 */
public class Main {

    public static int f(int i){
        return i;
    }

    public static Integer g(Integer i){
        return i;
    }

    public static void main(String[] args){

        System.out.println(f(new Integer(1)));
        System.out.println(g(1));
    }
}
