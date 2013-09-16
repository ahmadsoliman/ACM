
package SPOJ;

import java.util.Scanner;

//harry potter philosopher's stone
public class ByteSM2 {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		int t = sc.nextInt();	
		int m=0,n=0;
		int[][] matrix=null;
		long[][] dp=null;
		for (int i = 0; i < t; i++) {
			m = sc.nextInt();
			n = sc.nextInt();
			matrix = new int[m][n];
			for (int j = 0; j < m; j++) {
				for (int j2 = 0; j2 < n; j2++) {
					matrix[j][j2] = sc.nextInt();
				}
			}
		
			/*
			//brute force , fails around 17,18 
			ByteSM2.matrix = matrix;
			visited = new boolean[m][n];
			int max=0;
			for (int j = 0; j < n; j++) {
				int cur = brute(0, j);
				if(cur>max)
					max = cur;
			}
			System.out.println(max);
			*/
			
			//dynamic
			long maxNum=0;
			dp = new long[m][n];
			for (int j = m-1; j >= 0; j--) {
				for (int j2 = n-1; j2 >= 0; j2--) {
					if(j==m-1){
						dp[j][j2] = matrix[j][j2];
					}else{
						long x=0,y=0,z=0;
						if(j2>0) {
							x = dp[j+1][j2-1];
						}
						y = dp[j+1][j2];
						if(j2<n-1) {
							z = dp[j+1][j2+1];
						}
						dp[j][j2] = matrix[j][j2] + max(x,y,z);
					}
					if(j==0&&dp[j][j2]>maxNum){
						maxNum=dp[j][j2];
					}
				}
			}
			System.out.println(maxNum);
		}
	}
	public static long max(long x, long y, long z){
		if(x>y)
			if(x>z)
				return x;
			else
				return z;
		else
			if(y>z)
				return y;
			else
				return z;
	}
	/*
	static int[][] matrix;
	static boolean[][] visited;
	public static int brute(int i, int j){
		if(i==matrix.length || j==matrix[0].length)
			return 0;
		//if(visited[i][j]) 
			//return matrix[i][j];
		visited[i][j] = true;
		int x=0,y=0,z=0;
		if(j>0) x = brute(i+1,j-1);
		y = brute(i+1,j);
		if(j<matrix[0].length) z = brute(i+1,j+1);
		return matrix[i][j] + Math.max(x, Math.max(y,z));
	}
	*/
}

/*
1
30 30
1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10
10 9 8 7 6 5 4 3 2 1 10 9 8 7 6 5 4 3 2 1 10 9 8 7 6 5 4 3 2 1
1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10
10 9 8 7 6 5 4 3 2 1 10 9 8 7 6 5 4 3 2 1 10 9 8 7 6 5 4 3 2 1
1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10
10 9 8 7 6 5 4 3 2 1 10 9 8 7 6 5 4 3 2 1 10 9 8 7 6 5 4 3 2 1
1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10
10 9 8 7 6 5 4 3 2 1 10 9 8 7 6 5 4 3 2 1 10 9 8 7 6 5 4 3 2 1
1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10
10 9 8 7 6 5 4 3 2 1 10 9 8 7 6 5 4 3 2 1 10 9 8 7 6 5 4 3 2 1
1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10
10 9 8 7 6 5 4 3 2 1 10 9 8 7 6 5 4 3 2 1 10 9 8 7 6 5 4 3 2 1
1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10
10 9 8 7 6 5 4 3 2 1 10 9 8 7 6 5 4 3 2 1 10 9 8 7 6 5 4 3 2 1
1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10
10 9 8 7 6 5 4 3 2 1 10 9 8 7 6 5 4 3 2 1 10 9 8 7 6 5 4 3 2 1
1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10
10 9 8 7 6 5 4 3 2 1 10 9 8 7 6 5 4 3 2 1 10 9 8 7 6 5 4 3 2 1
1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10
10 9 8 7 6 5 4 3 2 1 10 9 8 7 6 5 4 3 2 1 10 9 8 7 6 5 4 3 2 1
1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10
10 9 8 7 6 5 4 3 2 1 10 9 8 7 6 5 4 3 2 1 10 9 8 7 6 5 4 3 2 1
1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10
10 9 8 7 6 5 4 3 2 1 10 9 8 7 6 5 4 3 2 1 10 9 8 7 6 5 4 3 2 1
1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10
10 9 8 7 6 5 4 3 2 1 10 9 8 7 6 5 4 3 2 1 10 9 8 7 6 5 4 3 2 1
1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10
10 9 8 7 6 5 4 3 2 1 10 9 8 7 6 5 4 3 2 1 10 9 8 7 6 5 4 3 2 1
1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10 1 2 3 4 5 6 7 8 9 10
10 9 8 7 6 5 4 3 2 1 10 9 8 7 6 5 4 3 2 1 10 9 8 7 6 5 4 3 2 1
300
*/


/*


*/