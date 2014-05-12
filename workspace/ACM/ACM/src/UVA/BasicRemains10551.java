package UVA;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class BasicRemains10551 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String in, comps[];
		int b;
		BigInteger p,m;
		while((in=br.readLine())!=null){
			comps = in.split("\\s");
			if(comps.length==1) break;
			b = Integer.parseInt(comps[0]);
			p = new BigInteger(comps[1], b);
			m = new BigInteger(comps[2], b);
			System.out.println(p.mod(m).toString(b));
		}
	}
}
