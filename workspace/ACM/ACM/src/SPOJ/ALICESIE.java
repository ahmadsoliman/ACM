package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ALICESIE {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));		
		int t = Integer.parseInt(br.readLine());
		for (int i = 0; i < t; i++) {
			System.out.println((int)Math.ceil(Integer.parseInt(br.readLine())/2.0));
		}
	}
}
