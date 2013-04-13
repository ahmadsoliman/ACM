package CodeForces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Contest257A {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] in = br.readLine().split(" ");
		
		int n=Integer.parseInt(in[0]),m=Integer.parseInt(in[1]),k=Integer.parseInt(in[2]);
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int[] caps = new int[n];
		for (int i = 0; i < caps.length; i++) {
			caps[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(caps);
		
		int curSockets=k, neededLines=0;
		int i = n-1;
		while(curSockets<m && i>=0){
			curSockets+=caps[i]-1;
			neededLines++;
			i--;
		}
		if(curSockets>=m)
			System.out.println(neededLines);
		else
			System.out.println(-1);
	}
}
