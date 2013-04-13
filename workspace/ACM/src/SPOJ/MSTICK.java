package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class MSTICK {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(br.readLine().trim()), n;
		
		Point[] pairs; 
		Comparator<Point> xComp = new Comparator<Point>() {
			public int compare(Point o1, Point o2) {
				if(o1.x<o2.x){
					return -1;
				}else if(o1.x==o2.x){
					if(o1.y<o2.y)
						return -1;
					else if(o1.y==o2.y)
						return 0;
					else
						return 1;
				}else
					return 1;
			}
		};
		
		StringTokenizer sT;
		for (int i = 0; i < t; i++) {
			n = Integer.parseInt(br.readLine().trim());
			pairs = new Point[n];
			
			sT = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				pairs[j] = new Point(Integer.parseInt(sT.nextToken()),Integer.parseInt(sT.nextToken()));
			}
			
			boolean[] done = new boolean[n];
			Arrays.sort(pairs, xComp);
			int minutes=1;
			int latestY;
			for (int j = 0; j < n; j++) {
				if(done[j])
					continue;
				done[j] = true;
				latestY=pairs[j].y;
				for (int j2 = j+1; j2 < n; j2++) {
					if(done[j2])
						continue;
					if(latestY>pairs[j2].y){
						minutes++;
					}else{
						latestY = pairs[j2].y;
						done[j2] = true;
					}
				}
			}
			if(minutes>1)
				minutes--;
			System.out.println(minutes);
		}
		
	}
	static class Point implements Comparable<Point>{
		public int x,y;
		public Point(int x , int y) {
			this.x = x;
			this.y = y;
		}
		public String toString() {
			return "(" + x + "," + y + ")";
		}
		
		public int compareTo(Point o) {
			if(x<o.x){
				return -1;
			}else if(x==o.x){
				if(y<o.y)
					return -1;
				else if(y==o.y)
					return 0;
				else
					return 1;
			}else
				return 1;
		}
	}
}