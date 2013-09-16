package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class IWGBS {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String in;
		int n;
		BigInteger dp[][] = new BigInteger[10005][2], zero=new BigInteger("0"), one=new BigInteger("1");
		dp[0][0]=zero;
		dp[0][1]=one;
		while((in=br.readLine())!=null){
			n = Integer.parseInt(in);
			for (int i = 1; i <= n; i++)
				for (int j = 0; j < 2; j++)
					dp[i][j] = dp[i-1][1].add((j!=0)?dp[i-1][0]:zero);
			System.out.println(dp[n][0].add(dp[n][1]));
		}
	}
}
