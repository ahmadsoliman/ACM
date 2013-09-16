package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class SAMER08D {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String in = br.readLine();
		int k;
		while(!in.equals("0")){
			k = Integer.parseInt(in);
			StringBuffer s1 = new StringBuffer(br.readLine()), s2 = new StringBuffer(br.readLine());
			
			int m = s1.length(), n=s2.length();
			
	        // opt[i][j] = length of LCS of x[i..M] and y[j..N]
			int[][] dp = new int [m+1][n+1];
			
	        // compute length of LCS and all subproblems via dynamic programming
			for (int i = m-1; i>=0; i--) {
				for (int j = n-1; j>=0; j--) {
					if(s1.charAt(i)==s2.charAt(j))
						dp[i][j] = dp[i+1][j+1] + 1;
					else
						dp[i][j] = Math.max(dp[i][j+1], dp[i+1][j]);
				}
			}
			
	        // recover LCS itself
			StringBuffer lcs;
			int i, j , kCount, maxLCS=0, len;
			boolean failed;
			
			// loop for m
			for (int l = 0; l < m; l++) {
				lcs = new StringBuffer();
				i = l; j = 0;
				while(i<m&&j<n)
					if(s1.charAt(i)==s2.charAt(j)){
						lcs.append(s1.charAt(i));
						i++;
						j++;
					}else if(dp[i+1][j] >= dp[i][j+1])
						i++;
					else
						j++;
				
				failed = false;
				//inner loop for m
				i = 0; j = 0; kCount = 0;
				len = lcs.length();
				if(len<maxLCS)
					break;
				while(i<m&&j<len)
					if(s1.charAt(i)==lcs.charAt(j)){
						i++;
						j++;
						kCount++;
					}else{
						i++;
						if(kCount>0 && kCount<k){
							failed = true;
							break;
						}
						kCount=0;
					}
				if(kCount>0 && kCount<k)
					failed = true;
				
				
				// inner loop for n
				i = 0; j = 0; kCount = 0;
				while(i<n&&j<len)
					if(s2.charAt(i)==lcs.charAt(j)){
						i++;
						j++;
						kCount++;
					}else{
						i++;
						if(kCount>0 && kCount<k){
							failed = true;
							break;
						}
						kCount=0;
					}
				if(!(kCount>0 && kCount<k) && !failed && len>maxLCS)
					maxLCS = lcs.length();
			}
			
			// loop for n
			for (int l = 0; l < n; l++) {
				lcs = new StringBuffer();
				i = 0; j = l;
				while(i<m&&j<n)
					if(s1.charAt(i)==s2.charAt(j)){
						lcs.append(s1.charAt(i));
						i++;
						j++;
					}else if(dp[i+1][j] >= dp[i][j+1])
						i++;
					else
						j++;
				
				failed = false;
				//inner loop for m
				i = 0; j = 0; kCount = 0;
				len = lcs.length();
				if(len<maxLCS)
					break;
				while(i<m&&j<len)
					if(s1.charAt(i)==lcs.charAt(j)){
						i++;
						j++;
						kCount++;
					}else{
						i++;
						if(kCount>0 && kCount<k){
							failed = true;
							break;
						}
						kCount=0;
					}
				if(kCount>0 && kCount<k)
					failed = true;
				
				
				// inner loop for n
				i = 0; j = 0; kCount = 0;
				while(i<n&&j<len)
					if(s2.charAt(i)==lcs.charAt(j)){
						i++;
						j++;
						kCount++;
					}else{
						i++;
						if(kCount>0 && kCount<k){
							failed = true;
							break;
						}
						kCount=0;
					}
				if(!(kCount>0 && kCount<k) && !failed && len>maxLCS)
					maxLCS = lcs.length();
			}			
			
			System.out.println(maxLCS);
			
			in = br.readLine();
		}
	}

}