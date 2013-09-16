package UVA;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class MaximumSubSequenceProduct {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String in;
		StringTokenizer st;
		int i, j, n, t;
		BigInteger cur, res, dp[][]=new BigInteger[101][101], nums[]=new BigInteger[101];
		while((in=br.readLine())!=null){
			st = new StringTokenizer(in);
			for(i=0; (t=Integer.parseInt(st.nextToken()))!=-999999; i++) nums[i]=new BigInteger(""+t);
			n = i;
			res=null;
			for(i=0; i<n; i++){
	            for(j=i; j<n; j++){
	                if(i==j)
	                    dp[i][j] = new BigInteger(nums[i].toString());
	                else
	                    dp[i][j] = dp[i][j-1].multiply(nums[j]);
	                if(res==null)
	                    res = dp[i][j];
	                else
	                	res = res.max(dp[i][j]);
	            }
	        }
			System.out.println(res.toString());
		}
	}
}
