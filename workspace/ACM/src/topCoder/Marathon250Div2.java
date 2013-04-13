package topCoder;

import java.util.Arrays;

public class Marathon250Div2 {
	public static void main(String[] args) {
	}

	// 144
	public static String whatTime(int seconds) {
		int hours = seconds / 3600;
		int minutes = (int) (((seconds / 3600.0) - hours) * 60);
		seconds = seconds - hours * 3600 - minutes * 60;
		return hours + ":" + minutes + ":" + seconds;
	}

	// 145
	public static int count(String dithered, String[] screen) {
		int count = 0;
		for (int i = 0; i < screen.length; i++) {
			for (int j = 0; j < screen.length; j++) {
				if (dithered.contains(screen[i].charAt(j) + ""))
					count++;
			}
		}
		return count;
	}

	// 146
	public static int maxPoints(int[] toss) {
		int maxScore = 0;
		for (int i = 0; i < toss.length; i++) {
			int score = 0;
			for (int j = 0; j < toss.length; j++) {
				if (toss[j] == i)
					score += i + 1;
			}
			if (score > maxScore)
				maxScore = score;
		}
		return maxScore;
	}

	// 147
	public static String decode(String cipherText, int shift) {
		StringBuffer res = new StringBuffer();
		for (int i = 0; i < cipherText.length(); i++) {
			char c = cipherText.charAt(i);
			c -= shift;
			while (c < 'A')
				c += 26;
			res.append(c);
		}
		return res.toString();
	}

	// 149
	public static String amount(int dollars, int cents) {
		String str = dollars + "";
		StringBuffer res = new StringBuffer();
		res.append("$");
		int j = str.length();
		for (int i = 0; i < str.length(); i++) {
			j--;
			if (j % 3 == 0 && i != str.length() - 1)
				res.append(",");
			res.append(str.charAt(i));
		}
		res.append(".");
		res.append(cents);
		if (cents / 10 < 1)
			res.append(0);
		return res.toString();
	}

	// 150
	public static int days(int[] arrivals, int numPerDay) {
		int count = 0;
		for (int i = 0; i < arrivals.length - 1; i++) {
			if (arrivals[i] == 0)
				continue;
			count++;
			arrivals[i] -= numPerDay;
			if (arrivals[i] <= 0)
				continue;
			arrivals[i + 1] += arrivals[i];
		}
		int rem = arrivals[arrivals.length - 1];
		while (rem > 0) {
			rem -= numPerDay;
			count++;
		}
		return count;
	}

	// 151
	public static String isOne(String[] words) {
		if (words.length <= 1)
			return "Yes";
		for (int i = 0; i < words.length; i++) {
			for (int j = 0; j < words.length; j++) {
				if (words[j].equals(words[i].substring(words[j].length())))
					return "No, " + j;
			}
		}
		return "Yes";
	}

	// 152
	public static double cycleRange(double R) {
		double x = 0.25;

		for (int i = 0; i < 200000; i++) {
			x = R * x * (1 - x);
		}
		double min = Integer.MAX_VALUE - 10, max = 0;
		for (int i = 0; i < 1000; i++) {
			x = R * x * (1 - x);
			if (x < min)
				min = x;
			if (x > max)
				max = x;
		}
		return max - min;
	}

	// 153
	public static String bestItem(int[] costs, int[] prices, int[] sales,
			String[] items) {
		int[] profits = new int[costs.length];
		int maxProfit = 0;
		String maxName = "";
		for (int i = 0; i < prices.length; i++) {
			profits[i] = (prices[i] - costs[i]) * sales[i];
			if (profits[i] > maxProfit) {
				maxProfit = profits[i];
				maxName = items[i];
			}
		}
		if (maxProfit < 0)
			return "";
		return maxName;
	}

	// 154
	public static int percent(String[] items) {
		double totalPrice = 0, totalcost = 0;
		for (int i = 0; i < items.length; i++) {
			String[] its = items[i].split(" ");
			totalPrice += Double.parseDouble(its[0]);
			totalcost += Double.parseDouble(its[1]);
		}
		return (int) Math.floor((totalPrice - totalcost) / totalPrice);
	}

	// 155
	public static int readKnots(String knots) {
		StringBuffer str = new StringBuffer();
		for (int i = 1; i < knots.length() - 1; i++) {
			if (knots.charAt(i) == '-' && knots.charAt(i + 1) == '-')
				str.append(0);
			if (knots.charAt(i) == '-')
				continue;
			int j = 0;
			while (knots.charAt(i) == 'X') {
				i++;
				j++;
			}
			str.append(j);
		}
		return Integer.parseInt(str.toString());
	}

	// 156
	public static int minDrives(int[] used, int[] total) {
		int[] free = new int[used.length];
		for (int i = 0; i < free.length; i++) {
			free[i] = total[i] - used[i];
		}

		for (int i = 0; i < free.length; i++) {
			int maxFree = max(free);
			while (free[maxFree] > 0) {
				int minUsed = min(used);
				if (minUsed == maxFree) {
					int tmp = free[maxFree];
					int tmp1 = maxFree;
					free[maxFree] = 0;
					maxFree = max(free);
					free[tmp1] = tmp;
				}
				if (free[maxFree] - used[minUsed] >= 0) {
					free[maxFree] -= used[minUsed];
					used[maxFree] += used[minUsed];
					used[minUsed] = 0;
					free[minUsed] = total[minUsed];
				} else {
					used[minUsed] -= free[maxFree];
					free[minUsed] += free[maxFree];
					free[maxFree] = 0;
					used[maxFree] = total[maxFree];
				}
			}
		}
		int count = free.length;
		for (int i = 0; i < free.length; i++) {
			if (used[i] == 0)
				count--;
		}
		return count;
	}

	public static int max(int[] a) {
		int max = a[0], k = 0;
		for (int i = 1; i < a.length; i++) {
			if (a[i] > max) {
				max = a[i];
				k = i;
			}
		}
		return k;
	}

	public static int min(int[] a) {
		int min = a[0], k = 0;
		for (int i = 1; i < a.length; i++) {
			if (a[i] < min) {
				min = a[i];
				k = i;
			}
		}
		return k;
	}

	// 157
	public static int noGuesses(int upper, int answer) {
		int lower = 1;
		int guesses = 0;
		while (lower != answer) {
			guesses++;
			int x = (lower + upper) / 2;
			if (x <= answer)
				lower = x;
			else
				upper = x;
		}

		return guesses;
	}

	// 158
	public static int getCycle(String initial, String current) {
		int count = 1;
		String myInitial = initial;
		while (true) {
			if (initial.equals(current))
				break;
			if (initial.equals(myInitial) && count != 1)
				return -1;
			initial = "" + initial.charAt(3) + initial.charAt(2)
					+ initial.charAt(0) + initial.charAt(1);
			count++;
		}
		return count;
	}

	// 159
	public static int freeParks(String street) {
		boolean[] allowed = new boolean[street.length()];
		for (int i = 0; i < allowed.length; i++) {
			if (street.charAt(i) == 'D')
				allowed[i] = true;
			if (street.charAt(i) == 'B') {
				allowed[i] = true;
				if (i - 1 >= 0)
					allowed[i - 1] = true;
				if (i - 2 >= 0)
					allowed[i - 2] = true;
			}
			if (street.charAt(i) == 'S') {
				allowed[i] = true;
				if (i - 1 >= 0)
					allowed[i - 1] = true;
				if (i + 1 < allowed.length)
					allowed[i + 1] = true;
			}
		}
		int count = 0;
		for (int i = 0; i < allowed.length; i++) {
			if (!allowed[i])
				count++;
		}
		return count;
	}

	// 160
	public static int getValue(String key, String code) {
		StringBuffer str = new StringBuffer();
		for (int i = 0; i < code.length(); i++) {
			if (key.contains(code.charAt(i) + "")) {
				int index = key.indexOf(code.charAt(i)) + 1;
				if (index == 10)
					index = 0;
				str.append(index);
			}
		}
		return Integer.parseInt(str.toString());
	}

	// 161
	public static String[] dealHands(int numPlayers, String deck) {
		String[] res = new String[numPlayers];
		java.util.Arrays.fill(res, "");
		for (int i = 0; i < (deck.length() / numPlayers) * numPlayers; i += 0) {
			for (int j = 0; i < deck.length() && j < numPlayers; j++) {
				res[j] += deck.charAt(i);
				i++;
			}
		}
		return res;
	}

	// 162
	public static int lcm(int first, int last) {
		int lcm = first;
		for (int i = first + 1; i <= last; i++) {
			lcm = lcm1(lcm, i);
		}
		return lcm;
	}

	public static int lcm1(int a, int b) {
		int lcm = a * b;
		while (a != b) {
			if (a > b)
				a = a - b;
			else
				b = b - a;
		}
		return lcm / a;
	}

	// 163
	public static int lunchtime(int branch, int rest, int leaf) {
		int start = 0;
		int leaves = 1;
		int deltaLeaf = 0;
		while (start != branch) {
			start += rest;
			if (start > branch)
				break;
			if (start % deltaLeaf == 0)
				leaves++;
		}
		return leaves;
	}

	// 164
	public static String[] justify(String[] textIn) {
		int max = 0;
		for (int i = 0; i < textIn.length; i++) {
			if (textIn[i].length() > max)
				max = textIn[i].length();
		}
		for (int i = 0; i < textIn.length; i++) {
			StringBuffer str = new StringBuffer();
			for (int j = 0; j < max - textIn[i].length(); j++) {
				str.append(" ");
			}
			str.append(textIn[i]);
			textIn[i] = str.toString();
		}
		return textIn;
	}

	// 165
	public static int[] coins(int pence) {
		int pounds = 0, shillings = 0;
		pounds = pence / (20 * 12);
		pence = pence - (pence / (20 * 12)) * (20 * 12);
		shillings = pence / 12;
		pence = pence - (pence / 12) * 12;
		return new int[] { pounds, shillings, pence };
	}

	// 166
	public static int pictureFrames(int[] pieces) {
		Arrays.sort(pieces);
		int count = 0;
		for (int i = 0; i < pieces.length; i++) {
			for (int j = i; j < pieces.length; j++) {
				int sides = pieces[i] + pieces[j];
				for (int k = j + 1; k < pieces.length; k++) {
					if (sides > pieces[k])
						count++;
				}
			}
		}
		return count;
	}

	// 167
	public static double closest(int sleepTime, int k) {
		if (k == 1)
			return 24 * 60;
		if (sleepTime == 0)
			return 24.0 / k;
		double day = 24.0 - sleepTime;
		double hours = day / (k - 1.0);
		if (hours > 12)
			hours = 12;
		if (24 - hours * (k - 1) >= sleepTime)
			hours = 24.0 / k;
		return hours * 60.0;
	}

	// 168
	public static int stridesTaken(int[] flights, int stairsPerStride) {
		int count = 0;
		for (int i = 0; i < flights.length; i++) {
			while (flights[i] - stairsPerStride > 0) {
				flights[i] = flights[i] - stairsPerStride;
				count++;
			}
			if (flights[i] != 0)
				count++;
			if (i != flights.length - 1)
				count += 2;
		}
		return count;
	}

	// 169
	public static int[] getSwimTimes(int[] distances, int[] speeds, int current) {
		int[] time = new int[speeds.length];
		java.util.Arrays.fill(time, 0);
		for (int i = 0; i < speeds.length; i++) {
			if (distances[i] == 0) {
				time[i] = 0;
				continue;
			}
			double x = 0;
			if (speeds[i] + current != 0)
				x = (double) distances[i] / (double) (speeds[i] + current);
			if (speeds[i] - current != 0)
				x += (double) distances[i] / (double) (speeds[i] - current);
			else
				x = -1;
			if (x <= 0)
				x = -1;
			time[i] = (int) x;
		}
		return time;
	}

	// 170
	public static int toNextLevel(int[] expNeeded, int received) {
		int cur = 0;
		int total = 0;
		while (received > 0) {
			total += expNeeded[cur];
			if (expNeeded[cur] - received > 0) {
				expNeeded[cur] -= received;
				received = 0;
			} else {
				received -= expNeeded[cur];
				expNeeded[cur] = 0;
				cur++;
				expNeeded[cur] -= total;
			}
			if (cur == expNeeded.length)
				break;
		}
		return expNeeded[cur];
	}

	// 171
	public static int[] dieRolls(String[] dice) {
		int min = 0, max = 0;
		for (int i = 0; i < dice.length; i++) {
			String[] str = dice[i].split("d");
			int n = Integer.parseInt(str[0]);
			int sides = Integer.parseInt(str[1]);
			min += n;
			max += n * sides;
		}
		int av = (min + max) / 2;
		return new int[] { min, max, av };
	}

	// 172
	public static int[] partners(int[] candidates, int height) {
		int c1 = candidates[0], c2 = candidates[1];
		for (int i = 2; i < candidates.length; i++) {
			int c3 = candidates[i];
			if (Math.abs(c1 - height) > Math.abs(c2 - height)) {
				if (Math.abs(c3 - height) == Math.abs(c1 - height)) {
					c1 = Math.max(c1, c3);
				}else if (Math.abs(c3 - height) < Math.abs(c1 - height)) {
					c1 = c3;
				}
			}else{
				if (Math.abs(c3 - height) == Math.abs(c2 - height)) {
					c2 = Math.max(c2, c3);
				}else if (Math.abs(c3 - height) < Math.abs(c2 - height)) {
					c2 = c3;
				}
			}
		}
		return new int[] { Math.min(c1, c2), Math.max(c1, c2) };
	}
	//173
	public static String showProgress(int[] taskTimes, int tasksCompleted){
		int timeComp = 0, sum=0;
		for (int i = 0; i < taskTimes.length; i++) {
			sum+=taskTimes[i];
			if(i<tasksCompleted)timeComp+=taskTimes[i];
		}
		int compPer = (timeComp/sum)*20;
		StringBuffer str = new StringBuffer();
		for (int i = 0; i < compPer; i++) {
			str.append("#");
		}
		for (int i = compPer; i <20 ; i++) {
			str.append(".");
		}
		return str.toString();
	}
	//174
	public static int countWords(String[] board, int size){
		int count=0;
		for (int i = 0; i < board.length; i++) {
			int len = size;
			for (int j = 0; j < board[i].length(); j++) {
				if(board[i].charAt(j)=='X') len=size;
				else {
					len--;
				}
				if(len==0) {
					if(j==board[i].length()-1||board[i].charAt(j+1)=='X')
						count++;
				}
			}
		}
		return count;
	}
	//175
	public static int finalPosition(String flips){
		int h = 0;
		for (int i = 0; i < flips.length(); i++) {
			if(flips.charAt(i)=='h') h += i+1;
			else h-=(i+1);
		}
		if(h>12){
			while(h>12)h-=12;
		}
		if(h<0){
			while(h<0) h+=12;
		}
		if(h==0) h=12;
		return h;
	}
	//176
	public static int[] getComplement(int[] rgb){
		int[] comp = new int[rgb.length];
		boolean needs128=true;
		for (int i = 0; i < comp.length; i++) {
			comp[i] = 255 - rgb[i];
			if(Math.abs(rgb[i]-comp[i])>32)needs128=false;
		}
		if(!needs128)return comp;
		for (int i = 0; i < comp.length; i++) {
			if(rgb[i]>=128) comp[i] = rgb[i]-128;
			else comp[i] = rgb[i]+128;
		}
		return comp;
	}
	//178
	public static int designs(int maxHeight, int minWidth, int totalHeight, int totalWidth){
		int count = 0;
		for (int i = maxHeight; i > 0; i--) {
			for (int j = minWidth; j<=totalWidth ; j++) {
				if(totalHeight%i==0&&totalWidth%j==0){
					if(totalHeight/i==(totalWidth/j + 1))count++;
				}
			}
		}
		return count;
	}
	
	public static int countStars(String[] result){
		int count=0;
		for (int i = 0; i < result.length; i++) {
			for (int j = 0; j < result[i].length(); j++) {
				if(result[i].charAt(j)=='o')count++;
			}
		}
		return count;
	}
	
}





