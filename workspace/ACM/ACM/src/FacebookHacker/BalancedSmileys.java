package FacebookHacker;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class BalancedSmileys {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("G:\\BalancedSmileys.txt"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("G:\\output.txt"));
		int t = Integer.parseInt(br.readLine());
		
		for (int i = 0; i < t; i++) {
			bw.write("Case #"+(i+1)+": "+(recur(br.readLine())?"YES":"NO"));
			bw.newLine();
		}
		br.close();
		bw.close();
	}
	public static boolean recur(String s){
		int stack=0, smiley=0, frowney=0;
		for (int i = 0; i < s.length(); i++) {
			if(s.charAt(i)=='('){
				stack++;
				if(i>0&&s.charAt(i-1)==':')
					frowney++;
			}else if(s.charAt(i)==')'){
				stack--;
				if(i>0&&s.charAt(i-1)==':')
					smiley++;
			}
				
		}
		if(stack==0)
			return true;
		if(stack>0){
			
		}else{
			
		}
		return true;
	}
}
