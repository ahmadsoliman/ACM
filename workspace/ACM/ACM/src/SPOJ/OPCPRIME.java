package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class OPCPRIME {
	public static void main(String[] args) throws NumberFormatException, IOException {
//		
//		int l = 1000000, n = 2, sqrt = (int) Math.sqrt(l);
//		boolean[] nums = new boolean[l + 1];
//		int[] primes = new int[l+1];
//
//		while(n <= sqrt){
//		    for(int i = 2 * n; i <= l; nums[i] = true, i += n);
//		    for(n++; nums[n]; n++);
//		}
//		
//		int i,k;
//		for(i = 2, k = 0; i < nums.length; i++) if(!nums[i]) primes[k++] = i;
//		System.out.println(k);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		long N = Long.parseLong(br.readLine());
		int sqrtN = (int)Math.ceil(Math.sqrt(N));
		int d = 2;
		boolean printed=false;
		while (N > 1 && d<=sqrtN){
			printed = false;
//			if(N<l&&!nums[(int)N]){
//				System.out.println(N);
//				break;
//			}
	        while (N%d==0){
	            if(!printed){
	            	System.out.println(d);
	            	printed = true;
	            }
	            N /= d;
	        }
	        d++;
		}
		if(!printed)
	    	System.out.println(N);
	}
	   
}
