package Contests;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class ProgrammingEDSAC {
	public static void main(String[] args) throws NumberFormatException, IOException {
		final double eps = 0.00000000000000001;
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		StringTokenizer sT;
		StringBuffer binary;
		int caseNum;
		Double input;
		StringBuffer res;
		final String lookup = "PQWERTYUIOJ#SZK*?F@D!HNM&LXGABCV";
		
		final double[] validValues = new double[131072];
		double reachedValue = 0.9999847412109375;
		for (int last = 0; last < validValues.length&&reachedValue>=-1; last++) {
			validValues[last] = reachedValue; 
			reachedValue-=0.0000152587890625;
		}
		
		for (int i = 0; i < t; i++) {
			sT = new StringTokenizer(br.readLine());
			caseNum = Integer.parseInt(sT.nextToken());
			String s = sT.nextToken();
			input = Double.parseDouble(s);
			binary = new StringBuffer();
			
			if(input==-1){
				boolean flag=false;
				for (int j = 3; j < s.length(); j++) {
					if(s.charAt(j)!='0'){
						System.out.println(caseNum + " INVALID VALUE");
						flag = true;
						break;
					}
				}
				if(flag)
					continue;
			}
			
			if((input<0&&input.compareTo(-1.0)<0)||(input>0 && input-1.0>eps||input==1.0)){
				System.out.println(caseNum + " INVALID VALUE");
				continue;
			}
			
		
			
			for (int k = 0; k < validValues.length; k++) {
				if(validValues[k]>0 && Math.abs(input-validValues[k])<=0.0000152587890625){
					input = validValues[k+1];
					break;
				}else if(Math.abs(input-validValues[k])<0.0000152587890625){
					input = validValues[k];
					break;
				}
			}
		
			char c;
			if(input>=0){
				c = '0';
			}else{
				c = '1';
			}
			
			if(input<0)
				input+=1.0;
			
			binary.append(c);
			
			for (int j = 0; j < 16; j++) {
				if(input==0.0){
					binary.append(0);
					continue;
				}
				input*=2;
				int digit = input.intValue();
				binary.append(digit);
				if(digit==1){
					input-=1;
				}
			}
			
			//System.out.println(binary);
						
			res = new StringBuffer();
			
			int index = binaryToDecimal(binary.substring(0, 5));
			res.append(lookup.charAt(index));
			res.append(" ");
			
			res.append(binaryToDecimal(binary.substring(5, 16)));
			
			res.append(" ");
			
			if(binary.charAt(16)=='0')
				res.append('F');
			else
				res.append('D');
			
			System.out.println(caseNum + " " + res);
		}
	}

	public static int binaryToDecimal(String s){
		int j = 0, res = 0;
		for (int i = s.length()-1; i >= 0; i--) {
			if(s.charAt(i)=='1') res += Math.pow(2,j);
			j++;
		}
		return res;
	}
}
