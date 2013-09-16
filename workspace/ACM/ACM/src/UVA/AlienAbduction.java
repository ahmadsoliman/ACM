package UVA;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class AlienAbduction {

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());

		PriorityQueue<Pair>[] map;

		int kase = 1, N, Q, W, H, X, Y, Ek, a, b, c, d, e, f;

		StringTokenizer st;
		while (t-- > 0) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			Q = Integer.parseInt(st.nextToken());
			W = Integer.parseInt(st.nextToken());
			H = Integer.parseInt(st.nextToken());

			map = new PriorityQueue[W];
			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				X = Integer.parseInt(st.nextToken());
				Y = Integer.parseInt(st.nextToken());

				if (map[X] == null)
					map[X] = new PriorityQueue<Pair>();
				map[X].add(new Pair(Y, i));
			}

			for (int i = 0; i < Q; i++) {
				st = new StringTokenizer(br.readLine());
				X = Integer.parseInt(st.nextToken());
				Y = Integer.parseInt(st.nextToken());
				Ek = Integer.parseInt(st.nextToken());
				a = Integer.parseInt(st.nextToken());
				b = Integer.parseInt(st.nextToken());
				c = Integer.parseInt(st.nextToken());
				d = Integer.parseInt(st.nextToken());
				e = Integer.parseInt(st.nextToken());
				f = Integer.parseInt(st.nextToken());
				
				for (int j = 0; j <= Ek; j++) {
					for (int j2 = 0; j+j2 <= Ek; j2++) {
						
					}
				}
			}
		}
	}

	static class Pair implements Comparable<Pair> {
		int x, y, i;

		public Pair(int y, int i) {
			this.y = y;
			this.i = i;
		}

		public Pair(int x, int y, int i) {
			this.x = x;
			this.y = y;
			this.i = i;
		}

		public int compareTo(Pair p) {
			return Integer.compare(y, p.y);
		}

	}
}
