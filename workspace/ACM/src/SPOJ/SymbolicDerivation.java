package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class SymbolicDerivation {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String in;
		while((in=br.readLine())!=null){
			System.out.println(derive(in));
		}
		
	}
	public static String derive(String s){
		if(s.isEmpty())
			return "";
		if(s.equals("x"))
			return "1";
		if(!(s.contains("(") || s.contains("*") || s.contains("/") || s.contains("+") || (s.length()>1 && s.substring(1).contains("-")) || s.contains("l")))
			return "0";
		
		char c;
		ArrayList<String> elements = new ArrayList<String>();
		String latest;
		for (int i = 0; i < s.length(); i++) {
			c = s.charAt(i);
			if(c=='x' || c=='*' || c=='/' || c=='+' || (c=='-' && !elements.isEmpty())){
				elements.add(c+"");	
			}else if(c=='l'){
				latest = "ln";
				i+=2;
				int brackets = 0;
				while(i<s.length()){
					c = s.charAt(i);
					if(c=='(')
						brackets++;
					else if(c==')'){
						brackets--;
						if(brackets==0){
							latest+=c;
							break;
						}
					}
					latest+=c;
					i++;
				}
				i--;
				elements.add(latest);
			}else if(c=='('){
				latest = c+"";
				int brackets = 1;
				i++;
				while(i<s.length()){
					c = s.charAt(i);
					if(c=='(')
						brackets++;
					else if(c==')'){
						brackets--;
						if(brackets==0){
							latest+=c;
							break;
						}
					}
					latest+=c;
					i++;
				}
				i--;
				elements.add(latest);
			}else if(c=='-' || Character.isDigit(c)){
				latest = "";
				latest += c;
				i++;
				while(i<s.length()){
					c = s.charAt(i);
					if(!(c=='.' || Character.isDigit(c)))
						break;
					latest+=c;
					i++;
				}
				i--;
				elements.add(latest);
			}
		}
		
		boolean bracketed = false;
		if(elements.size()==1){
			if(elements.get(0).charAt(0)=='l'){//ln()
				String arg = s.substring(3,s.length()-1);
				return '('+derive(arg)+")/"+'('+arg+')';
			}else if(elements.get(0).charAt(0)=='('){
				elements.set(0, elements.get(0).substring(1, elements.get(0).length()-1));
				bracketed = true;
			}
		}
//		
//		for (int j = 0; j < elements.size(); j++) {
//			System.out.println(elements.get(j));
//		}
//		
		String cur;
		for (int j = elements.size()-1; j > 0; j--) {
			cur = elements.get(j);
			if(cur.isEmpty())
				continue;
			if(cur.charAt(0)=='/' || cur.charAt(0)=='*'){
				int i = j-1;
				latest="";
				while(i>=0){
					cur = elements.get(i);
					if(cur.isEmpty()){
						i--;
						continue;
					}
					if(cur.length()==1 && (cur.charAt(0)=='+' || cur.charAt(0)=='-'))
						break;
					latest = cur + latest;
					elements.remove(i);
					i--;
				}
				i++;
				elements.add(i, latest);
			}
		}
		
		StringBuffer res = new StringBuffer();
		if(bracketed)
			res.append('(');
		boolean[] components = new boolean[elements.size()];
		for (int j = 1; j < elements.size(); j++) {
			cur = elements.get(j);
			if(cur.isEmpty())
				continue;
			if(cur.charAt(0)=='*'){
				res.append('(');
				res.append(derive(elements.get(j-1)));
				res.append('*');
				res.append(elements.get(j+1));
				if(elements.get(j-1).charAt(0)!='-') res.append('+');
				res.append(elements.get(j-1));
				res.append('*');
				res.append(derive(elements.get(j+1)));
				res.append(')');
				components[j-1] = true;
				components[j+1] = true;
			}else if(cur.charAt(0)=='/'){
				res.append('(');
				res.append(derive(elements.get(j-1)));
				res.append('*');
				res.append(elements.get(j+1));
				if(elements.get(j-1).charAt(0)!='-') res.append('-');
				res.append(elements.get(j-1));
				res.append('*');
				res.append(derive(elements.get(j+1)));
				res.append(')');
				res.append('/');
				if(elements.get(j+1).length()>1){
					res.append('(');
					res.append(elements.get(j+1));
					res.append(")^2");
				}else{
					res.append(elements.get(j+1));
					res.append("^2");
				}
				components[j-1] = true;
				components[j+1] = true;
			}else if(cur.charAt(0)=='+' || cur.charAt(0)=='-'){
				if(!components[j-1]){
					res.append(derive(elements.get(j-1)));
				}
				if(elements.get(j+1).charAt(0)!='-') res.append(cur.charAt(0));
				components[j-1] = true;
			}
		}
		
		if(!components[elements.size()-1])
			res.append(derive(elements.get(elements.size()-1)));
		
		if(bracketed)
			res.append(')');
		
		return res.toString();
	}
}