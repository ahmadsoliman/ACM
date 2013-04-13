package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ELIS {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] pairs = new int[n]; 
		String[] in = br.readLine().split(" ");
		for (int i = 0; i < n; i++) {
			pairs[i] = Integer.parseInt(in[i]);
		}
		System.out.print(LIS(pairs));
	}
	
	public static int LIS(int[] arr){
		int n = arr.length;
		int[] dp = new int[n];

		int maxLen=0;
		for (int i = n-1; i >= 0; i--) {
			int maxFound = 0;
			for (int j = i; j < n ; j++) {
				 if(arr[i]<arr[j] && dp[j]>maxFound){
					 maxFound = dp[j];
				 }
			}
			dp[i] = maxFound + 1;
			if(dp[i]>maxLen){
				maxLen = dp[i];
			}
		}
		return maxLen;
	}
}