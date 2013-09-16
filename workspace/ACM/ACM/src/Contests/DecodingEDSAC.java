package Contests;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.NumberFormat;
import java.util.StringTokenizer;

//accepted
public class DecodingEDSAC {
	public static void main(String[] args) throws NumberFormatException, IOException {
				
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		StringTokenizer sT;
		int caseNum;
		String lookup = "PQWERTYUIOJ#SZK*?F@D!HNM&LXGABCV";
		
		int sign, first5,lastOne;
		String first5Binary, middleBinary;
		
		for (int i = 0; i < t; i++) {
			sT = new StringTokenizer(br.readLine());
			caseNum = Integer.parseInt(sT.nextToken());
			char c = sT.nextToken().charAt(0);
			int d = Integer.parseInt(sT.nextToken());
			char s = sT.nextToken().charAt(0);
			
			first5 = lookup.indexOf(c);
			first5Binary = decimalToBinary(first5,5);
			
			sign = first5Binary.charAt(0)-'0';			
			
			middleBinary = decimalToBinary(d, 11);
			
			if(s=='F')
				lastOne = 0;
			else
				lastOne = 1;
			
			String binary = first5Binary + middleBinary + lastOne;
			
			Double resValue = floatBinaryToDecimal(binary.substring(1));
			
			if(sign==1&&resValue==0.0)
				resValue = -1.0;
			else if(sign==1){
				resValue-=1;
			}
			
			NumberFormat nF = NumberFormat.getNumberInstance();
			nF.setMaximumFractionDigits(17);
			String res = nF.format(resValue);
			if(res.length()==1||(resValue<0&&res.length()==2))
				res += ".0";
			
			System.out.println(caseNum + " " + res);
		}
	}
		
	public static String decimalToBinary(int x, int numOfDigits){
		StringBuffer res = new StringBuffer();
		while(x>=1 || numOfDigits>0){
			res.insert(0, x%2);
			if(x>=1) x/=2;
			numOfDigits--;
		}
		return res.toString();
	}
	
	public static double floatBinaryToDecimal(String s){
		int j = -1; 
		double res = 0;
		for (int i = 0; i < s.length(); i++) {
			if(s.charAt(i)=='1') res += Math.pow(2.0,j);
			j--;
		}
		return res;
	}
}
