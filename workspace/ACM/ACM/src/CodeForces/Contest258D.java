package CodeForces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Contest258D {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		int p = Integer.parseInt(br.readLine());
		
		Arrays.sort(arr);
		int count=0;
		for (int i = 0; i < args.length; i++) {
			count+=solve(i,p);
		}
		System.out.println(count);
	}
	static int[] arr;
	public static int solve(int i, int l){
		if(l-arr[i]<0){
			return arr.length-i;
		}
		
		int count = 0;
		for (int j = 0; j < arr.length; j++) {
			count+=solve(j,l-arr[i]);
		}
		
		return 0;
	}
} 