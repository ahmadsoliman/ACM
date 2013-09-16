package SPOJ;

import java.util.Arrays;

public class AssignAlgorithms {
	public static void main(String[] args) {
		System.out.println(getMaxAmount(new int[] { 424, 244, 128, 118, 574,
				454, 151, 560, 524, 280, 476, 371, 63, 571, 517, 184, 48, 477,
				587, 474, 547, 376, 304, 31, 284, 275, 124, 59, 160, 98, 148,
				415 }, 491, 891));
	}

	public static String getMaxAmount(int[] money, int m, int q) {
		days = money;
		C = q;

		dp = new int[money.length][q + 1];
		steps = new boolean[money.length][q + 1];
		for (int j = 0; j < money.length; j++) {
			Arrays.fill(dp[j], -1);
		}

		int max = recur(0, m);

		int maxJ = -1;
		StringBuffer res = new StringBuffer();
		res.append(max);
		res.append(",");
		for (int i = 0; i < dp.length; i++) {
			for (int j = 0; j < dp[0].length; j++) {
				if (dp[i][j] == max) {
					maxJ = j;
				}
			}
			if (steps[i][maxJ])
				res.append('+');
			else
				res.append('-');
		}
		return res.toString();
	}

	static int C;
	static int[] days;
	static int[][] dp;
	static boolean[][] steps;

	public static int recur(int i, int p) {
		if (i >= days.length)
			return p;
		if (dp[i][p] > -1)
			return dp[i][p];
		int a = -1, b = -1;
		if (p - days[i] >= 0)
			a = recur(i + 1, p - days[i]);
		if (p + days[i] <= C)
			b = recur(i + 1, p + days[i]);
		if (a >= b) {
			dp[i][p] = a;
		} else {
			dp[i][p] = b;
			steps[i][p] = true;
		}
		return dp[i][p];
	}
}
