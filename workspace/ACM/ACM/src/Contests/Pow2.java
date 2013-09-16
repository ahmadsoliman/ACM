package Contests;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class Pow2 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t=Integer.parseInt(br.readLine().trim());
				
		BigInteger ans[] = new BigInteger[21];
		ans[1]=new BigInteger("1");
		ans[2]=new BigInteger("9");
		ans[3]=new BigInteger("89");
		ans[4]=new BigInteger("89");
		ans[5]=new BigInteger("589");
		ans[6]=new BigInteger("3089");
		ans[7]=new BigInteger("3089");
		ans[8]=new BigInteger("3089");
		
		BigInteger x = new BigInteger("3089"), two=new BigInteger("2"), twotodelta, five=new BigInteger("5"), 
				deltax=new BigInteger("12500"), pow2, ten=new BigInteger("10"), mod=new BigInteger("100000000");
		String s;
		boolean found;
		for (int i = 8; i < 21; i++) {
			found = false;
			pow2=two.modPow(x, mod);
			twotodelta=two.modPow(deltax, mod);
			while(!found){
				s=pow2.toString();
				found=true;
				for (int j = 0; j < s.length()-i+2; j++) {
					if(s.charAt(j)!='1'&&s.charAt(j)!='2'){
						found=false;
						break;
					}
				}
				if(!found){
					//x=x.add(deltax);
					pow2=pow2.multiply(twotodelta).mod(mod);
				}
			}
			deltax=deltax.multiply(five);
			twotodelta=two.modPow(deltax, mod);
			ans[i]=x;
			mod=mod.multiply(ten);
		}

		int kase=1, n;
		while(t-->0){
			n=Integer.parseInt(br.readLine().trim());
			System.out.println(kase++ + " " + n +" " +ans[n]);
		}
	}
}
