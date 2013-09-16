package topCoder;

import java.util.Arrays;

public class SRM423D2 {
	public static void main(String[] args) {
		//System.out.println(Arrays.toString(count(new int[] { 4, 4 }, new int[] {7, 7 })));
		System.out.println(getmin("1111101"));
	}

	// 250
	public static int count(int n, int[] x, int[] y) {
		int moves = 0;
		for (int i = 0; i < n; i++) {
			int a = x[i], b = y[i];
			if (a == 1) {
				if (b == 1 || b == n)
					continue;
			} else if (a == n) {
				if (b == 1 || b == n)
					continue;
			}
			int deltay = Math.min(a - 1, n - a);
			int deltax = Math.min(b - 1, n - b);
			moves += deltay + deltax;
		}
		return moves;
	}

	// 600
	public static int[] count(int[] x, int[] y) {
		if (x.length == 0)
			return new int[] {};
		StringBuffer strX = new StringBuffer(), strY = new StringBuffer();
		int n = x.length;
		int minX = x[0], maxX = x[0], minY = y[0], maxY = y[0];
		for (int i = 1; i < n; i++) {
			strX.append(x[i] + " ");
			strY.append(y[i] + " ");
			if (x[i] < minX)
				minX = x[i];
			if (x[i] > maxX)
				maxX = x[i];
			if (y[i] < minY)
				minY = y[i];
			if (y[i] > maxY)
				maxY = y[i];
		}
		int meanX = (minX + maxX) / 2 - 1;
		int meanY = (minY + maxY) / 2 - 1;
		int[] res = new int[n];
		res[0] = 0;
		for (int k = 1; k < n; k++) {
			int minMoves = 1000000;
			for (int i = meanX; i <= maxX; i++) {
				for (int j = meanY; j <= maxY; j++) {
					// if(strX.indexOf(i+"")!=strY.indexOf(j+"")) continue;
					if (strX.indexOf(i + "") == -1
							|| strX.indexOf(i + "") == -1)
						continue;
					int cur = recur(x, y, i, j, k + 1);
					if (cur < minMoves)
						minMoves = cur;
				}
			}
			res[k] = minMoves;
		}
		return res;
	}

	public static int recur(int[] x, int[] y, int i, int j, int k) {
		if (k <= 0)
			return 0;
		if (x.length == 0)
			return 10000000;
		int deltax = Math.abs(x[0] - i), deltay = Math.abs(y[0] - j);

		int[] x1 = new int[x.length - 1], y1 = new int[x.length - 1];
		for (int h = 0; h < x.length - 1; h++) {
			x1[h] = x[h + 1];
			y1[h] = y[h + 1];
		}

		int sol1 = recur(x1, y1, i, j, k - 1) + deltax + deltay;
		int sol2 = recur(x1, y1, i, j, k);

		return Math.min(sol1, sol2);
	}

	// SRM 555, 250
	public static int theMax(String[] board) {
		int max = 0;
		int n = board.length, m = board[0].length();
		boolean[][] bolBoard = new boolean[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				bolBoard[i][j] = (board[i].charAt(j) == '1');
				System.out.print(board[i].charAt(j));
			}
			System.out.println();
		}

		for (int i = 0; i < n; i++) {
			boolean[][] boardCopy1 = deepCopy(bolBoard);
			for (int j = 0; j < m; j++) {
				boardCopy1[i][j] = !boardCopy1[i][j];
			}
			for (int j = 0; j < m; j++) {
				boolean[][] boardCopy2 = deepCopy(boardCopy1);
				for (int j2 = 0; j2 < n; j2++) {
					boardCopy2[j2][j] = !boardCopy2[j2][j];
				}
				int count = 0;
				for (int k = 0; k < n; k++) {
					for (int k2 = 0; k2 < m; k2++) {
						if (boardCopy2[k][k2])
							count++;
					}
				}
				max = Math.max(max, count);
			}
		}
		return max;
	}

	public static boolean[][] deepCopy(boolean[][] arr) {
		boolean[][] res = new boolean[arr.length][arr[0].length];
		for (int i = 0; i < res.length; i++) {
			res[i] = (boolean[]) arr[i].clone();
		}
		return res;
	}

	// SRM 555, 500
	public static int getmin(String S) {
		return recur(S);
	}

	public static int recur(String S) {
		if (S==null || S.length()==0) {
			return 0;
		}
		long num = Long.parseLong(S, 2);
		for (long i = num; i > 0; i--) {
			if ((Math.log(i) % Math.log(5))==0) {
				String lookFor = Long.toBinaryString(i);
				int x = S.indexOf(lookFor);
				if (x != -1){
					System.out.println(lookFor);
					int left = recur(S.substring(0, x));
					if (left==-1)
						continue; 
					int right = recur(S.substring(x + lookFor.length(), S.length()));
					if (right!=-1) {
						return 1 + left + right;
					}
				}
			}
		}
		return -1;
	}
}
