package topCoder;

import java.awt.Rectangle;
import java.util.ArrayList;

public class TCH63 {
	public static void main(String[] args) {
		System.out.println(whereIsMistake(new String[] { "xy yx 3:2",
				"xx yy 1:1" }, "yx"));
	}

	// 250
	public static int whoIsTheWinner(int[] points) {
		int max = -1, j = -1;
		boolean rep = false;
		for (int i = 0; i < points.length; i++) {
			if (points[i] == max)
				rep = true;
			if (points[i] > max && points[i] <= 21) {
				j = i;
				max = points[i];
				rep = false;
			}
		}
		if (rep)
			return -1;
		return j;
	}

	// 600
	public static int doNotTellTheTruth(int n, int[] a, String[] parties) {
		int exag = 0;
		boolean[] know = new boolean[n + 1];
		boolean[] exagParties = new boolean[parties.length];
		for (int i = 0; i < a.length; i++) {
			know[a[i]] = true;
		}
		for (int i = 0; i < parties.length; i++) {
			String[] str = parties[i].split(" ");
			boolean aman = true;
			for (int j = 0; j < str.length; j++) {
				int x = Integer.parseInt(str[j]);
				if (know[x]) {
					aman = false;
					break;
				}
			}
			if (aman) {
				exagParties[i] = true;
				exag++;
			} else {
				for (int j = 0; j < str.length; j++) {
					int x = Integer.parseInt(str[j]);
					know[x] = true;
				}
			}
		}
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < parties.length; i++) {
				String[] str = parties[i].split(" ");
				for (int j = 0; j < str.length; j++) {
					int x = Integer.parseInt(str[j]);
					if (know[x] && exagParties[i]) {
						exagParties[i] = false;
						exag--;
						break;
					}
				}
			}
		}
		return exag;
	}

	// 1000
	public static int whereIsMistake(String[] results, String winner) {
		Rectangle[] scores = new Rectangle[results.length];
		int[] points = new int[results.length * 2];
		ArrayList<String> names = new ArrayList<String>();
		int n = 0;
		for (int i = 0; i < results.length; i++) {
			String[] str = results[i].split(" ");
			String[] score = str[2].split(":");
			int i1 = 0, i2 = 0;
			if (!names.contains(str[0])) {
				names.add(str[0]);
				i1 = n;
				n++;
			} else {
				i1 = names.indexOf(str[0]);
			}
			if (!names.contains(str[1])) {
				names.add(str[1]);
				i2 = n;
				n++;
			} else {
				i2 = names.indexOf(str[1]);
			}
			int s1 = Integer.parseInt(score[0]), s2 = Integer
					.parseInt(score[1]);
			scores[i] = new Rectangle(s1, s2, i1, i2);
			if (s1 == s2) {
				points[i1]++;
				points[i2]++;
			} else if (s1 > s2) {
				points[i1] += 3;
			} else {
				points[i2] += 3;
			}
		}

		int max = -1, j = -1;
		boolean rep = false;
		for (int i = 0; i < n; i++) {
			if (points[i] == max)
				rep = true;
			if (points[i] > max) {
				max = points[i];
				j = i;
				rep = false;
			}
		}

		int iWin = names.indexOf(winner);
		if (!rep && j == iWin)
			return -2;

		int max2 = -1, j2 = -1;
		for (int i = 0; i < n; i++) {
			if (rep && points[i] == max2 && j != i) {
				max2 = points[i];
				j2 = i;
			}
			if (points[i] > max2) {
				max2 = points[i];
				j2 = i;
			}
		}

		if (iWin == j2 && max - max2 >= 3)
			return -1;
		if (iWin != j2 && iWin != j)
			return -1;

		for (int i = 0; i < scores.length; i++) {
			if (iWin != scores[i].width && iWin != scores[i].height)
				continue;
			if (scores[i].x == scores[i].y && max - max2 >= 2)
				continue;
			boolean player1 = true;
			if (iWin == scores[i].height)
				player1 = false;
			if (player1 && scores[i].x <= scores[i].y) {
				return i;
			} else if (!player1 && scores[i].x >= scores[i].y) {
				return i;
			}
		}
		return -1;
	}
}
