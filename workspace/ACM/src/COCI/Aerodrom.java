package COCI;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

public class Aerodrom {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N, M;
		String[] pieces = br.readLine().split(" ");
		N = Integer.parseInt(pieces[0]);//desks
		M = Integer.parseInt(pieces[1]);//people
		
		int[] times = new int[N];
		for (int i = 0; i < times.length; i++) {
			times[i] = Integer.parseInt(br.readLine());
		}
		
		int[] left = new int[N];
		int time = 0;
		
		Point[] timesSorted = new Point[N]; //pairs to be sorted using comparator
		Comparator<Point> pairsComparator = new Comparator<Point>() {
				public int compare(Point o1, Point o2) {
					if(o1.x<o2.x){
						return -1;
					}else if(o1.x==o2.x){
						return 0;
					}else
						return 1;
				}
			};
		for (int i = 0; i < N; i++) {
			timesSorted[i] = new Point(times[i], i);
		}
		Arrays.sort(timesSorted,pairsComparator);
				
		
		while(M>0){
			for (int i = 0; i < timesSorted.length; i++) {
				int x = timesSorted[i].x;
				for (int j = 0; j < timesSorted.length; j++) {
					
				}
				
				if(x<1){
					left[i] = x;
					M--;
				}
			}
		}
		
	}
	static class Point{
		int x;
		int i;
		public Point(int x, int i) {
			super();
			this.x = x;
			this.i = i;
		}
		public String toString() {
			return "(" + x + "," + i + ")";
		}
	}
}
