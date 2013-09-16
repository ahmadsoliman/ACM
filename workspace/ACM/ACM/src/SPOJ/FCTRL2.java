package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class FCTRL2 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		long[] pre = new long[102];
		pre[1]=1;
		for (int i = 2; i < pre.length; i++) {
			pre[i] = pre[i-1]*i;
		}
		System.out.println(Arrays.toString(pre));
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine()), n;
		for (int i = 0; i < pre.length; i++) {
			n = Integer.parseInt(br.readLine());
			System.out.println(pre[n]);
		}
	}
}
