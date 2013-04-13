package CodeForces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Contest257D {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
	
		list=new int[n];
		for (int i = 0; i < n; i++) {
			list[i]=Integer.parseInt(st.nextToken());
		}
	}
	static int[] list;
	static int[][] dp;
	public static void recur(){
		
	}
}
