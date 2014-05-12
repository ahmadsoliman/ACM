import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.StringTokenizer;


public class Calendar115 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n, m;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		Calendar c = GregorianCalendar.getInstance();
	    c.set(2001, m-1, n);  

	    try {  
	        c.getTime();  
	        System.out.println(c.get(GregorianCalendar.DAY_OF_WEEK_IN_MONTH));
	     } catch (Exception e) {  
	    	 System.out.println("Impossible");
	     } 
	}
}
