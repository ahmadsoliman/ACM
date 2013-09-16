package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class FASHION {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(br.readLine()), n;
		long sum;
		
		int[] nl1, nl2;
		
		StringTokenizer l1,l2;
		for (int i = 0; i < t; i++) {
			sum = 0;
			n = Integer.parseInt(br.readLine());
			nl1 = new int[n];
			nl2 = new int[n];
			l1 = new StringTokenizer(br.readLine());
			l2 = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				nl1[j] = Integer.parseInt(l1.nextToken());
				nl2[j] = Integer.parseInt(l2.nextToken());
			}
			Arrays.sort(nl1);
			Arrays.sort(nl2);
			for (int j = 0; j < n; j++) {
				sum+=nl1[j]*nl2[j];
			}
			System.out.println(sum);
		}
	}
}
