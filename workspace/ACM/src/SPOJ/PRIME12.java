package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class PRIME12 {
	public static void main(String[] args) throws
			IOException {
		BufferedReader stdin = new BufferedReader(new InputStreamReader(
				System.in));

		int t = Integer.parseInt(stdin.readLine());
		int[] m = new int[t], n = new int[t];
		StringBuffer res = new StringBuffer();
		int higherLimit = 0;
		int max = 0;

		for (int i = 0; i < t; i++) {
			String[] str = (stdin.readLine()).split(" ");
			m[i] = Integer.parseInt(str[0]);
			n[i] = Integer.parseInt(str[1]);
			int cur = ((int) Math.sqrt(n[i])) + 1;
			if (cur > higherLimit)
				higherLimit = cur;
			if (n[i] > max)
				max = n[i];
		}
		max++;
		int levels=1;
		if(max>10000000) levels = 10;
		if(max>100000000) levels = 100;
		int size = max/levels+1;
		boolean[][] arr = new boolean[levels][size];
		for (int i = 0; i < levels; i++) {
			Arrays.fill(arr[i], true);
		}
		
		arr[0][0] = false;
		arr[0][1] = false;
		
		for (int i = 2; i < higherLimit; i++) {
			if (!arr[i/size][i%size])
				continue;
			for (int j = 2; j * i < max; j++) {
				int cur = i*j;
				arr[cur/size][cur%size] = false;
			}
		}

		for (int i = 0; i < t; i++) {
			for (int j = m[i]; j <= n[i]; j++) {
				if (arr[j/size][j%size]) {
					res.append(j);
					res.append("\n");
				}
			}
			res.append("\n");
		}
		res.replace(res.length() - 1, res.length(), "");
		System.out.print(res.toString());
	}
}
