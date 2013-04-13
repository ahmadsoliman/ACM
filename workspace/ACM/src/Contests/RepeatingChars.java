package Contests;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class RepeatingChars {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		StringTokenizer sT;
		StringBuffer res;
		int caseNum , R;
		String S;
		for (int i = 0; i < t; i++) {
			sT = new StringTokenizer(br.readLine());
			caseNum = Integer.parseInt(sT.nextToken());
			R = Integer.parseInt(sT.nextToken());
			S = sT.nextToken();
			res = new StringBuffer();
			
			for (int j = 0; j < S.length(); j++) {
				char c = S.charAt(j);
				for (int j2 = 0; j2 < R; j2++) {
					res.append(c);
				}
			}
			System.out.println(caseNum + " " + res.toString());
		}
	}
}
