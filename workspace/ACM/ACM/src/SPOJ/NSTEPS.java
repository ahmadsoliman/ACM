package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class NSTEPS {
	public static void main(String[] args) throws NumberFormatException, IOException {
		int [][] pre = new int[2][10002];
		int reached = 0;
		for (int i = 0; i < pre[0].length-3; i+=2) {
			pre[0][i] = reached++;
			pre[0][i+1] = reached++;
			pre[1][i+2] = reached++;
			pre[1][i+3] = reached++;
		}
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(br.readLine());
		int x, y;
		String[] in;
		for (int i = 0; i < t; i++) {
			in = br.readLine().split(" ");
			x = Integer.parseInt(in[0]);
			y = Integer.parseInt(in[1]);
			
			if((x<2&&x!=y)||(y!=x&&y!=x-2)){
				System.out.println("No Number");
				continue;
			}
			
			if(y==x)
				System.out.println(pre[0][x]);
			else
				System.out.println(pre[1][x]);
			
		}
	}
}
