package Contests;

import java.util.ArrayList;
import java.util.Arrays;

public class Knapsack {
	public static void main(String[] args) {
		ArrayList<Integer> V = new ArrayList<Integer>(),W = new ArrayList<Integer>();
		
		V.add(5);V.add(2);V.add(7);V.add(1);V.add(9);
		W.add(1);W.add(2);W.add(3);W.add(4);W.add(5);
		
		System.out.println(knapsack(V, W, 10));
		
	}
	
	int[] values,weights;
	
	//5,2,7,1,9
	//1,2,3,4,5
	public static ArrayList<Integer> knapsack(ArrayList<Integer> V, ArrayList<Integer> W, int C){
		
		int n = V.size();
		int[][] dp = new int[n+1][n+1];
		
		for (int i = n-1; i >= 0; i--) {
			for (int j = n-1; j >= 0; j--) {
				if(i==j)
					dp[i][j] = W.get(i);
				else if(W.get(i)<C){
					dp[i][j] = Math.max(V.get(i)+dp[i-1][j-1], dp[i][j-1]);
				}else{
					
				}
			}
		}
		
		for (int i = 0; i < dp.length; i++) {
			System.out.println(Arrays.toString(dp[i]));
		}
		
		return null;
	}
}
