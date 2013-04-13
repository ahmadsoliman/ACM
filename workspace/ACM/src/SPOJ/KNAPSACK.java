package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class KNAPSACK {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer sT = new StringTokenizer(br.readLine());
		int S =	Integer.parseInt(sT.nextToken());
		int N =	Integer.parseInt(sT.nextToken());
		int[] W = new int[N];
		int[] V = new int[N];
		
		for (int i = 0; i < N; i++) {
			sT = new StringTokenizer(br.readLine());
			W[i] = Integer.parseInt(sT.nextToken());
			V[i] = Integer.parseInt(sT.nextToken());
		}
		
		int max = 0;
		int dp[][] = new int[N+1][S+1];
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= S; j++) {
				if(W[i-1]>j){
					if(i>0)
						dp[i][j] = dp[i-1][j];
				}else{
						dp[i][j] = Math.max(dp[i-1][j], dp[i-1][j-W[i-1]]+V[i-1]);
				}
				if(dp[i][j]>max)
					max = dp[i][j];
			}
		}
		System.out.println(max);
	}
}
