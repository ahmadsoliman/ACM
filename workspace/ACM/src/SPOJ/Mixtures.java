package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Mixtures {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input;
		while((input=br.readLine())!=null){
			int n = Integer.parseInt(input);
			String[] mixtures = br.readLine().split(" ");
			
			int[][] colors=null, smoke=new int[n+1][n+1];
			
			
			for (int i = 1; i < smoke.length; i++) {
				for (int j = 1; j < smoke.length; j++) {
					//colors[i][j] = 
				}
			}
			
			int maxInt = Integer.MAX_VALUE-1000;
			for (int i = 0; i < smoke.length; i++)
				Arrays.fill(smoke[i],maxInt);
			
			smoke[n][n] = 0;
			for (int i = n-1; i >= 0; i--) {
				for (int j = n-1; j >= 0; j--) {
					Math.min(Math.min(smoke[i+1][j],smoke[i][j+1]),smoke[i+1][j+1]+colors[i][j]);
				}
			}
		}
	}
}
