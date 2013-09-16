package CodeForces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Contest258B {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken()) , k = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(br.readLine());
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		int i =0;
		while(i<n  && arr[i]<0 && k>0){
			arr[i++]*=-1;
			k--;
		}
		if(i<n && arr[i]==0){
			k=0;
		}
		Arrays.sort(arr);
		if(k>0&&k%2==1){
			arr[0]*=-1;
		}
		int sum=0;
		for (int j = 0; j < n; j++) {
			sum+=arr[j];
		}
		System.out.println(sum);
	}
}
