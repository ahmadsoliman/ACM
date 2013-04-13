package COCI;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Sahovnica {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int R,C,A,B;
		String[] pieces = br.readLine().split(" ");
		R = Integer.parseInt(pieces[0]);
		C = Integer.parseInt(pieces[1]);
		pieces = br.readLine().split(" ");
		A = Integer.parseInt(pieces[0]);
		B = Integer.parseInt(pieces[1]);
		
		char[][] res = new char[R*A][C*B];
		
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < A; j++) {
				for (int j2 = 0; j2 < C; j2++) {
					for (int k = 0; k < B; k++) {
						System.out.print(((i%2==0&&j2%2==0)||(i%2==1&&j2%2==1))?'X':'.');
					}
				}
				if(i!=R-1 || j!=A-1)System.out.println();
			}
		}		
	}
}
