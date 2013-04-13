package Contests;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class SimpleEncryption {
	public static void main(String[] args) throws IOException {
				
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input;
		int caseNum = 1;
		long modConst = (long)Math.pow(10, 12);
		while(!(input=br.readLine()).trim().equals("0")){
			int k1 = Integer.parseInt(input);
			for (long i = (long) Math.pow(10.0,11.0); i < modConst; i++) {
				String reached=modPow(k1, i, modConst);
				if(reached.equals(i+"")){
					System.out.println("Case " + caseNum + ": Public Key = " + k1 +" Private Key = " + i);
					break;
				}
			}
			caseNum++;
			break;
		}
	}
	public static String modPow(int a, long b, long mod){
		BigInteger x = new BigInteger(a+"");
		BigInteger y = new BigInteger(b+"");
		BigInteger z = new BigInteger(mod+"");
		return x.modPow(y, z).toString();
	}
}
