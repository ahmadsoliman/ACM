package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class MMAXPER {
	public static void main(String[] args) throws NumberFormatException, IOException {
		final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		final int n = Integer.parseInt(br.readLine());
		
		final int[][] points = new int[2][n];
		String[] in;
		
		conf = new int[n];
		
		final int[] dp = new int[n];
		int a , firstH, secH;
		for (int i = 0; i < n; i++) {
			in = br.readLine().split(" ");
			points[0][i] = Integer.parseInt(in[0]);
			points[1][i] = Integer.parseInt(in[1]);
			
			if(i>1){
				firstH = conf[i-2]==1?points[0][i-2]:points[1][i-2];
				secH = conf[i-1]==1?points[0][i-1]:points[1][i-1];
				dp[i] = dp[i-2] + calcMax(i,points[0][i-1], points[0][i], points[1][i-1], points[1][i]) + Math.abs(firstH-secH);
				
				if(Math.abs(points[conf[i-1]][i-1]-points[0][i])+points[1][i] <= Math.abs(points[conf[i-1]][i-1]-points[1][i])+points[0][i]){
					a = dp[i-1] + points[0][i];
					if(a>=dp[i]){
						dp[i] = a;
						conf[i] = 0;
					}
				}else{
					a = dp[i-1] + points[1][i];
					if(a>=dp[i]){
						dp[i] = a;
						conf[i] = 1;
					}
				}
			}else if(i==0){
				if(points[0][0]>=points[1][0]){
					dp[0] = points[0][0];
					conf[0] = 0;
				}else{
					dp[0] = points[1][0];
					conf[0] = 1;
				}
			}else if(i==1){
				dp[1] = calcMax(1,points[0][0], points[0][1], points[1][0], points[1][1]);
			}
		}
//		System.out.println(Arrays.toString(conf));
//		System.out.println(Arrays.toString(dp));
		System.out.println(dp[n-1]);
	}
	static int[] conf;
	public static int calcMax(int index,int x, int y, int z, int w) {
		int a,b,c,d, ans;
		a = x + y + Math.abs(w - z);//0,0
		b = x + w + Math.abs(y - z);//0,1
		c = z + y + Math.abs(w - x);//1,0
		d = z + w + Math.abs(y - x);//1,1
		ans = Math.max(a,Math.max(b, Math.max(c, d)));
		if(ans==a){
			conf[index-1] = 0;
			conf[index] = 0;
		}else if(ans==b){
			conf[index-1] = 0;
			conf[index] = 1;
		}else if(ans==c){
			conf[index-1] = 1;
			conf[index] = 0;
		}else if(ans==d){
			conf[index-1] = 1;
			conf[index] = 1;
		}
		return ans;
	}

}
