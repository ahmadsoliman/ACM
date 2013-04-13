package CodeForces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Contest261C {
	public static void main(String[] args) throws NumberFormatException, IOException {
		for (int i = 1; i < 1001; i++) {
			System.out.print(i+" ");
		}
		System.out.println();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String s=br.readLine();
		Point[] places = new Point[s.length()];
		
		double left=0, right=1000000000;
		for (int i = 0; i < places.length; i++) {
			if(s.charAt(i)=='l'){
				right = left + (right-left)/2.0;
				places[i]= new Point(right, i);
			}else{
				left = right - (right-left)/2.0;
				places[i]= new Point(left, i);
			}
		}
		
		Arrays.sort(places);
		for (int i = 0; i < places.length; i++) {
			System.out.println(places[i].index+1);
		}
	}
	static class Point implements Comparable<Point>{
		double value;
		int index;
		public Point(double value, int index) {
			super();
			this.value = value;
			this.index = index;
		}
		
		public int compareTo(Point o) {
			if(value>o.value)
				return 1;
			if(value<o.value)
				return -1;
			return 0;
		}
	}
}
