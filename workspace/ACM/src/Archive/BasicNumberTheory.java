package Archive;

import java.util.Arrays;

public class BasicNumberTheory {
	public static void main(String[] args) {
//		System.out.println(GCD(10000120402050000l,1258912521292512400l));
//		System.out.println(LCM(10,25));
//		System.out.println(Arrays.toString(eGCD(10,4)));
//		System.out.println(CRT(new long[][]{{2,3},{3,4},{1,5}}));
//		System.out.println(inverseMod(4,5));
	}
	
	public static long GCD(long m, long n){
		if(m==0)
			return n;
		return GCD(n%m,m);
	}
	
	public static long LCM(long m, long n){
		return m*n/GCD(m,n);
	}
	
	//Extended Euclidean Algorithm
	public static long[] eGCD(long m, long n){
		if(m==0)
			return new long[]{0,1,n};
		long[] tmp = eGCD(n%m, m);
		return new long[]{tmp[1]-(n/m)*tmp[0],tmp[0],tmp[2]};
	}
	
	//Chinese Remainder Theorem , congruences[i][0] = ai & congruences[i][1] = ni
	public static long CRT(long[][] congruences){
		//check all n are co-prime
		
		//calculate N
		long N=1;
		for (int i = 0; i < congruences.length; i++) {
			N*=congruences[i][1];
		}
		
		//calculate x
		long x=0;
		for (int i = 0; i < congruences.length; i++) {
			long si = N/congruences[i][1];
			x += eGCD(congruences[i][1], si)[1]*si*congruences[i][0];
		}
		return x;
	}
	
	public static long inverseMod(long n, long mod){
		long inv = eGCD(mod, n)[1];
		while(inv<0)
			inv+=mod;
		return inv%mod;
	}
	
	//sieve
	public static boolean[] sieve(int N){
	    boolean[] isNotPrime = new boolean[N + 1];
	    isNotPrime[0]=true;
		isNotPrime[1]=true;	 
		
	    for (int i = 2; i*i <= N; i++) {
	        if (!isNotPrime[i]) {
	            for (int j = i; i*j <= N; j++) {
	                isNotPrime[i*j] = true;
	            }
	        }
	    }
	    return isNotPrime;
	}
	
	//prime factorization once and with powers
	
	//residue classes & group ,, euler's totient
}
