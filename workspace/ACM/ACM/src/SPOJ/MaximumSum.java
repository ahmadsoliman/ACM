package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class MaximumSum {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		int[][] arr = new int[N][N];
		StringTokenizer st;
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		int maxSum=0, sum;
		for (int i = 1; i < N; i++) {
			for (int i2 = 0; i2 < N; i2++) {
				sum=0;
				for (int j = 1; j <= N; j++) {
					for (int j2 = 0; j2 < N; j2++) {
						for (int j3 = 0; j3 < N; j3++) {
							
						}
					}
				}
			}
		}
	}
}
/*
4
0 -2 -7  0
9  2 -6  2
-4  1 -4  1
-1 8  0 -2
*/