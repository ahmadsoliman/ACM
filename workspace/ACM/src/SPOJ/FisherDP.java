package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class FisherDP {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer sT = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(sT.nextToken()), t = Integer.parseInt(sT.nextToken());
		int[][] time , toll;
		String[] values;
		
		int[][] dp;
		
		while(!(n==0&&t==0)){
			time = new int[n][n];
			toll = new int[n][n];
			
			for (int i = 0; i < n; i++) {
				values = br.readLine().split(" ");
				for (int j = 0; j < n; j++) {
					time[i][j] = Integer.parseInt(values[j]);
				}
			}
			br.readLine();
			for (int i = 0; i < n; i++) {
				values = br.readLine().split(" ");
				for (int j = 0; j < n; j++) {
					toll[i][j] = Integer.parseInt(values[j]);
				}
			}
			
			dp = new int[n+1][t+1];
			
			for (int i = 1; i <= t; i++) {
				dp[0][i] = Integer.MAX_VALUE-1000000;
			}
			for (int i = 1; i < dp[0].length; i++) {
				for (int j = 0; j < n; j++) {
					dp[0][i] += 0;
				}
			}
			
			int lastSelected = 0;
			for (int i = 1; i < n; i++) {
				for (int j = 1; j <= t  ; j++) {
					if(time[lastSelected][i]<=j){
						int a = dp[i-1][j] , b = toll[lastSelected][i] + dp[i-1][j-time[lastSelected][i]];
						if(a < b){ 
							dp[i][j] = a;
						}else{
							dp[i][j] = b;
							lastSelected = i;
						}
					}else
						dp[i][j] = dp[i-1][j];
				}
			}
			
			for (int i = 0; i < dp.length; i++) {
				System.out.println(Arrays.toString(dp[i]));
			}
			
			System.out.println("");
			
			
			br.readLine();
			sT = new StringTokenizer(br.readLine());
			n = Integer.parseInt(sT.nextToken());
			t = Integer.parseInt(sT.nextToken());
		}
	}
}

/* toll : dp[city][time] 
 */
