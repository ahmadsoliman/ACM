package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

//5295. Adjacent Bit Counts
public class GNYR09F {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int P =	Integer.parseInt(br.readLine());
		StringTokenizer sT;
		int caseNum, n,k;
		int dp[][];
		for (int i = 0; i < P; i++) {
			sT = new StringTokenizer(br.readLine());
			caseNum = Integer.parseInt(sT.nextToken());
			n = Integer.parseInt(sT.nextToken());
			k = Integer.parseInt(sT.nextToken());
			
			//brute force
			System.out.println(caseNum + " " + brute(0, n, k));
			
			//dp
			dp = new int[n+1][n+1];
			for (int j = n; j >= 0; j--) {
				for (int j2 = j; j2 >= 0; j2--) {
					
				}
			}
		}
	}
	
	public static int brute(int lastChar, int n, int k){
		if(k==0&&n==0)
			return 1;
		if(n==0)
			return 0;
		int res = brute(0, n-1, k);
		if(lastChar==0)
			res += brute(1, n-1, k);
		else
			res += brute(1, n-1, k-1);
		return res;
	}
}
