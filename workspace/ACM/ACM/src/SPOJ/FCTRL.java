package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class FCTRL {
	public static void main(String[] args) throws NumberFormatException, IOException {
		final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		final int t = Integer.parseInt(br.readLine());
		String in;
		int inI, count;
		for (int i = 0; i < t; i++) {
			in = br.readLine();
			inI = Integer.parseInt(in);
			count=0;
			
			while(inI>0){
				inI/=5;
				count+=inI;
			}
			System.out.println(count);
		}
	}
}
