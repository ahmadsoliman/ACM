package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

//Two squares or not two squares
public class TWOSQRS {
	public static void main(String[] args) throws NumberFormatException, IOException {
		final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		final int t = Integer.parseInt(br.readLine());
		
		long inI;
		int sqrt;
		boolean entered; 
		double rest;
		
		for (int i = 0; i < t; i++) {
			inI = Long.parseLong(br.readLine());
			sqrt = (int) Math.sqrt(inI);
			
			if(sqrt*sqrt==inI){
				System.out.println("Yes");
				continue;
			}
			
			entered = false;
			for (int j = 0; j <= sqrt; j++) {
				rest = Math.sqrt(inI - j*j);
				if(rest-(int)rest==0){
					entered = true;
					break;
				}
			}
			if (entered) {
				System.out.println("Yes");
			}else{
				System.out.println("No");
			}
			
		}
	}
}
