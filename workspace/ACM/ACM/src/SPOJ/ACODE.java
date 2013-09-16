package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class ACODE {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String in = br.readLine();
		char [] chars;
		int[] dp;
		int len;
		while(!in.equals("0")){
			chars = in.toCharArray();
			len = chars.length;
			dp = new int[len+1];
			dp[0] = 1;
			dp[1] = 1;
			
			for (int i = 2; i <= len; i++) {
				if(chars[i-1]=='0')
					dp[i] = dp[i-2];
				else if(chars[i-2]=='0')
					dp[i] = dp[i-1];
				else if((chars[i-1]-'0') + (chars[i-2]-'0')*10 > 26)
					dp[i] = dp[i-1];
				else
					dp[i] = dp[i-2]+dp[i-1];
			}

			//System.out.println(Arrays.toString(dp));
			System.out.println(dp[len]);
			
			in = br.readLine();
		}
	}
}
