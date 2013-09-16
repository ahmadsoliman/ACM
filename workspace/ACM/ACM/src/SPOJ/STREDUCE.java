package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

//String reduction
public class STREDUCE {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String in = br.readLine();
		
		//brute force
		String bruteRes = brute(in);
		System.out.println(bruteRes + " : " + bruteRes.length());
		
		
	}
	
	//brute force -- baababaababaababaaba
	public static String brute(String s){
		if(s.length()<3)
			return s;
		char[] sA = s.toCharArray();
		String minS=s, tempS;
		for (int i = 0; i < sA.length-2; i++) {
			if(sA[i]==sA[i+2]){
				tempS = brute(s.substring(0,i)+sA[i+1]+s.substring(i+3,s.length()));
				if(tempS.length()<minS.length()){
					minS = tempS;
				}
			}
		}
		return minS;
	}
}