package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

//transform the expression
public class ONP {
	public static void main(String[] args) throws IOException{
		final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		final int t = Integer.parseInt(br.readLine());
		char[] in;
		Stack<Character> s;
		StringBuffer res;
		int len;
		for (int i = 0; i < t; i++) {
			in = br.readLine().toCharArray();
			len = in.length;
			s = new Stack<Character>();
			res = new StringBuffer();
			
			for (int j = 0; j < len; j++) {
				if(in[j]=='(')
					continue;
				else if(in[j]==')'){
					res.append(s.pop());
				}else if(Character.isLetter(in[j])){
					res.append(in[j]);
				}else{
					s.push(in[j]);
				}
			}
			
			System.out.println(res);
		}
	}
}
