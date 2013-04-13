package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class CANDY3 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(br.readLine());
		long n;
		BigInteger sum;
		BigInteger[] res;
		
		for (int i = 0; i < t; i++){
			br.readLine();
			n = Integer.parseInt(br.readLine());
			if(n==0){
				System.out.println("YES");
				continue;
			}
			sum=new BigInteger("0");
			for (int j = 0; j < n; j++) {
				sum = sum.add(new BigInteger(br.readLine()));
			}
			
			res = sum.divideAndRemainder(new BigInteger(n+""));
			if(res[1].toString().equals("0")){
				System.out.println("YES");
			}else{
				System.out.println("NO");
			}
		}
	}
}