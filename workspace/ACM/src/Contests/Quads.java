package Contests;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Quads {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int caseNum=1;
		String input;
		while(!(input=br.readLine()).trim().equals("0")){
			int n = Integer.parseInt(input);
			long x=1 , y=1 , z=1;
			for (long i = 3; i < n; i++) {
				long newV = x + y + z;
				x = y;
				y = z;
				z = newV;
			}
			System.out.println("Case " + caseNum + ": " + z);
			caseNum++;
		}
	}
}
