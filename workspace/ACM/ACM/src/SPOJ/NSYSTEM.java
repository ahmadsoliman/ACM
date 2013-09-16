package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class NSYSTEM {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(br.readLine());
		String[] in;
		String res;
		for (int i = 0; i < t; i++) {
			in = br.readLine().split(" ");
			res="";
			int[] num1 = toMCXI(in[0]);
			int[] num2 = toMCXI(in[1]);
			for (int j = 3; j >= 0; j--) {
				num1[j]+=num2[j];
				if(num1[j]>9){
					num1[j]%=10;
					num1[j-1]++;
				}
				if(num1[j]==0)
					continue;
				switch (j) {
				case 3:
					res = ((num1[j]==1)?"":num1[j])+"i"+res;
					break;
				case 2:
					res = ((num1[j]==1)?"":num1[j])+"x"+res;
					break;
				case 1:
					res = ((num1[j]==1)?"":num1[j])+"c"+res;
					break;
				case 0:
					res = ((num1[j]==1)?"":num1[j])+"m"+res;
					break;
				default:
					break;
				}
			}
			System.out.println(res);
		}
		
	}
	//mcxi
	public static int[] toMCXI(String s){
		int reached=0;
		int[] MCXI=new int[4];
		for (int i = 0; i < s.length(); i++) {
			switch (s.charAt(i)) {
			case 'm':
				MCXI[0]=(i-reached==0)?1:Integer.parseInt(s.substring(reached,i));
				reached=i+1;
				break;
			case 'c':
				MCXI[1]=(i-reached==0)?1:Integer.parseInt(s.substring(reached,i));
				reached=i+1;
				break;
			case 'x':
				MCXI[2]=(i-reached==0)?1:Integer.parseInt(s.substring(reached,i));
				reached=i+1;
				break;
			case 'i':
				MCXI[3]=(i-reached==0)?1:Integer.parseInt(s.substring(reached,i));
				reached=i+1;
				break;
			default:
				break;
			}
		}
		return MCXI;
	}
}
