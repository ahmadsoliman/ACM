package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class JULKA {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BigInteger sum, diff, two = new BigInteger("2");
		for (int i = 0; i < 10; i++) {
			sum = new BigInteger(br.readLine());
			diff = new BigInteger(br.readLine());
			
			diff = sum.add(diff);
			diff = diff.divide(two);
			
			System.out.println(diff);
			System.out.println(sum.add(diff.negate()));
		}
	}
}
