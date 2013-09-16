package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class FISHER {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer sT = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(sT.nextToken()), t = Integer.parseInt(sT.nextToken());
		int[][] time , toll, dp;
		String[] values;
		
		while(!(n==0&&t==0)){
			time = new int[n][n];
			toll = new int[n][n];
			
			for (int i = 0; i < n; i++) {
				values = br.readLine().split(" ");
				for (int j = 0; j < n; j++) {
					time[i][j] = Integer.parseInt(values[j]);
				}
			}
			br.readLine();
			for (int i = 0; i < n; i++) {
				values = br.readLine().split(" ");
				for (int j = 0; j < n; j++) {
					toll[i][j] = Integer.parseInt(values[j]);
				}
			}
			
			FISHER.n = n;
			FISHER.time = time;
			FISHER.toll = toll;
			
			ArrayList<Integer> rest = new ArrayList<Integer>(n);
			
			calculated = new int[n][n];//[t]
			totalTime = 0;
			
			for (int i = 0; i < calculated.length; i++) {
				Arrays.fill(calculated[i],Integer.MAX_VALUE);
				if(i>0)rest.add(i);
			}
			
			System.out.println(recur(0,rest,t)+" "+totalTime);
			
			
			br.readLine();
			sT = new StringTokenizer(br.readLine());
			n = Integer.parseInt(sT.nextToken());
			t = Integer.parseInt(sT.nextToken());
		}
	}
	static int n, totalTime;
	static int[][] time,toll, calculated;
	static int recur(int last, ArrayList<Integer> rest, int t){
		if(last==n-1){
			return 0;
		}
		int cur, minValue=Integer.MAX_VALUE;
		ArrayList<Integer> tmp;
		for (int k = 0; k < rest.size(); k++) {
			cur = rest.get(k).intValue();
			if(cur!=last){
				if(calculated[last][cur]==Integer.MAX_VALUE){
					if(time[last][cur]<=t){
						tmp = (ArrayList<Integer>) rest.clone();
						tmp.remove(k);
						calculated[last][cur] = toll[last][cur] + recur(cur,tmp,t-time[last][cur]);
					}
				}
				if(calculated[last][cur]<minValue && calculated[last][cur]>0){
					minValue = calculated[last][cur];
					totalTime += time[last][cur];
				}
			}
		}
		return minValue;
	}
}


