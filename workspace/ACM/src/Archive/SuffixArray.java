package Archive;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

public class SuffixArray {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		int[] SA = construct(s);
		System.out.println(Arrays.toString(SA));
		for (int i = 0; i < SA.length; i++) {
			System.out.println(s.substring(SA[i]));
		}
	}
	
	//O(nlognlogn) : Prefix Doubling 
	public static int[] construct(String s){
		//mark string end
		s+="$";
		int len = s.length();
		
		//all chars in s
		char[] chars = s.toCharArray();
		//all chars in s sorted in O(nlogn)
		char[] sortedChars = chars.clone();
		Arrays.sort(sortedChars);
		
		//construct all suffixes to be ordered O(n)
		String[] suffixes = new String[len]; 
		for (int i = 0; i < len; i++) {
			suffixes[i] = s.substring(i);
		}
		
//		//sort T1 in O(nlogn): sort the suffixes according to the first character
//		String[] T1 = suffixes.clone();
//		Arrays.sort(T1, new Comparator<String>() {
//			public int compare(String s1, String s2) {
//				if(s1.charAt(0)>s2.charAt(0)){
//					return 1;
//				}else if(s1.charAt(0)<s2.charAt(0)){
//					return -11;
//				}else{
//					return 0;
//				}
//			}
//		});
		
		//then do "order preserving naming" for T1 in O(n)
		int logN = (int)Math.ceil(Math.log10(len)/Math.log10(2));
		int[][] N = new int[logN+1][len]; //N[i][j] represents "order preserving name" of jth suffix in N.2^i
		
		for (int i = 0; i < len; i++) {
			if(i>0&&sortedChars[i]==sortedChars[i-1])
				continue;
			//N.2^0 : N1
			for (int j = 0; j < len; j++) {
				if(chars[j]==sortedChars[i])
					N[0][j] = i;
			}
		}
		
		int l;
		Point[] T2lPairs; //pairs to be sorted using comparator
		Comparator<Point> pairsComparator = new Comparator<Point>() {
				public int compare(Point o1, Point o2) {
					if(o1.x<o2.x){
						return -1;
					}else if(o1.x==o2.x){
						if(o1.y<o2.y)
							return -1;
						else if(o1.y==o2.y)
							return 0;
						else
							return 1;
					}else
						return 1;
				}
			};
		
		//produce T2,T4,T8,... from T1, logn steps each in O(n) : O(nlogn)	
		for (int i = 1; i <= logN; i++) {
			l = (int)Math.pow(2, i);
			//N.2^i : Nl
			T2lPairs = new Point[len];
			for (int j = 0; j < len; j++) {
				T2lPairs[j] = new Point(N[i-1][j],N[i-1][Math.min(j+l,len-1)]);
				T2lPairs[j].i = j;
			}

			//sort the pairs in O(n) using radix sort for nlogn time
			
			//sort using merge in O(nlogn) ,, total time will be n(logn)^2
			Arrays.sort(T2lPairs, pairsComparator);
			
			for (int j = 1; j < len; j++) {
				if(pairsComparator.compare(T2lPairs[j],T2lPairs[j-1])==0)
					N[i][T2lPairs[j].i] = N[i][T2lPairs[j-1].i];
				else
					N[i][T2lPairs[j].i] = j;
			}
		}
		
		int[] SA = new int[len];
		for (int i = 1; i < SA.length; i++) {
			SA[N[logN][i]] = i;
		}
		return Arrays.copyOfRange(SA, 1, len);
	}
	static class Point{
		int x;
		int y;
		int i;
		public Point(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}
		public String toString() {
			return "(" + x + "," + y + ")";
		}
	}
}
