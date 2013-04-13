package topCoder;

import java.awt.Point;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class TCH45 {
	public static void main(String[] args) {
		// BufferedReader stdin = new BufferedReader(new InputStreamReader(
		// System.in));
		// int a, b, c, w;
		// System.out.println(Integer.valueOf(solve(3,3,5,7))); 962340
		// System.out.println(Integer.valueOf(numberOfOperations1(962340)));
		// int[] x = {5, 5, 0};
		// System.out.println(wager(x, 4 , 0));
		// System.out.println(getPixelWidth("Hello World",
		// new int[] {7,8,8,8,7,8,8,8,7,8,8,8,8,8,7,8,8,8,8,8,7,8,8,8,8,8},
		// new int[] {5,6,6,6,5,6,6,6,5,6,6,6,6,6,5,6,6,6,6,6,5,6,6,6,6,6}));
		// calculate(new String[] { "BEARS", "GIANTS", "COWBOYS", "BRONCOS",
		// "DOLPHINS", "LIONS" }, new String[] { "-WLWW-", "L-WL-W",
		// "WL---W", "LW--L-", "L--W--", "-LL---" });

		System.out.println(longest(new String[] { "LL-L-", "L+L+L", "--NL-",
				"L+--L", "LL+L-" }));
	}

	public static int longest(String[] pipes) {
		int n = pipes[0].length(), m = pipes.length;
		char[][] grid = new char[n][m];
		Point center = null;
		int dir = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				grid[i][j] = pipes[i].charAt(j);
				if (grid[i][j] == 'N') {
					center = new Point(i, j);
					dir = 0;
				} else if (grid[i][j] == 'E') {
					center = new Point(i, j);
					dir = 1;
				} else if (grid[i][j] == 'S') {
					center = new Point(i, j);
					dir = 2;
				} else if (grid[i][j] == 'W') {
					center = new Point(i, j);
					dir = 3;
				}
			}
		}
		return flow(grid, new int[n][m], center.x, center.y, dir) - 1;
	}

	public static int flow(char[][] grid, int[][] used, int x, int y, int dir) {
		System.out.println(x + "" + y);

		// gayy lel + mn nafs l na7ya
		if (used[x][y] == 1 && grid[x][y] != '+')
			return 0;
		else if (used[x][y] == 2)
			return 0;
		used[x][y]++;
		
		if (dir == 0)
			x--;
		else if (dir == 1)
			y++;
		else if (dir == 2)
			x++;
		else if (dir == 3)
			y--;
		
		if (x < 0 || x >= grid.length || y < 0 || y >= grid[0].length)
			return 0;// out of limits
		
		
		int [][] used1 = new int[grid.length][grid[0].length];
		int [][] used2 = new int[grid.length][grid[0].length];
		for (int i = 0; i < grid.length; i++) {
			for (int j = 0; j < grid[0].length; j++) {
				used1[i][j]=used[i][j];
				used2[i][j]=used[i][j];
			}
		}
	
		if (grid[x][y] == '-' || grid[x][y] == '+'){
			return 1 + flow(grid, used1, x, y, dir);
		}
			
		if (grid[x][y] == 'L') {
			if (dir == 0 || dir == 2) {
				int e = flow(grid, used1, x, y, 1);
				int w = flow(grid, used2, x, y, 3);
				return 1 + Math.max(e, w);
			} else if (dir == 1 || dir == 3) {
				int n = flow(grid, used1, x, y, 0);
				int s = flow(grid, used2, x, y, 2);
				return 1 + Math.max(n, s);
			}
		}
		return 0;
	}

	public static String[] calculate(String[] teams, String[] results) {
		int N = teams.length;

		double[] records = new double[N];

		for (int i = 0; i < N; i++) {
			double wins = 0, losses = 0;
			for (int j = 0; j < N; j++) {
				if (i == j)
					continue;
				for (int k = 0; k < N; k++) {
					char c = results[j].charAt(k);
					if (c == '-' || k == i || results[j].charAt(i) == '-')
						continue;
					if (c == 'W')
						wins++;
					else if (c == 'L')
						losses++;
				}
			}
			records[i] = wins / (wins + losses);
		}
		String[] ranking = new String[N];
		for (int i = 0; i < N; i++) {
			int maxJ = 0;
			for (int j = 0; j < N; j++) {
				if (records[j] > records[maxJ]) {
					maxJ = j;
				} else if (records[j] == records[maxJ]) {
					if (teams[maxJ].compareTo(teams[j]) == 1) {
						maxJ = j;
					}
				}
			}
			records[maxJ] = -1;
			ranking[i] = teams[maxJ];
			System.out.println(ranking[i]);
		}
		return ranking;
	}

	public static int getPixelWidth(String sentence, int[] uppercase,
			int[] lowercase) {
		int width = 0;
		for (int i = 0; i < sentence.length(); i++) {
			char c = sentence.charAt(i);
			if (c == ' ') {
				width += 3;
			} else if (Character.isLowerCase(c)) {
				int k = (int) c - (int) 'a';
				width += lowercase[k];
			} else if (Character.isUpperCase(c)) {
				int k = (int) c - (int) 'A';
				width += uppercase[k];
			}
			if (i != sentence.length() - 1)
				width++;
		}
		return width;
	}

	public static int solve(int A, int B, int C, int W) {
		for (int i = 0; true; i++) {
			for (int j = 0; true; j++) {
				for (int k = 0; true; k++) {
					if (A * i + B * j + C * k == W)
						return i + j + k;
					if (A * i + B * j + C * k > W)
						break;
				}
				if (A * i + B * j > W)
					break;
			}
			if (A * i > W)
				break;
		}
		return -1;
	}

	public static int numberOfOperations1(int n) {
		if (n <= 1)
			return 0;
		int x = 1000, y = 1000, z = 1000;
		if ((n - 1) % 3 == 0)
			z = numberOfOperations1(n - 1) + 1;
		else {
			if (n % 3 == 0) {
				x = numberOfOperations1(n / 3) + 1;
			}
			if (n % 2 == 0) {
				y = numberOfOperations1(n / 2) + 1;
			}
		}
		return Math.min(Math.min(x, y), z);
	}

	public static int numberOfOperations(int n) {
		int count = 0;
		while (n > 1) {

		}
		return count;
	}

	public static String isValidUnfolding(String[] code) {
		StringBuffer str = new StringBuffer();
		for (int i = 0; i < code.length; i++) {
			str.append(code[i]);
		}

		return "";
	}

	// public static int wager(int[] scores, int wager1, int wager2) {
	// int p1 = scores[0], p2 = scores[1], p3 = scores[2];
	// if (p1 * 2 <= Math.max(p2 - wager1, p3 - wager2))
	// return 0;
	// if (p1 > Math.max(p2 + wager1, p3 + wager2))
	// return 0;
	// double p = 0;
	// int w = 0;
	// if(p1 < Math.max(p2 + wager1, p3 + wager2))
	// return w;
	// }

	public static int wager(int[] scores, int wager1, int wager2) {
		int p1 = scores[0], p2 = scores[1], p3 = scores[2];
		if (p1 * 2 <= Math.max(p2 - wager1, p3 - wager2))
			return -1;
		if (p1 > Math.max(p2 + wager1, p3 + wager2))
			return 0;
		// ArrayList<Integer> w = new ArrayList<Integer>();
		// ArrayList<Double> p = new ArrayList<Double>();
		int minW = p1;
		double maxP = 0;
		for (int i = 0; i <= p1; i++) {
			int score = p1 + i;

		}
		return minW;
	}
}
