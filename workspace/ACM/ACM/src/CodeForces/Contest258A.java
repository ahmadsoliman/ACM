package CodeForces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Contest258A {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine()); 
		int n = Integer.parseInt(st.nextToken()) , k = Integer.parseInt(st.nextToken()), countLucky, cur, digit, countRes=0;
		boolean flag;
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < n; i++) {
			countLucky=0;
			cur = Integer.parseInt(st.nextToken());
			flag=true;
			while(cur>0){
				digit=cur%10;
				if(digit==4||digit==7)
					countLucky++;
				if(countLucky>k){
					flag=false;
					break;
				}
				cur/=10;
			}
			if(flag)
				countRes++;
		}
		System.out.println(countRes);
		
	}

}
