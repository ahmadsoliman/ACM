package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class PIGBANK {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		String in[];
		
		int C, n;
		int[] V, W;
		for (int i = 0; i < t; i++) {
			in = br.readLine().split(" ");
			C = Integer.parseInt(in[1])-Integer.parseInt(in[0]);
			n = Integer.parseInt(br.readLine());
			
			V = new int[n];
			W = new int[n];
			for (int j = 0; j < n; j++) {
				in = br.readLine().split(" ");
				V[j] = Integer.parseInt(in[0]);
				W[j] = Integer.parseInt(in[1]);
			}
			
			int dp[][] = new int[n+1][C+1];
			
			
			for (int j = 1; j <= n; j++) {
				for (int j2 = 1; j2 <= C; j2++) {
					
				}
			}
		}
	}
}
