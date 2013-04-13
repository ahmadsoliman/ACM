package CodeForces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Contest257C {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine());
		String[] in;
		Point[] points = new Point[n];
		for (int i = 0; i < n; i++) {
			in = br.readLine().split(" ");
			points[i] = new Point(Integer.parseInt(in[0]), Integer.parseInt(in[1]));
		}
		
		boolean quad1,quad2,quad3,quad4;
		for (int i = 0; i < points.length; i++) {
			if(points[i].x>0)
				if(points[i].y>=0)
					quad1=true;
				else
					quad4=true;
			else
				if(points[i].y>=0)
					quad2=true;
				else
					quad3=true;
		}
		
		Arrays.sort(points);
		Point firstPoint = points[n-1];
		for (int i = n-1; i >= 0; i--) {
			
		}
		
	}
	static class Point implements Comparable<Point>{
		int x,y;
		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
		public int compareTo(Point o) {
			if(this.x>o.x)
				return 1;
			else if(this.x<o.x)
				return -1;
			else
				return 0;
		}
	}
}
