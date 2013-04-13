package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class SAMER08F {
	public static void main(String[] args) throws NumberFormatException, IOException {
		int[] pre = new int[101];
		for (int i = 1; i < pre.length; i++) {
			pre[i] = pre[i-1] + i*i;
		}
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int in = Integer.parseInt(br.readLine());
		while(in>0){
			System.out.println(pre[in]);
			in = Integer.parseInt(br.readLine());
		}
	}
}



