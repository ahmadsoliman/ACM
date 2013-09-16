package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class CRDS {
	public static void main(String[] args) throws NumberFormatException, IOException {
		long[] pre = new long[1000001];
		 
		for (int i = 1; i < pre.length; i++) {
			pre[i] = (pre[i-1] + (i-1) + i*2)%1000007;
		}
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(br.readLine()), N;
		
		for (int i = 0; i < t; i++) {
			N = Integer.parseInt(br.readLine());
			System.out.println(pre[N]);
		}
	}
}