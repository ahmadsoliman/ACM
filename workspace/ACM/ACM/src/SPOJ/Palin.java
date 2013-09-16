package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Palin {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		StringBuffer res = new StringBuffer();
		for (int i = 0; i < t; i++) {
			StringBuffer s = new StringBuffer(br.readLine());
			int len = s.length();
			if(len==0)
				continue;
			else if(len==1){
				int x = Integer.parseInt(s.toString());
				if(x<9)res.append(x+1);
				else res.append(11);
				res.append("\n");
				continue;
			}else if(len==2){
				if(s.toString().equals("99")){
					res.append(101);
					res.append("\n");
					continue;
				}
				int left = Integer.parseInt(s.charAt(0)+"");
				int right = Integer.parseInt(s.charAt(1)+"");
				if(left>right){
					s.replace(1, 2, left+"");
				}else{
					left++;
					s = new StringBuffer(left+""+left);
				}
				res.append(s);
				res.append("\n");
				continue;
			}
			if(checkPalin(s.toString()))
				s.setCharAt(len-1, (char)(s.charAt(len-1)+1));
			for (int j = 0; j < len/2; j++) {
				int k = len-j-1;
				int left = s.charAt(j)-'0';
				int right = s.charAt(k)-'0';
				int b4Right = s.charAt(k-1)-'0';
				if(left!=right){
					s.setCharAt(k, (char)(((int)'0')+left));
					if(left<right){
						if(b4Right<9)
							b4Right++;
						else{
							int r = k; 
							boolean flag = false;
							while(b4Right==9&&r>=0){
								s.setCharAt(r, '0');
								r--;
								if(r>=0){
									b4Right = (s.charAt(r)-'0');
								}else{
									s.insert(0, 1);
									len++;
									for (int m = 1; m < len; m++) {
										s.setCharAt(m, '0');
									}
									j = -1;
									flag = true;
								}
							}
							if(flag) continue;
							if(r>=0){
								s.setCharAt(r, (char)(s.charAt(r)+1));
							}
							if(j>=r) j = r-1;
							if(j<0)j=-1;
						}
						s.setCharAt(k-1, (char)(((int)'0')+b4Right));
						if(j==k-1)
							s.setCharAt(k, (char)(((int)'0')+b4Right));
					}
				}
			}
			res.append(s);
			res.append("\n");
		}
		System.out.println(res);
	}
	public static boolean checkPalin(String s){
		int len = s.length();
		for (int i = 0; i < len/2; i++) {
			if(s.charAt(i)!=s.charAt(len-i-1)){
				return false;
			}
		}
		return true;
	}
}