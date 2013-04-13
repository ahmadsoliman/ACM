package CodeForces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Contest261A {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String s=br.readLine(), t=br.readLine();
		int i=0;
		for (int j = 0; j < t.length(); j++) {
			if(s.charAt(i)==t.charAt(j)){
				i++;
			}
		}
		System.out.println(i+1);
	}
}
