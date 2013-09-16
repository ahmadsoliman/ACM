package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class INUMBER {
	public static void main(String[] args) throws NumberFormatException, IOException {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(br.readLine()), reached, nInt;
		String multipleS;
		BigInteger multiple, n;
		for (int i = 0; i < t; i++) {
			 n = new BigInteger(br.readLine());
			 multiple = new BigInteger(n.toString());
			 nInt = n.intValue();
			 while(true) {
				reached = 0;
				multiple = multiple.add(n);
				multipleS = multiple.toString();
				for (int j2 = 0; j2 < multipleS.length() && reached<nInt+2; reached+=multipleS.charAt(j2)-'0', j2++);
				if(nInt==reached)
					break;
			}
			System.out.println(multiple);
		}
		
	}

}
