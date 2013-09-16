package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class FOOL {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		StringBuffer s;
		for (int i = 0; i < t; i++) {
			s = new StringBuffer(br.readLine());
			
			//brute force
			str = s;
			brute("");
		}
	}
	
	static StringBuffer str; //expected "0 = {" , "1 = ," , "2 = }"
	static Stack<Integer> stack;
	final static String comma=",";
	public static boolean brute(String s){
		String[] parts = s.split(comma);
		
		if(parts[0].charAt(0)=='{'){
			if(parts[parts.length-1].charAt(parts[parts.length-1].length())!='}')
				return false;
			boolean total = brute(parts[0].substring(1));
			total &= brute(parts[parts.length-1].substring(0,parts[parts.length-1].length()));
			for (int i = 1; i < parts.length; i++) {
				total &= brute(parts[i]);
			}
			return total;
		}
		
		if(s.length()>1)
			return false;
		else{
			char c = s.charAt(0);
			if(c=='{'||c==','||c=='}')
				return true;
			return false;
		}
		
		
		//{ { , , }
		
	}
}
