package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class COINS {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String in;	
		while((in=br.readLine())!=null){
			System.out.println(recur(Integer.parseInt(in)));
		}
	}
	
	static int[] dp = new int[100000001];
	public static long recur(int coins){
		if(coins<12){
			return coins;
		}
		int a = coins/2, b = coins/3, c = coins/4;
		if(dp[a]==0)
			dp[a] = (int)recur(a);
		if(dp[b]==0)
			dp[b] = (int)recur(b);
		if(dp[c]==0)
			dp[c] = (int)recur(c);
		
		return Math.max(coins, dp[a]+dp[b]+dp[c]);
	}
}
