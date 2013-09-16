package Contests;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Random;

public class Equivilance {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		String exp1, exp2;
		int vars[] = new int[30];
		Random rand = new Random();
		boolean done;
		while(t-->0){
			exp1=br.readLine().replaceAll("\\s", "").toLowerCase();
			exp2=br.readLine().replaceAll("\\s", "").toLowerCase();
			done = false;
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 30; j++) vars[j] = rand.nextInt(1000)-500;
				if(!evaluate(exp1, vars).equals(evaluate(exp2, vars))){
					System.out.println("NO");
					done = true;
					break;
				}	
			}
			
			if(!done)
				System.out.println("YES");
		}
	}
	public static BigInteger evaluate(String exp, int vars[]) {
		int b=0;
		BigInteger v=new BigInteger("0"), res=new BigInteger("0");
		char oper='+';
		for (int i = 0, j; i < exp.length(); i++) {
			if(exp.charAt(i)=='('){
				b=0;
				for (j=i; j < exp.length(); j++) {
					if(exp.charAt(j)=='(')b++;
					else if(exp.charAt(j)==')')b--;
					if(b==0) break;
				}
				v = evaluate(exp.substring(i+1, j), vars);
				i=j;
			} else if(exp.charAt(i)=='+' || exp.charAt(i)=='-' || exp.charAt(i)=='*'){
				oper = exp.charAt(i);
				continue;
			}
			else if(Character.isDigit(exp.charAt(i))) v=new BigInteger(""+exp.charAt(i));
			else if(Character.isLowerCase(exp.charAt(i))){
				if(exp.charAt(i)-'a'<0 || exp.charAt(i)-'a'>26){
					while(true);
				}
				v=new BigInteger(""+vars[exp.charAt(i)-'a']);
			}
			else continue; //else throw new Exception("Not parsing very well..");
			
			
			switch (oper) {
			case '+': res=res.add(v); break;
			case '-': res=res.subtract(v); break;
			case '*': res=res.multiply(v); break;
			default: break; //throw new Exception("Not parsing operators!");
			}
		}
		return res;
	}
}

/*
2
a*2-(a+c)+((a+c+e)*2)
3*a+c+(2*e)
(a-b)*(a-b)
(a*a)-(2*a*b)-(b*b)
*/