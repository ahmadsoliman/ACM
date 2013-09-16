package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class DSUBSEQ {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(br.readLine()), len;
		StringBuffer in;
		
		long[] sum;
		int[] last;
		int mod = 1000000007;
		
		for (int i = 0; i < t; i++) {
			in = new StringBuffer(br.readLine());
			len = in.length();
			sum = new long[len+1];
			last = new int[26];
			
			sum[0] = 1;
			for (int j = 1; j <= len; j++) {
				sum[j] = ((2*sum[j-1])%mod + mod)%mod;
				if(last[in.charAt(j-1)-'A']-1>=0)
					sum[j] = ((sum[j]-sum[last[in.charAt(j-1)-'A']-1])%mod + mod)%mod;
				last[in.charAt(j-1)-'A'] = j;
			}
			
			System.out.println((sum[len]%mod + mod)%mod);
		}
	}
}
