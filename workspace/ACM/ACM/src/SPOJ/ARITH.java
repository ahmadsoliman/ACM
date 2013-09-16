package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class ARITH {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(br.readLine().trim());
		
		StringBuffer in;
		String op1, op2;
		StringBuffer res, productRes;
		BigInteger opInt1,opInt2, resInt, product;
		int spaces1, spaces2, dashes, maxLineLen;
		
		for (int i = 0; i < t; i++) {
			in = new StringBuffer(br.readLine());
			res = new StringBuffer();			
			spaces1 = 0;
			spaces2 = 0;
			
			for (int j = 0; j < in.length(); j++) {
				switch (in.charAt(j)) {
				case '+':
					op1 = in.substring(0, j);
					op2 = in.substring(j+1);
					
					if(op2.length()>=op1.length())
						spaces1 = op2.length() - op1.length() + 1; 
					else
						spaces2 = op1.length() - op2.length() - 1;
					
					
					for (int j2 = 0; j2 < spaces1; j2++) {
						res.append(' ');
					}
					res.append(op1);
					res.append('\n');
					
					for (int j2 = 0; j2 < spaces2; j2++) {
						res.append(' ');
					}
					res.append('+');
					res.append(op2);
					res.append('\n');
					
					maxLineLen = Math.max(spaces1+op1.length(), spaces2+op2.length()+1);
				
					opInt1 = new BigInteger(op1);
					opInt2 = new BigInteger(op2);
					
					resInt = opInt1.add(opInt2);
					
					for (int j2 = 0; j2 < maxLineLen; j2++) {
						res.append('-');
					}
					res.append('\n');
					
					for (int j2 = 0; j2 < maxLineLen-resInt.toString().length(); j2++)
						res.append(' ');
						
					res.append(resInt.toString());
					
					break;
					
				case '-':
					op1 = in.substring(0, j);
					op2 = in.substring(j+1);
					
					if(op2.length()>=op1.length())
						spaces1 = op2.length() - op1.length() + 1; 
					else
						spaces2 = op1.length() - op2.length() - 1;
					
					
					for (int j2 = 0; j2 < spaces1; j2++) {
						res.append(' ');
					}
					res.append(op1);
					res.append('\n');
					
					for (int j2 = 0; j2 < spaces2; j2++) {
						res.append(' ');
					}
					res.append('-');
					res.append(op2);
					res.append('\n');
					
					maxLineLen = Math.max(spaces1+op1.length(), spaces2+op2.length()+1);
				
					opInt1 = new BigInteger(op1);
					opInt2 = new BigInteger(op2);
					
					resInt = opInt1.add(opInt2.negate());
					
					for (int j2 = 0; j2 < maxLineLen; j2++) {
						res.append('-');
					}
					res.append('\n');
					
					for (int j2 = 0; j2 < maxLineLen-resInt.toString().length(); j2++)
						res.append(' ');
						
					res.append(resInt.toString());
					
					break;
				case '*':	
					op1 = in.substring(0, j);
					op2 = in.substring(j+1);
					
					opInt1 = new BigInteger(op1);
					opInt2 = new BigInteger(op2);
					
					product = new BigInteger("0");
					productRes = new StringBuffer();
					
					for (int j2 = op2.length()-1; j2 >= 0 ; j2--) {
						resInt = opInt1.multiply(new BigInteger((op2.charAt(j2)-'0')+""));
						
						product = product.add(resInt.multiply(new BigInteger(""+(int)Math.pow(10, op2.length()-j2-1))));
						
						productRes.append(resInt.toString());
						if(j2>0)
							productRes.append('\n');
					}
					
					
					maxLineLen = Math.max(Math.max(op1.length(), op2.length()+1),Math.max(op2.length()-1+(new BigInteger(""+(op2.charAt(0)-'0'))).multiply(opInt1).toString().length(), product.toString().length()));
					
					for (int j2 = 0; j2 < maxLineLen-op1.length(); j2++)
						res.append(' ');
					res.append(op1);
					res.append('\n');
					

					for (int j2 = 0; j2 < maxLineLen-op2.length()-1; j2++)
						res.append(' ');
					res.append('*');
					res.append(op2);
					res.append('\n');
					
					int dashesSpaces=Math.max(op1.length(), op2.length()+1);
					for (int j2 = 0; j2 < maxLineLen-dashesSpaces; j2++)
						res.append(' ');
					
					for (int j2 = 0; j2 < dashesSpaces; j2++) {
						res.append('-');
					}
					
					
					StringTokenizer st = new StringTokenizer(productRes.toString());
					int j3 = 0;
					while (st.hasMoreTokens()) {
						res.append("\n");
						String token = st.nextToken("\n");
						for (int j2 = 0; j2 < maxLineLen-token.length()-j3; j2++)
							res.append(' ');
						res.append(token);
						
						j3++;
					}
					
					if(op2.length()==1)
						break;
					
					res.append('\n');
					for (int j2 = 0; j2 < maxLineLen; j2++) {
						res.append('-');
					}
					
					res.append('\n');
					res.append(product.toString());
					
					break;
				}
				if(res.length()>0)
					break;
			}
			System.out.println(res);
			System.out.println();
		}
	}

}
