package topCoder;

import java.awt.Rectangle;
import java.util.ArrayList;
import java.util.Arrays;

public class SRM493Div2 {
	public static void main(String[] args) {
		// System.out.println(count(new String[] { "AA", "AA", "AA" }, 2));
		// System.out.println(winner(5, 5, 2, 3));

	}

	// SRM 360 Div2 500
	public static int winningMove(int n) {
		String str = n + "";
		String[] a = str.split("");
//		ArrayList<Integer> combs = backtrack(new boolean[str.length()], 0 ,str.length());
		
		return 0;
	}

	// BACKTRACKING
//	static boolean finished = false; /* found all solutions yet? */
//
//	public static ArrayList<Integer> backtrack(String[] a, int k, int n) {
//		if (is_a_solution(a, k, n)){
//			ArrayList<Integer> res = new ArrayList<Integer>();
//			for(int i=0; i<a.length; i++) res.add(Integer.parseInt(a[i]));
//			return res;
//		}
//		else {
//			k = k + 1;
//			boolean c[] = construct_candidates();
//			for (int i = 0; i < c.length; i++) {
//				a[k] = c[i];
////				backtrack(a, k);
//				if (finished)
//					return a; /* terminate early */
//			}
//		}
//	}
//
//	public static boolean is_a_solution(String[] a, int k, int n) {
//		return (k == n); /* is k == n? */
////		return true;
//	}
//
//	public static boolean[] construct_candidates() {
//		boolean[] c = new boolean[2];
//		c[0] = true;
//		c[1] = false;
//		return c;
//	}

//	public static void process_solution(String[] a, int k) {
//		int i; /* counter */
//		printf("{");
//		for (i = 1; i <= k; i++)
//			if (a[i] == TRUE)
//				printf(" %d", i);
//		printf(" }\n");
//	}
//END OF BACKTRACKING
	
	
	// SRM 360 Div2 500
	public static String hypothesis(String[] table) {
		int n = table.length, m = table[0].length();
		int[][] board = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				board[i][j] = Integer.parseInt(Character.toString(table[i]
						.charAt(j)));
			}
		}
		for (int i = 0; i < m; i++) {
			ArrayList<Integer> visited = new ArrayList<Integer>();
			visited.add(new Integer(i));
			// recure(board, );
		}
		return "CORRECT";
	}

	// 1000
	public static int count(int[] x, int[] y, int A, int T) {

		Rectangle wide = findBest(A + T);
		Rectangle narrow = findBest(A);

		// moveNearest(wide, T);
		// destroy(narrow);

		return 0;
	}

	public static Rectangle findBest(int a) {

		return new Rectangle();
	}

	// 250
	public static int count(String[] table, int K) {
		int n = table.length, m = table[0].length();
		int count = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (table[i].charAt(j) == 'M')
					continue;
				for (int k = 0; k <= K; k++) {
					if (k + j >= m)
						break;
					if (table[i].charAt(k + j) == 'M')
						break;
					if (k == K - 1)
						count++;
				}
				if (K == 1)
					continue;
				for (int k = 0; k <= K; k++) {
					if (k + i >= n)
						break;
					if (table[k + i].charAt(j) == 'M')
						break;
					if (k == K - 1)
						count++;
				}
			}
		}
		return count;
	}

	// 500
	static boolean[] visited;

	public static String winner(int N, int M, int K, int L) {
		boolean[] board = new boolean[N];
		M--;
		L--;
		board[M] = true;
		visited = Arrays.copyOf(board, board.length);

		int x = findWin(board, K, L, 1);
		if (x == 0)
			return "Draw";
		if (x == 1)
			return "Romeo";
		return "Strangelet";
	}

	public static int findWin(boolean[] board, int K, int L, int turn) {
		if (K == 1)
			return 0;
		ArrayList<Integer> results = new ArrayList<Integer>();
		for (int i = 0; i < 2 * K; i++) {
			boolean[] board1 = Arrays.copyOf(board, board.length);
			;
			int x = findWhite(board1) - K + 1 + i;
			if (x >= 0 && x + K - 1 < board.length)
				swap(board1, x, x + K - 1);
			else
				continue;
			int w = findWhite(board1);
			if (visited[w])
				return 0;
			else
				visited[w] = true;
			if (w == L)
				results.add(turn);
			results.add(findWin(board1, K, L, (turn == 0) ? 2 : 1));
		}
		boolean romeo = true, strange = true;

		for (int i = 0; i < results.size(); i++) {
			if (results.get(i) == 1)
				strange = false;
			if (results.get(i) == 2)
				romeo = false;
			if (results.get(i) == 0)
				return 0;
		}
		if (romeo)
			return 1;
		if (strange)
			return 2;
		return 0;
	}

	public static boolean[] swap(boolean[] board, int i, int j) {
		for (int k = i; k < j; k++) {
			boolean tmp = board[k];
			board[k] = board[j];
			board[j] = tmp;
			j--;
		}
		return board;
	}

	public static int findWhite(boolean[] board) {
		for (int i = 0; i < board.length; i++) {
			if (board[i])
				return i;
		}
		return -1;
	}

}
