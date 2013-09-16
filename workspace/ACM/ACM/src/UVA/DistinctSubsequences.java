package UVA;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class DistinctSubsequences {
	static BigInteger dp[][], one=new BigInteger("1"), zero= new BigInteger("0");
	static String a,b;
	
	static BigInteger recur(int i, int j){
		if(j==b.length())
			return one;
		if(i==a.length())
			return zero;
		
		if(dp[i][j]!=null)
			return dp[i][j];
		
		BigInteger res = recur(i+1,j);
		if(a.charAt(i)==b.charAt(j))
			res = res.add(recur(i+1,j+1));
		return dp[i][j] = res;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		
		while(t-->0){
			a = br.readLine();
			b = br.readLine();
			dp = new BigInteger[a.length()][b.length()];
			System.out.println(recur(0,0));
		}
	}
}
