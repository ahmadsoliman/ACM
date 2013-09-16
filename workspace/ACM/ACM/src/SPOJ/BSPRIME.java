package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BSPRIME {
	public static void main(String[] args) throws NumberFormatException, IOException {
		int N = 100000000;
	    boolean[] isNotPrime = new boolean[N+1];
	    isNotPrime[0]=true;
		isNotPrime[1]=true;	 
		
	    for (int i = 2; i*i <= N; i++) {
	        if (!isNotPrime[i]) {
	            for (int j = i; i*j <= N; j++) {
	                isNotPrime[i*j] = true;
	            }
	        }
	    }
	    
	    StringBuffer sb = new StringBuffer();
	    for (int i = 0; i < isNotPrime.length; i++) {
	    	if (!isNotPrime[i]) {
	    		sb.append(i+",");
	    	}
	    	if(i%100000==0)
	    		sb.append('\n');
		}
	    System.out.println(sb);
		
	    int[] dp = new int[N];
	    dp[1]=1;
	    dp[2]=1;
	    for (int i = 3; i < 100; i++) {
			if(!isNotPrime[i]){
				int power = (int)Math.ceil((Math.log(i)/Math.log(2)))-1;
				dp[i] = 1 + dp[(int)(i-Math.pow(2, power))];
				//System.out.println(i + " : " + power + " : " + dp[i]);
			}
		}
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(br.readLine()), n;
		for (int i = 0; i < t; i++) {
			n = Integer.parseInt(br.readLine());
			
			int bits = (int)Math.log10(n)+1;
			
			for (int j = 2; j < 100; j++) {
				if(!isNotPrime[j])
					System.out.println(j+" : "+toBinary(j)+" : "+countOnes(toBinary(j)));
			}
			
			System.out.println(bits);
		}
	}
	public static String toBinary(int x){
		String s = "";
		while(x>0){
			s = (x%2)+s;
			x/=2;
		}
		return s;
	}
	public static int countOnes(String s){
		int count=0;
		for (int i = 0; i < s.length(); i++) {
			if(s.charAt(i)=='1')
				count++;
		}
		return count;
	}
}
