package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ROOTCIPH {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(br.readLine());
		String[] data;
		int b,c,d;
		double x12, x3;
		for (int i = 0; i < t; i++) {
			data = br.readLine().split(" ");
			b = Integer.parseInt(data[0]);
			c = Integer.parseInt(data[1]);
			d = Integer.parseInt(data[2]);
			
			x12 = (b*c-9.0*d)/(2.0*(3.0*c-b*b));
			x3 = (9.0*d-4.0*b*c+b*b*b)/(3*c-b*b);
			System.out.println(x12+" "+x3);
		}
	}
	
	
}

