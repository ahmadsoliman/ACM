package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class VISION {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		
		int[] arr = new int[n]; 
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		int m = Integer.parseInt(br.readLine());
		int h=0, count, j, max;
		for (int i = 0; i < m; i++) {
			h = Integer.parseInt(br.readLine());
			
			count = 0; j = 0; max = 0;
			while(j<n){
				if(h<max)
				count ++;
				
				j++;
			}
		}
	}

}

