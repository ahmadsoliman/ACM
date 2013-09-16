package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class CANDY {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(br.readLine()), sum, count;
		double unit;
		int[] arr;
		
		while(n>-1){
			arr = new int[n];
			sum=0;
			for (int i = 0; i < n; i++) {
				arr[i] = Integer.parseInt(br.readLine());
				sum+=arr[i];
			}
			
			count = -1;
			unit = 1.0*sum/n;
			if(unit==(int)unit){
				count = 0;
				for (int i = 0; i < n; i++) {
					if(arr[i]>unit)
						count += arr[i]-unit;
				}
			}
			System.out.println(count);
			n = Integer.parseInt(br.readLine());
		}
	}
}
