package Archive;

import java.util.ArrayList;
import java.util.Arrays;

public class LISDP {
	public static void main(String[] args) {
		LIS(new int[]{9,1,2,3,8,4,5,0});
	}
	
	public static ArrayList<Integer> LIS(int[] arr){
		int n = arr.length;
		int[] dp = new int[n];
		//dp[n][n] = 1;

		int x=-1;
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
				x = i;
			}
		}
		System.out.println(Arrays.toString(dp));
		
		
		ArrayList<Integer> res = new ArrayList<Integer>(arr.length);
		res.add(arr[x]);
		int j = ++x+1;
		while(x<n&&j<n){
			if(arr[x]<arr[j]&&dp[x]-dp[j]==1){
				res.add(arr[x]);
				x=j;
				j++;
			}else{
				j++;
			}
		}
		res.add(arr[x]);
		System.out.println(res.toString());
		return res;
	}
}
