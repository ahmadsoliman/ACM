package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class PRIME1 {
	public static void main(String[] args) throws NumberFormatException,
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

		int[] arr = new int[max];
		arr[0] = 2;

		for (int i = 0; i < t; i++) {
			if (2 >= m[i]) {
				res.append(2);
				res.append("\n");
			}
			int reached = 2;
			int size = 1;

			if (m[i] <= arr[size - 1]) {
				for (int j = 1; j < size; j++) {
					int cur = arr[j];
					if (cur > m[i])
						break;
					if (cur >= m[i]) {
						res.append(cur);
						res.append("\n");
						reached = cur;
						size++;
					}
				}
			}

			for (int j = reached + 1; j <= n[i]; j += 2) {
				boolean prime = true;
				int limit = ((int) Math.sqrt(j)) + 1;
				for (int j2 = 1; j2 < size; j2++) {
					int cur = arr[j2];
					if (cur > limit)
						break;
					if (j % cur == 0) {
						prime = false;
						break;
					}
				}
				if (prime) {
					if (j < higherLimit) {
						arr[size] = j;
						size++;
					}
					if (j >= m[i]) {
						res.append(j);
						res.append("\n");
						reached = j;
					}
				}
			}
			res.append("\n");
		}
		res.replace(res.length() - 1, res.length(), "");
		System.out.print(res.toString());
	}
}
