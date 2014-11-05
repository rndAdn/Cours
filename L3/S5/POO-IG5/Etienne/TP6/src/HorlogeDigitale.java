import java.text.SimpleDateFormat;
import java.util.Date;


public class HorlogeDigitale {
	static public void afficheHeure(){
		long yourmilliseconds = System.currentTimeMillis();
		SimpleDateFormat sdf = new SimpleDateFormat("HH:mm");
        Date resultdate = new Date(yourmilliseconds);
        System.out.println(sdf.format(resultdate));
	}
}
