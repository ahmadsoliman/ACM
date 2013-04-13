package topCoder;

public class Marathon250Div1 {
	public static void main(String[] args) {
		System.out.println(cardsLeft("KKKKKAQT23"));
		;
	}

	// 145
	public static int[] getDivision(int[] points) {
		int sum = 0;
		for (int i = 0; i < points.length; i++) {
			sum += points[i];
		}
		int[] perc = new int[points.length];
		int sumPerc = 0;
		for (int i = 0; i < perc.length; i++) {
			perc[i] = (int) ((double) points[i] / (double) sum * 100.0);
			sumPerc += perc[i];
		}
		int leftover = 100 - sumPerc;
		System.out.println(leftover);
		for (int i = 0; i < leftover; i++) {
			int max = maxIndex(points);
			perc[max] += 1;
			points[max] = 0;
		}
		return perc;
	}

	public static int maxIndex(int[] a) {
		int max = a[0], k = 0;
		for (int i = 1; i < a.length; i++) {
			if (a[i] > max) {
				max = a[i];
				k = i;
			}
		}
		return k;
	}

	// 146
	public static long countRectangles(int width, int height) {
		long count = 0l;
		for (int i = 1; i <= height; i++) {
			for (int j = 1; j <= width; j++) {
				if (i == j)
					continue;
				int deltax = width - j + 1;
				int deltay = height - i + 1;
				count += deltax * deltay;
			}
		}
		return count;
	}

	// 147 -- Failed
	public static String order(int numMales, int numFemales, int K) {
		int total = numFemales + numMales;
		StringBuffer res = new StringBuffer();
		boolean[] fem = new boolean[total];
		int j = K;
		int lastFem = j;
		while (numFemales > 0) {
			if (j % K == 0) {
				for (int i = lastFem + 1; i < j % total - 1; i++) {
					if (fem[i])
						j++;
				}
				if (j % total == 0) {
					fem[total - 1] = true;
					lastFem = total - 1;
				} else {
					fem[j % total - 1] = true;
					lastFem = j % total - 1;
				}
				numFemales--;
			}
			j++;
		}
		for (int i = 0; i < fem.length; i++) {
			if (fem[i])
				res.append('F');
			else
				res.append('M');
		}
		return res.toString();
	}

	// 148
	public static int cardsLeft(String deck) {
		int loop = deck.length() + 1;
		StringBuffer myDeck = new StringBuffer(deck);

		while (loop > 0) {
			loop--;
			for (int i = 0; i < myDeck.length(); i++) {
				boolean first = false;
				char c1 = myDeck.charAt(i), c2 = '.';
				if (i != myDeck.length() - 1) {
					c2 = myDeck.charAt(i + 1);
				} else {
					if (i != 0) {
						first = true;
						c2 = myDeck.charAt(0);
					}
				}
				if (c1 == 'K') {
					myDeck.replace(i, i + 1, "");
					loop = deck.length() + 1;
					continue;
				}
				int ic1 = 0, ic2 = -1;
				if (c1 >= '1' && c1 <= '9') {
					ic1 = Integer.parseInt(c1 + "");
				}
				if (c2 >= '1' && c2 <= '9') {
					ic2 = Integer.parseInt(c2 + "");
				}
				switch (c1) {
				case 'A':
					ic1 = 1;
					break;
				case 'T':
					ic1 = 10;
					break;
				case 'J':
					ic1 = 11;
					break;
				case 'Q':
					ic1 = 12;
					break;
				case 'K':
					ic1 = 13;
					break;
				default:
					break;
				}
				switch (c2) {
				case 'A':
					ic2 = 1;
					break;
				case 'T':
					ic2 = 10;
					break;
				case 'J':
					ic2 = 11;
					break;
				case 'Q':
					ic2 = 12;
					break;
				case 'K':
					ic2 = 13;
					break;
				default:
					break;
				}
				if (ic1 + ic2 == 13) {
					myDeck.replace(i, i + 2, "");
					if (first)
						myDeck.replace(0, 1, "");
					loop = deck.length() + 1;
				}
				System.out.println(myDeck);
			}
		}
		return myDeck.length();
	}

	// 149
	public static int maxWait(int[] arrival, int[] service) {
		int max = 0;
		for (int i = 0; i < arrival.length; i++) {
			if (i != 0) {
				int wait = arrival[i - 1] - arrival[i];
				if (wait > 0) {
					if(wait > max) max = wait;
					arrival[i] = arrival[i - 1] + service[i];
				}else
					arrival[i] += service[i];
			} else
				arrival[i] += service[i];
		}
		return max;
	}
	//150
//	public static {
//		
//	}
}











