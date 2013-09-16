package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class MAXSUB {
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine()), n, nZeros, maxV, cur, nMax;
		StringTokenizer st;
		BigInteger sum, two=new BigInteger("2"), mod=new BigInteger("1000000009"), one=new BigInteger("1");
		String e="";
		while(t-->0){
			sum = new BigInteger("0");
			n = Integer.parseInt(br.readLine());
			st = new StringTokenizer(br.readLine()," ");
			
			nZeros=0;maxV=Integer.MIN_VALUE;nMax=1;
			while(st.hasMoreTokens()){
				cur = Integer.parseInt(st.nextToken());
				if(cur==0) nZeros++;
				else if(cur>0) sum=sum.add(new BigInteger(e+cur));
				if(cur>=maxV) {
					if(cur==maxV) nMax++;
					else{
						maxV=cur;
						nMax=1;
					}
				}
			}
			if(maxV>0)
				System.out.println(sum + " "  + two.modPow(new BigInteger(e+nZeros), mod));
			else if(maxV==0)
				System.out.println("0 " + (two.modPow(new BigInteger(e+nZeros), mod)).subtract(one));
			else
				System.out.println(maxV + " " + nMax);
		}
	}
}
