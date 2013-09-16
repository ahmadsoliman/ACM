package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class LENGFACT {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(br.readLine());
		
		double pi=3.14159265358979323;
		long digits, n;
		
		for (int i = 0; i < t; i++) {
			n = Long.parseLong(br.readLine());
			digits = (long)Math.floor(Math.abs((Math.log(2*pi*n)/2.0+n*(Math.log(n)-1))/Math.log(10.0)))+1;
			System.out.println(digits);
		}
		
	}
}

