package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class CPCRC1C {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		long[] pre = new long[9];
		pre[0]=45;
		for (int i = 1; i < pre.length; i++) {
			pre[i] = pre[i-1]*10 + (long)((int)45*Math.pow(10, i));
		}
		
		String[] in;
		int x,y;
		long sum;
		while(true){
			in=br.readLine().split(" ");
			x = Integer.parseInt(in[0]);
			y = Integer.parseInt(in[1]);
			if(x==-1)
				break;
			
			System.out.println("brute: "+brute(x,y));
			
			sum=0;
			int yPow = (""+y).length()-1, xPow = (""+x).length()-1;
			sum+=brute(1,(int)(y%Math.pow(10,yPow)));
			
			System.out.println(sum);
			
			int lowerY=y-y%(int)Math.pow(10,yPow), upperX=x+(int)Math.pow(10,xPow)-x%(int)Math.pow(10,xPow);
			
			sum+=brute(x,upperX);
			
			System.out.println(sum);
			
			int diff = lowerY-upperX;
			int diffPow = (""+diff).length()-1;
			
			int diffTenth = (int)Math.pow(10,diffPow);
			int xDigit = upperX/diffTenth, yDigit = lowerY/diffTenth;
			

			System.out.println("upperX: "+xDigit);
			System.out.println("lowerY: "+yDigit);
			
			sum+=pre[diffPow]*(yDigit-xDigit);
			
			System.out.println(sum);
			
			for (int i = xDigit; i <= yDigit; i++) {
				sum+=i*diffTenth;
			}
			
			System.out.println(sum);
		}
	}
	public static long brute(int x, int y){
		long sum=0;
		for (int i = x; i <= y; i++) {
			sum+=sum(i);
		}
		return sum;
	}
	public static int sum(int x){
		int sum=0;
		while(x>0){
			sum+=x%10;
			x/=10;
		}
		return sum;
	}
}
