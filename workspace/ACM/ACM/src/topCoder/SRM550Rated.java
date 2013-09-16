package topCoder;

import java.awt.Point;

public class SRM550Rated {
	public static void main(String[] args) {
		System.out.println(minArea(new int[]{1,1,1,1}));
	}
	
	
	
	// 250
	public static String isItPossible(String originalWord, String finalWord,
			int k) {

		for (int i = 0; i < originalWord.length(); i++) {
			if (originalWord.charAt(i) != finalWord.charAt(i)) {
				k--;
			}
			if (k < 0)
				return "IMPOSSIBLE";
		}
		while (k >= 2) {
			k -= 2;
		}
		if (k == 0)
			return "POSSIBLE";
		return "IMPOSSIBLE";
	}

	// 550

	public static int minArea(int[] moves) {
		int sum = moves[0];
		for (int i = 1; i < moves.length; i++) {
			sum += moves[i];
		}
		int dir = 1;
		Point[] ps = new Point[sum+2];
		
		int totalmoves=0;
		int curx = 0, cury = 0;
		int minx = 0, miny = 0, maxx = 0, maxy = 0;
		for (int i = 0; i < moves.length; i++) {
			while (moves[i] > 0) {
				Point p = new Point(curx,cury);
				if(contains(ps,p)) return -1;
				ps[totalmoves] = p;
				totalmoves++;
				if (dir == 1) {
					curx += 1;
					if(curx>maxx) maxx = curx;
				} else if (dir == 3) {
					curx -= 1;
					if(curx<minx) minx = curx;
				} else if (dir == 0) {
					cury += 1;
					if(cury>maxy) maxy = cury;
				} else if (dir == 2) {
					cury -= 1;
					if(cury<miny) miny = cury;
				}
				if(contains(ps,p)) return -1;
				moves[i]--;
			}
			if (dir == 1) {
				dir=0;
			} else if (dir == 3) {
				dir=2;
			} else if (dir == 0) {
				dir=3;
			} else if (dir == 2) {
				dir=1;
			}
		}
		return (maxx-minx+1)*(maxy-miny+1);
	}
	
	public static boolean contains(Point[] ps, Point p){
		for(int i=0; i<ps.length; i++){
			if(ps[i]==null) break;
			if(ps[i].x==p.x && ps[i].y==p.y) return true;
		}
		return false;
	}
}
