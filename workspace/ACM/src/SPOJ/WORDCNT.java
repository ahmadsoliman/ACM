package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class WORDCNT {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(br.readLine());
		StringTokenizer st;
		int max, count, lastLen=0;
		String cur;
		for (int i = 0; i < t; i++) {
			st = new StringTokenizer(br.readLine());
			max=0;
			cur = st.nextToken();
			while(true){
				lastLen=cur.length();
				count=0;
				while(true){
					if(cur.length()==lastLen){
						count++;
						if(st.hasMoreTokens())
							cur = st.nextToken();
						else
							break;
					}else
						break;
				}
				if(count>max)
					max = count;
				if(!st.hasMoreTokens())
					break;
			}
			System.out.println(max);
		}
	}
}
