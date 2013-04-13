package UVA;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class LargestSubmatrix {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		
		String[] map = new String[26];
		String in;
		int M,N, maxArea, area;
		
		boolean[][][][] dp=new boolean[26][26][26][26];
	    for(int i=0; i<26; i++){
            for(int k=0; k<26; k++){
                for(int j=0; j<26; j++){
                    for(int l=0; l<26; l++){
                        dp[i][k][j][l]= true;
                    }
                }
            }
        }
	    
		br.readLine();
		for (int r = 0; r < t; r++) {
			M=0;
			while(!(in=br.readLine()).equals("")){
				map[M++]=in;
			}
			
			N=map[0].length();
			maxArea=0;
	        for(int i=1; i<=M; i++){
	            for(int k=0; k<i; k++){
	                for(int j=1; j<=N; j++){
	                    for(int l=0; l<j; l++){
	                        dp[i][k][j][l] = dp[i-1][k][j][l] && dp[i][k][j-1][l] && map[i-1].charAt(j-1)=='1';
	                        if(dp[i][k][j][l]){
		                        area = (i-k)*(j-l);
		                        if(area>maxArea)
		                            maxArea=area;
	                        }
	                    }
	                }
	            }
	        }
	        System.out.println(maxArea);
	        if(r<t-1)
	        	System.out.println();
		}
		
	}
}
