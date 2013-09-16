package Archive;

import java.util.Arrays;

//longest common subsequence in O(n^2) dynamic
public class LCSDP {
	public static void main(String[] args) {
		LCS("alsdfkjfjkdsal","fdjskalajfkdsla");
	}
	public static int LCS(String a, String b){
		String x = a, y =b;
		if(a.length()>b.length()){
			x = b;
			y = a;
		}
		int m = x.length(), n=y.length();
		
		System.out.println(x + " " + y);
		
        // opt[i][j] = length of LCS of x[i..M] and y[j..N]
		int[][] dp = new int [m+1][n+1];
		
        // compute length of LCS and all subproblems via dynamic programming
		for (int i = m-1; i>=0; i--) {
			for (int j = n-1; j>=0; j--) {
				if(x.charAt(i)==y.charAt(j))
					dp[i][j] = dp[i+1][j+1] + 1;
				else
					dp[i][j] = Math.max(dp[i][j+1], dp[i+1][j]);
			}
		}
		
		for (int i = 0; i < dp.length; i++)
			System.out.println(Arrays.toString(dp[i]));
		
        // recover LCS itself and print it
		int i =0, j = 0;
		while(i<m&&j<n){
			if(x.charAt(i)==y.charAt(j)){
				System.out.print(x.charAt(i));
				i++;
				j++;
			}else if(dp[i+1][j] >= dp[i][j+1])
				i++;
			else
				j++;
		}
		
		return 0;
	}
}
