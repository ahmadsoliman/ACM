package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BEADS {
	public static void main(String[] args) throws NumberFormatException, IOException {
		final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		final int t = Integer.parseInt(br.readLine());
		StringBuffer in;
		StringBuffer minS,tempS;
		int len, minI;
		
		for (int i = 0; i < t; i++) {
			in = new StringBuffer(br.readLine());
			len = in.length();
			minS = new StringBuffer(in);
			minI=0;
			for (int j = 1; j < len; j++) {
				tempS = new StringBuffer(in.substring(j)+in.substring(0,j));
				if(tempS.toString().compareTo(minS.toString())<0){
					minS = new StringBuffer(tempS);
					minI=j;
				}
			}
			
			System.out.println(minI+1);
		}
	}
}
