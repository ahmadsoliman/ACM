package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ADITYA13 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String[] in = br.readLine().split(" ");
		String C=br.readLine(), D=br.readLine();
		int A = Integer.parseInt(in[0]), B = Integer.parseInt(in[1]);;
		
		boolean divA,divB;
		for (int i = 1; i < 100; i++) {
			divA=i%A==0;
			divB=i%B==0;
			if(divA&&divB)
				System.out.println(C+D);
			else if(divA)
				System.out.println(C);
			else if(divB)
				System.out.println(D);
			else
				System.out.println(((i<10)?"0":"")+i);
		}
	}
}

