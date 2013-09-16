package Contests;

import java.awt.Point;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Line2D;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class AirPol {
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int caseNum=1;
		String input;
		while(!(input=br.readLine()).trim().equals("0 0 0 0")){
			String[] s = input.split(" ");
			int Cx = Integer.parseInt(s[0]),Cy = Integer.parseInt(s[1]),radius = Integer.parseInt(s[2]), N = Integer.parseInt(s[3]);
			
			Point[] purs = new Point[N]; 
			for (int i = 0; i < N; i++) {
				s = br.readLine().split(" ");
				purs[i] = new Point(Integer.parseInt(s[0]),Integer.parseInt(s[1]));
			}
			
			Point up=new Point(Cx,Cy+radius),down=new Point(Cx,Cy+radius);
			double perimeter = 2 * Math.PI * radius;
			for (int i = 0; i < perimeter; i+=0.1) {
				for (int j = 0; j < perimeter; j+=0.1) {
					
					
					
				}
			}
			
			System.out.println(Arrays.toString(purs));
		}
		
	}
}
