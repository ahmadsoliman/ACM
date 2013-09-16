package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class ARITH2 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		ArrayList<String> elems;
		int t = Integer.parseInt(br.readLine());
		String in;
		for (int i = 0; i < t; i++) {
			br.readLine();
			in = br.readLine();
			
			elems = new ArrayList<String>();
			String num="";
			for (int j = 0; j < in.length(); j++) {
				if(in.charAt(j)==' '||in.charAt(j)=='=')
					continue;
				else if(Character.isDigit(in.charAt(j))){
					while(j<in.length() && Character.isDigit(in.charAt(j))){
						num+=in.charAt(j);
						j++;
						if(!Character.isDigit(in.charAt(j))){
							elems.add(num);
							num="";
						}
					}
				}else
					elems.add(""+in.charAt(j));
			}
			
			long x=Long.parseLong(elems.get(0)),y=0;
			for (int j = 1; j < elems.size(); j++) {
				switch (elems.get(j).charAt(0)) {
				case '+':
					y=Long.parseLong(elems.get(j+1));
					x += y;
					break;
				case '-':
					y=Long.parseLong(elems.get(j+1));
					x -= y;
					break;
				case '*':
					y=Long.parseLong(elems.get(j+1));
					x *= y;
					break;
				case '/':
					y=Long.parseLong(elems.get(j+1));
					x /= y;
					break;
				default:
					break;
				}
			}
			System.out.println(x);
		}
	}
}
