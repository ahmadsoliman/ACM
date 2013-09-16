package Contests;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Factorial {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(br.readLine());
		
		int x, zeros, fives;
		
		for (int i = 0; i < t; i++) {
			//solBigInt(Integer.parseInt(br.readLine()));
			x = Integer.parseInt(br.readLine());
			
			zeros=0;
			fives = 5; 
			while(fives<=x){
				zeros+=x/fives;
				fives*=5;
			}
			System.out.println(zeros);
		}
	}

	public static void solBigInt(int x){
		BigInteger l;
		StringBuffer xS;
		int zeros;
		
		l = new BigInteger(x+"");
		zeros = 0;
		
		for (int j = x-1; j > 1; j--) {
			l  = l.multiply(new BigInteger(j+""));
			
			xS = new StringBuffer(l.toString());
			
			for (int j2 = xS.length()-1; j2 > 0; j2--) {
				if(xS.charAt(j2)=='0')
					zeros++;
				else{
					xS.delete(j2+1,xS.length());
					break;
				}
			}
			l = new BigInteger(xS.toString());
		}
		System.out.println(zeros);
	}
}

//zeros = 0;
//for (int j = 5; j <= x; j+=5) {
//	temp = j;
//	tens = 10;
//	while(temp%tens==0){
//		tens*=10;
//		zeros++;
//	}
//	temp /= tens;
//	temp*=10;
//	fives = 5;
//	while(temp%fives==0){
//		fives*=5;
//		zeros++;
//	}
//}
