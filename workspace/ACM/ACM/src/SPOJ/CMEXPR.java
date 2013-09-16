package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class CMEXPR {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		for (int i = 0; i < t; i++) {
			System.out.println(simplify(new StringBuffer(br.readLine())));
		}
	}

	private static String simplify(StringBuffer s) {
		boolean flag=false;
		int brackets;
		while(!flag){
			if(s.charAt(0)!='(')
				break;
			brackets=0;
			for (int i = 0; i < s.length(); i++) {
				if(s.charAt(i)=='(')
					brackets++;
				else if(s.charAt(i)==')')
					brackets--;
				if(brackets==0&&i!=s.length()-1)
					flag=true;
			}
			if(!flag){
				s.deleteCharAt(0);
			    s.deleteCharAt(s.length()-1);
			}
		}
		if(!s.toString().contains("("))
			return s.toString();
		
		StringBuffer temp;
		for (int i = 0; i < s.length(); i++) {
			if(i==0&&s.charAt(i)=='('){
				brackets=1;
				temp=new StringBuffer();
				while(brackets>0){
					i++;
					if(s.charAt(i)=='(')
						brackets++;
					else if(s.charAt(i)==')')
						brackets--; 
					if(brackets>0)
						temp.append(s.charAt(i));
				}
				String sT = simplify(temp);
				boolean containsAddSub=false;
				
				brackets=0;
				for (int k = 0; k < sT.length(); k++) {
					if(sT.charAt(k)=='(')
						brackets++;
					else if(sT.charAt(k)==')')
						brackets--;
					if(brackets==0&&(sT.charAt(k)=='+'||sT.charAt(k)=='-'))
						containsAddSub=true;
				}
				
				if(containsAddSub && (s.charAt(i+1)=='*'||s.charAt(i+1)=='/')){
					s.replace(0, i+1, '('+sT+')');
					i = sT.length()+1;
				}else{
					s.replace(0, i+1, sT);
					i = sT.length()-1;
				}
			}
			switch (s.charAt(i)) {
			case '+':
				if(s.charAt(i+1)=='('){
					brackets=1;
					int j = ++i;
					temp=new StringBuffer();
					while(brackets>0){
						i++;
						if(s.charAt(i)=='(')
							brackets++;
						else if(s.charAt(i)==')')
							brackets--; 
						if(brackets>0)
							temp.append(s.charAt(i));
					}
					String sT = simplify(temp);
					if(i+1<s.length() && (s.charAt(i+1)=='*'||s.charAt(i+1)=='/')){
						s.replace(j, i+1, '('+sT+')');
						i = sT.length()+j+1;
					}else{
						s.replace(j, i+1, sT);
						i = sT.length()+j-1;
					}
				}
				break;
				
			case '*':
				if(s.charAt(i+1)=='('){
					brackets=1;
					int j = ++i;
					temp=new StringBuffer();
					while(brackets>0){
						i++;
						if(s.charAt(i)=='(')
							brackets++;
						else if(s.charAt(i)==')')
							brackets--;
						if(brackets>0)
							temp.append(s.charAt(i));
					}
					String sT = simplify(temp);
					boolean containsAddSub=false;
					brackets=0;
					for (int k = 0; k < sT.length(); k++) {
						if(sT.charAt(k)=='(')
							brackets++;
						else if(sT.charAt(k)==')')
							brackets--;
						if(brackets==0&&(sT.charAt(k)=='+'||sT.charAt(k)=='-'))
							containsAddSub=true;
					}
					if(containsAddSub){
						s.replace(j, i+1, '('+sT+')');
						i = sT.length()+j+1;
					}else{
						s.replace(j, i+1, sT);
						i = sT.length()+j-1;
					}
				}
				break;
			case '-':
				if(s.charAt(i+1)=='('){
					brackets=1;
					int j = ++i;
					temp=new StringBuffer();
					while(brackets>0){
						i++;
						if(s.charAt(i)=='(')
							brackets++;
						else if(s.charAt(i)==')')
							brackets--;
						if(brackets>0)
							temp.append(s.charAt(i));
					}
					String sT = simplify(temp);
					boolean containsAddSub=false;
					brackets=0;
					for (int k = 0; k < sT.length(); k++) {
						if(sT.charAt(k)=='(')
							brackets++;
						else if(sT.charAt(k)==')')
							brackets--;
						if(brackets==0&&(sT.charAt(k)=='+'||sT.charAt(k)=='-'))
							containsAddSub=true;
					}
					if(containsAddSub){
						s.replace(j, i+1, '('+sT+')');
						i = sT.length()+j+1;
					}else{
						s.replace(j, i+1, sT);
						i = sT.length()+j-1;
					}
				}
				break;
			case '/':
				if(s.charAt(i+1)=='('){
					brackets=1;
					int j = ++i;
					temp=new StringBuffer();
					while(brackets>0){
						i++;
						if(s.charAt(i)=='(')
							brackets++;
						else if(s.charAt(i)==')')
							brackets--;
						if(brackets>0)
							temp.append(s.charAt(i));
					}
					String sT = simplify(temp);
					if(sT.length()>1){
						s.replace(j, i+1, '('+sT+')');
						i = sT.length()+j+1;
					}else{
						s.replace(j, i+1, sT);
						i = sT.length()+j-1;
					}
				}
				break;
			default:
				break;
			}
		}
		return s.toString();
	}
}