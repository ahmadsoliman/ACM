package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class TRT {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(br.readLine());
		}
		
		int dp[][] = new int[n+1][n+1];
		int max = 0;
		
		for (int i = 1; i < dp.length; i++) {
			dp[i][0] = dp[i-1][0] + arr[i-1] * i;
			if(dp[i][0]>max) max = dp[i][0];
		}
		for (int i = 1; i < dp.length; i++) {
			dp[0][i] = dp[0][i-1] + arr[n-i] * i;
			if(dp[0][i]>max) max = dp[0][i];
		}
		
		
		for (int i = 1; i < dp.length; i++) {
			for (int j = 1; j < dp.length; j++) {
				if(i+j>n)
					continue;
				int age = i+j;
				dp[i][j] = Math.max(dp[i][j-1]+age*arr[n-j] , dp[i-1][j]+age*arr[i-1]);
				if(dp[i][j]>max) max = dp[i][j];
			}
		}
		
//		System.out.println(Arrays.toString(arr));
//		System.out.println();
//		for (int i = 0; i < dp.length; i++) {
//			System.out.println(Arrays.toString(dp[i]));
//		}
//		
		System.out.println(max);
	}
}
