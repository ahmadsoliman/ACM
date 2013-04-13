package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

public class CLCR {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		variables = new ArrayList<CLCR.Variable>();
		
		String in = br.readLine();
		while(!in.equals("#")){
			newVariables = new ArrayList<Variable>();
			evaluate(in);
			Arrays.sort(newVariables.toArray());
			for (int i = newVariables.size()-1; i >=0 ; i--) {
				System.out.print(newVariables.get(i).name +" = "+newVariables.get(i).value);
				if(i>0)
					System.out.print(", ");
			}
			if(newVariables.size()==0)
				System.out.println("No Change");
			else
				System.out.println();
			in = br.readLine();
		}
	}
	static class Variable implements Comparable<Variable>{
		char name;
		int value;
		public Variable(char name) {
			this.name = name;
			this.value=0;
		}
		public boolean equals(Variable o) {
			if(this.name==o.name)
				return true;
			return false;
		}
		public int compareTo(Variable o) {
			if(this.name>o.name)
				return 1;
			else if(this.name<o.name)
				return -11;
			return 0;
		}
	}
	static ArrayList<Variable> variables;
	static ArrayList<Variable> newVariables;
	public static int evaluate(String in){
		if(in.length()==0)
			return 0;
		if(in.charAt(0)=='(')
			return evaluate(in.substring(1,in.length()-1));
		if(in.charAt(0)=='-' || Character.isDigit(in.charAt(0))){
			return Integer.parseInt(in);
		}
		if(in.length()==1 && Character.isUpperCase(in.charAt(0))){//variable
			Variable temp = find(in.charAt(0));
			if(temp!=null)
				return temp.value;
			else{
				temp = new Variable(in.charAt(0));
				variables.add(temp);
				return 0;
			}
		}
		
		ArrayList<String> elems = new ArrayList<String>();
		
		StringBuffer num=new StringBuffer();
		for (int j = 0; j < in.length(); j++) {
			if(in.charAt(j)==' ')
				continue;
			else if(in.charAt(j)=='('){
				num.append('(');
				int brackets=1;
				j++;
				while(brackets>0){
					num.append(in.charAt(j));
					if(in.charAt(j)=='(')
						brackets++;
					else if(in.charAt(j)==')')
						brackets--;
					j++;
				}
				elems.add(num.toString());
				num = new StringBuffer();
				j--;
			}
			else if(in.charAt(j)=='_'){
				num.append('-');
				j++;
				while(j<in.length() && Character.isDigit(in.charAt(j))){
					num.append(in.charAt(j));
					j++;
					if(j>=in.length() || !Character.isDigit(in.charAt(j))){
						elems.add(num.toString());
						num=new StringBuffer();
					}
				}
				j--;
			}else if(Character.isDigit(in.charAt(j))){
				while(j<in.length() && Character.isDigit(in.charAt(j))){
					num.append(in.charAt(j));
					j++;
					if(j>=in.length() || !Character.isDigit(in.charAt(j))){
						elems.add(num.toString());
						num=new StringBuffer();
					}
				}
				j--;
			}else
				elems.add(""+in.charAt(j));
		}	
		
		String cur;
		for (int i = 0; i < elems.size(); i++) {
			cur =elems.get(i); 
			if(cur.charAt(0)=='(')
				elems.set(i, ""+cur.substring(1, cur.length()-1));
		}
		
		int res, j;
		String equalSign="=";
		for (j = elems.size()-1; j > 0; j--) {
			if(elems.get(j).length()>1)
				continue;
			if(elems.get(j).equals(equalSign))
				break;
			switch (elems.get(j).charAt(0)) {
			case '+':
				res = evaluate(elems.get(j-1))+evaluate(elems.get(j+1));
				elems.remove(j-1);
				elems.remove(j-1);
				elems.remove(j-1);
				elems.add(""+res);
				j=elems.size()-1;
				break;
			case '-':
				res = evaluate(elems.get(j-1))-evaluate(elems.get(j+1));
				elems.remove(j-1);
				elems.remove(j-1);
				elems.remove(j-1);
				elems.add(""+res);
				j=elems.size()-1;
				break;
			case '*':
				res = evaluate(elems.get(j-1))*evaluate(elems.get(j+1));
				elems.remove(j-1);
				elems.remove(j-1);
				elems.remove(j-1);
				elems.add(""+res);
				j=elems.size()-1;
				break;
			case '/':
				res = evaluate(elems.get(j-1))/evaluate(elems.get(j+1));
				elems.remove(j-1);
				elems.remove(j-1);
				elems.remove(j-1);
				elems.add(""+res);
				j=elems.size()-1;
				break;
			default:
				break;
			}
		}
		
		res = Integer.parseInt(elems.get(elems.size()-1));
		for (;j >= 0; j--) {
			cur = elems.get(j);
			if(cur.equals(equalSign))
				continue;
			
			Variable temp = find(cur.charAt(0));
			if(temp!=null){
				if(temp.value!=res){
					temp.value=res;
					newVariables.add(temp);
				}
			}else{
				temp = new Variable(cur.charAt(0));
				temp.value=res;
				variables.add(temp);
				if(res!=0)
					newVariables.add(temp);
			}
		}
		return res;
	}
	public static Variable find(char name){
		for (int i = 0; i < variables.size(); i++) {
			if(variables.get(i).name==name)
				return variables.get(i);
		}
		return null;
	}
}
//A = B = 4
//C = (D = 2)*_2
//C = D = 2 * _2
//F = C - D
//E = D * _10
//Z = 10 / 3
//#