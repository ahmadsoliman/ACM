package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class MNNITAR {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(br.readLine());
		long n;
		BigInteger power, base=new BigInteger("2"), mod = new BigInteger("1000000007");
		
		double a=1.6180339887498948 , b=-0.618033988749894848, sqrt5= Math.sqrt(5);
		
		for (int i = 0; i < t; i++) {
			n = Long.parseLong(br.readLine())-1;
			
			power = new BigInteger(""+((long)Math.ceil((Math.pow(a, n)-Math.pow(b, n))/sqrt5)+1));
			System.out.println(base.modPow(power, mod));
		}
	}
}

