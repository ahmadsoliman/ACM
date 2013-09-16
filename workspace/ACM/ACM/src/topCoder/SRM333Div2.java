package topCoder;

import java.util.Arrays;

public class SRM333Div2 {
	public static void main(String[] args) {
		findZeroSegment("1000", "10100", "5");
	}

	// 250
	public static String[] makeChessboard(int rows, int columns) {
		String[] res = new String[rows];
		boolean flip = false;
		for (int i = rows - 1; i >= 0; i--) {
			for (int j = 0; j < columns; j++) {
				if (j == 0)
					res[i] = "";
				if (flip) {
					if (j % 2 == 1)
						res[i] += ".";
					else
						res[i] += "X";
				} else {
					if (j % 2 == 0)
						res[i] += ".";
					else
						res[i] += "X";
				}
			}
			flip = !flip;
		}
		return res;
	}

	// 500 "YYMMDDCCCC"
	public static String[] validate(String[] test) {
		int n = test.length;
		String[] res = new String[n];

		for (int i = 0; i < n; i++) {
			int year, month, day;
			String cc;
			year = Integer.parseInt(test[i].substring(0, 2));
			month = Integer.parseInt(test[i].substring(2, 4));
			day = Integer.parseInt(test[i].substring(4, 6));
			cc = test[i].substring(6, 10);
			
			if (!((month >= 1 && month <= 12) || (month >= 51 && month <= 62))) {
				res[i] = "NO";
				continue;
			}

			if(year>=7) year+=1900;
			else year+=2000;
			
			boolean leap = false;
			if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
				leap = true;

			if (month == 2 && leap) {
				if ((day < 1 || day > 29)) {
					res[i] = "NO";
					continue;
				}
			} else if (month == 2 && !leap) {
				if ((day < 1 || day > 28)) {
					res[i] = "NO";
					continue;
				}
			} else if (month == 1 || month == 3 || month == 5 || month == 7
					|| month == 8 || month == 10 || month == 12) {
				if (!(day < 1 || day > 31)) {
					res[i] = "NO";
					continue;
				}
			} else {
				if (day < 1 || day > 30) {
					res[i] = "NO";
					continue;
				}
			}

			int sum = year + month + day + Integer.parseInt(cc);
			if (sum % 11 != 0) {
				res[i] = "NO";
				continue;
			}
			res[i] = "YES";
		}

		return res;
	}
	//1000
	public static long findZeroSegment(String P1, String P2, String zeroCount){
		long res = -1;
		long end = (long)Math.pow(10, 16);
		StringBuffer[] T = new StringBuffer[1000];
		int used = 0;
		
		for (int i = 1; T[used].length()<end; i++) {
			for (int j = 0; j < 1000000&&T[used].length()<end; j++) {
				T[used].append(P1);
			}
			for (int j = 0; j < i&&T[used].length()<end; j++) {
				T[used].append(P2);
			}
		}
		System.out.println(T);
		return res;
	}
	
}






