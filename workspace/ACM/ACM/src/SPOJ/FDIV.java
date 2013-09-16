package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class FDIV {
	public static void main(String[] args) throws NumberFormatException, IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(br.readLine());
		BigInteger x , y;
		BigInteger[] res;
		String[] in;
		for (int i = 0; i < t; i++) {
			in = br.readLine().split(" ");
			x = new BigInteger(in[0]);
			y = new BigInteger(in[1]);
			
			res = x.divideAndRemainder(y);
			System.out.println(res[0] + " " + res[1]);
		}
	}
}

//VFDIV solution with PIKE

//import Gmp;
//
//int main() {
//  string s=Stdio.stdin->gets();
//  int t;
//  sscanf(s,"%d", t);
//  string x,y;
//  while (t>0) {
//	s=Stdio.stdin->gets();
//
//	sscanf(s,"%s %s",x,y);
//	object n = mpz(x);
//	object divisor = mpz(y);
//	write((n/divisor)->cast_to_string()+(n%divisor)->cast_to_string()+"\n");
//    t--;
//  }
//  return 0;
//}
