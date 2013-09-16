package UVA;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.GregorianCalendar;

public class CancerOrScorpio {
	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String in, name = "";
		int t = Integer.parseInt(br.readLine().trim()), kase = 1;
		GregorianCalendar date;
		while (t-- > 0) {
			in = br.readLine();
			date = new GregorianCalendar(Integer.parseInt(in.substring(4)
					.trim()), Integer.parseInt(in.substring(0, 2)) - 1,
					Integer.parseInt(in.substring(2, 4)));

			date.add(GregorianCalendar.DAY_OF_YEAR, 280);

			switch (date.get(GregorianCalendar.MONTH)) {
			case GregorianCalendar.JANUARY:
				if (date.get(GregorianCalendar.DAY_OF_MONTH) < 21)
					name = "capricorn";
				else
					name = "aquarius";
				break;
			case GregorianCalendar.FEBRUARY:
				if (date.get(GregorianCalendar.DAY_OF_MONTH) < 20)
					name = "aquarius";
				else
					name = "pisces";
				break;
			case GregorianCalendar.MARCH:
				if (date.get(GregorianCalendar.DAY_OF_MONTH) < 21)
					name = "pisces";
				else
					name = "aries";
				break;
			case GregorianCalendar.APRIL:
				if (date.get(GregorianCalendar.DAY_OF_MONTH) < 21)
					name = "aries";
				else
					name = "taurus";
				break;
			case GregorianCalendar.MAY:
				if (date.get(GregorianCalendar.DAY_OF_MONTH) < 22)
					name = "taurus";
				else
					name = "gemini";
				break;
			case GregorianCalendar.JUNE:
				if (date.get(GregorianCalendar.DAY_OF_MONTH) < 22)
					name = "gemini";
				else
					name = "cancer";
				break;
			case GregorianCalendar.JULY:
				if (date.get(GregorianCalendar.DAY_OF_MONTH) < 23)
					name = "cancer";
				else
					name = "leo";
				break;
			case GregorianCalendar.AUGUST:
				if (date.get(GregorianCalendar.DAY_OF_MONTH) < 22)
					name = "leo";
				else
					name = "virgo";
				break;
			case GregorianCalendar.SEPTEMBER:
				if (date.get(GregorianCalendar.DAY_OF_MONTH) < 24)
					name = "virgo";
				else
					name = "libra";
				break;
			case GregorianCalendar.OCTOBER:
				if (date.get(GregorianCalendar.DAY_OF_MONTH) < 24)
					name = "libra";
				else
					name = "scorpio";
				break;
			case GregorianCalendar.NOVEMBER:
				if (date.get(GregorianCalendar.DAY_OF_MONTH) < 23)
					name = "scorpio";
				else
					name = "sagittarius";
				break;
			case GregorianCalendar.DECEMBER:
				if (date.get(GregorianCalendar.DAY_OF_MONTH) < 23)
					name = "sagittarius";
				else
					name = "capricorn";
				break;
			default:
				throw new ArrayIndexOutOfBoundsException(""
						+ date.get(GregorianCalendar.MONTH));
			}
			System.out.println(kase++
					+ " "
					+ ((date.get(GregorianCalendar.MONTH) + 1) < 10 ? "0"
							+ (date.get(GregorianCalendar.MONTH) + 1) : (date
							.get(GregorianCalendar.MONTH) + 1)) + "/"
					+ (date.get(GregorianCalendar.DAY_OF_MONTH) < 10 ? "0"
							+ date.get(GregorianCalendar.DAY_OF_MONTH) : (date
							.get(GregorianCalendar.DAY_OF_MONTH))) + "/"
					+ date.get(GregorianCalendar.YEAR) + " " + name);
		}
	}
}
