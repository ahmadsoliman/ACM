package SPOJ;

//uva

import java.awt.Point;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Waldorf {

	public static void main(String[] args) {
		BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
		int cases=0;
		try {
			cases = Integer.parseInt(stdin.readLine());
		} catch (Exception e) {
			return;
		}
		for (int i = 0; i < cases; i++) {
			int m=0,n=0,k=0;
			char[][] grid;
			String[] words;
			try {
				stdin.readLine();
				String[] strSplit = stdin.readLine().split(" ");
				m=Integer.parseInt(strSplit[0]);
				n=Integer.parseInt(strSplit[1]);
				grid = new char[m][n];
				for (int j = 0; j < m; j++) {
					String str = stdin.readLine();
					for (int j2 = 0; j2 < n; j2++) {
						grid[j][j2] = Character.toLowerCase(str.charAt(j2));
					}
				}
				k=Integer.parseInt(stdin.readLine());
				words = new String[k];
				for (int j = 0; j < k; j++) {
					StringBuffer word = new StringBuffer();
					String str = stdin.readLine();
					for (int l = 0; l < str.length(); l++) {
						word.append(Character.toLowerCase(str.charAt(l)));
					}
					words[j] = word.toString();
				}
			} catch (Exception e) {
				return;
			}
			//input end
			
			//test
//			for (int j = 0; j < m; j++) {
//				for (int j2 = 0; j2 < n; j2++) {
//					System.out.print(grid[j][j2]);
//				}
//				System.out.println();
//			}
//			for (int j = 0; j < words.length; j++) {
//				System.out.println(words[j]);
//			}
			
			//process
			Point[] answers = new Point[k];
			for (int x = 0; x < m; x++) {
				for (int y = 0; y < n; y++) {
					for (int l = 0; l < k; l++) {
						int len = words[l].length();
						if(x+len<=m){
							StringBuffer test = new StringBuffer();
							for (int j = 0; j < len; j++) {
								test.append(grid[x+j][y]);
							}
							if(words[l].equals(test.toString())){
									answers[l] = checkPoint(answers[l], x, y);
							}
							if(y+len<=n){
								test = new StringBuffer();
								for (int j = 0; j < len; j++) {
									test.append(grid[x+j][y+j]);
								}
								if(words[l].equals(test.toString())){
									answers[l] = checkPoint(answers[l], x, y);
								}
							}
							if(y-len>=0){
								test = new StringBuffer();
								for (int j = 0; j < len; j++) {
									test.append(grid[x+j][y-j]);
								}
								if(words[l].equals(test.toString())){
									answers[l] = checkPoint(answers[l], x, y);
								}
							}
						}
						if(x-len>=0){
							StringBuffer test = new StringBuffer();
							for (int j = 0; j < len; j++) {
								test.append(grid[x-j][y]);
							}
							if(words[l].equals(test.toString())){
									answers[l] = checkPoint(answers[l], x, y);
							}
							if(y+len<=n){
								test = new StringBuffer();
								for (int j = 0; j < len; j++) {
									test.append(grid[x-j][y+j]);
								}
								if(words[l].equals(test.toString())){
									answers[l] = checkPoint(answers[l], x, y);
								}
							}
							if(y-len>=0){
								test = new StringBuffer();
								for (int j = 0; j < len; j++) {
									test.append(grid[x-j][y-j]);
								}
								if(words[l].equals(test.toString())){
									answers[l] = checkPoint(answers[l], x, y);
								}
							}
						}
						if(y+len<=n){
							StringBuffer test = new StringBuffer();
							for (int j = 0; j < len; j++) {
								test.append(grid[x][y+j]);
							}
							if(words[l].equals(test.toString())){
									answers[l] = checkPoint(answers[l], x, y);
							}
						}
						if(y-len>=0){
							StringBuffer test = new StringBuffer();
							for (int j = 0; j < len; j++) {
								test.append(grid[x][y-j]);
							}
							if(words[l].equals(test.toString())){
									answers[l] = checkPoint(answers[l], x, y);
							}
						}
					}
				}
			}
			//output
			for (int j = 0; j < answers.length; j++) {
				if(answers[j]!=null)System.out.println((answers[j].x+1) + " " + (answers[j].y+1));
			}
			if(i!=cases-1)System.out.println();
		}
	}
	
	public static Point checkPoint(Point old, int xNew, int yNew){
		if(old==null||old.x>xNew||(old.x==xNew&&old.y>yNew)){
			return new Point(xNew,yNew);
		}
		return old;
	}
}
