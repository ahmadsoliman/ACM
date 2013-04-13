package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// amr samir
public class PCPC12J {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine()), n;
		
		int[] freq;
		String[] in;
		StringTokenizer st;
		int[] nums;
		for (int i = 0; i < t; i++) {
			n = Integer.parseInt(br.readLine());
			st = new StringTokenizer(br.readLine());
			nums = new int[n];
			
			freq = new int[201];
			for (int j = 0; j < nums.length; j++) {
				nums[j] = Integer.parseInt(st.nextToken());
				freq[nums[j]]++;
			}
			boolean found=false;
			int max=-1, maxI=-1;
			String lastMax = "";
			while(!found){
				max=-1;
				maxI=-1;
				for (int j = 0; j < freq.length; j++) {
					if(freq[j]>=max && !lastMax.contains(j+"")){
						max = freq[j];
						maxI = j;
					}
				}
				lastMax+=maxI;
				if(freq[maxI]%maxI==0 || freq[maxI]==0){
					found = true;
				}
			}
			if(found&&freq[maxI]>0)
				System.out.println(maxI);
			else
				System.out.println(-1);
		}
	}		
}














