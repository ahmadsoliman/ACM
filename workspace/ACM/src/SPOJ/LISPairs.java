package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class LISPairs {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		Point[] pairs = new Point[n]; 
		for (int i = 0; i < n; i++) {
			String[] in = br.readLine().split(" ");
			pairs[i] = new Point(Integer.parseInt(in[0]),Integer.parseInt(in[1]));
		}
		System.out.print(LIS(pairs));
	}
	
	public static int LIS(Point[] arr){
		int n = arr.length;
		int[] dp = new int[n];

		int maxLen=0;
		for (int i = n-1; i >= 0; i--) {
			int maxFound = 0;
			for (int j = i; j < n ; j++) {
				 if(arr[i].x<arr[j].x && arr[i].y<arr[j].y && dp[j]>maxFound){
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
	static class Point{
		public int x,y;
		public Point(int x , int y) {
			this.x = x;
			this.y = y;
		}
	}
}
