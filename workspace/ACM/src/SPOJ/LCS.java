package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class LCS { // longest common SUBSTRING
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		final char[] x = br.readLine().toCharArray(), y = br.readLine().toCharArray();
		
		final int m = x.length, n = y.length;
		if(m==0||n==0){
			System.out.println(0);
			return;
		}
			
		int[][] dp = new int [2][n+1];
		
		int maxLen=0;
        // compute length of LCS and all subproblems via dynamic programming
		boolean up=true;
		for (int i = m-1; i>=0; i--) {
			char xc = x[i];
			for (int j = n-1; j>=0; j--){ 
				if(up){
					if(xc==y[j]){
						dp[0][j] = dp[1][j+1] + 1;
						if (dp[0][j]>maxLen)
							maxLen = dp[0][j];
					}
				}else
					if(xc==y[j]){
						dp[1][j] = dp[0][j+1] + 1;
						if (dp[1][j]>maxLen)
							maxLen = dp[1][j];
					}
			}
			up = !up;
		}
		System.out.println(maxLen);
	}
}
