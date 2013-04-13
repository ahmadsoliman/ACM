package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class MCARDS {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
			
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
