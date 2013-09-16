package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

//Adding Reversed Numbers
public class ADDREV {
	public static void main(String[] args) throws NumberFormatException, IOException {
		final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		final int t = Integer.parseInt(br.readLine());
		char[] s1,s2;
		StringBuffer s11, s22, res, revRes;
		StringTokenizer st;
		char c;
		for (int i = 0; i < t; i++) {
			st = new StringTokenizer(br.readLine());
			s1 = st.nextToken().toCharArray();
			s2 = st.nextToken().toCharArray();
			s11 = new StringBuffer(s1.length);
			s22 = new StringBuffer(s2.length);
			res = new StringBuffer(Math.max(s1.length, s2.length));
			
			for (int j = s1.length-1; j >= 0; j--) {
				s11.append(s1[j]);
			}
			for (int j = s2.length-1; j >= 0; j--) {
				s22.append(s2[j]);
			}
			
			revRes = new StringBuffer((Long.parseLong(s11.toString()) + Long.parseLong(s22.toString())) + "");
						
			boolean reachedValue = false;
			for (int j = revRes.length()-1; j >= 0; j--) {
				c = revRes.charAt(j);
				if(c!='0'){
					reachedValue = true;
					res.append(c);
				}else{
					if(reachedValue){
						res.append(c);
					}else
						continue;
				}
			}
			System.out.println(res);
		}
		
	}
}
