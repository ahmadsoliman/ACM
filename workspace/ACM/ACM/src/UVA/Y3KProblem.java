package UVA;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.GregorianCalendar;
import java.util.StringTokenizer;

public class Y3KProblem {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int n, d, m, y;
		StringTokenizer st;
		GregorianCalendar date;
		while (true) {
			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			d = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			y = Integer.parseInt(st.nextToken());

			if (n == 0 && d == 0 && m == 0 && y == 0)
				break;
			date = new GregorianCalendar(y, m-1, d);
			date.add(GregorianCalendar.DATE, n);

			System.out.println(date.get(GregorianCalendar.DAY_OF_MONTH) + " "
					+ (date.get(GregorianCalendar.MONTH)+1) + " "
					+ date.get(GregorianCalendar.YEAR));

		}

	}
}
