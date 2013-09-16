package Contests;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

public class Abbreviations {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine()), caseNum=1;
		Pair[] words;
		int abrvs[];
		while(N>0){
			words = new Pair[N];
			abrvs = new int[N];
			for (int i = 0; i < N; i++) {
				words[i]=new Pair(br.readLine(), i);
			}
			Arrays.sort(words);
			
			for (int i = 0; i < N; i++) {
				if(i==N-1){
					abrvs[i]++;
					break;
				}
				for (int j = 0; j < words[i].word.length(); j++) {
					if(j<words[i+1].word.length() && words[i].word.charAt(j)==words[i+1].word.charAt(j)){
						abrvs[i]=++abrvs[i+1];
					}else
						break;
				}
				abrvs[i]++;
			}
			Comparator<Pair> c = new Comparator<Pair>() {
				public int compare(Pair o1, Pair o2) {
					if(o1.index>o2.index)
						return 1;
					if(o1.index<o2.index)
						return -1;
					return 0;
				}
			};
			Arrays.sort(words,c);
			System.out.println(caseNum++);
			for (int i = 0; i < N; i++) {
				System.out.println(words[i].word+" "+
					words[i].word.substring(0,(abrvs[i]<words[i].word.length())?abrvs[i]:words[i].word.length()));
			}
			N = Integer.parseInt(br.readLine());
		}
	}
	static class Pair implements Comparable<Pair>{
		String word;
		int index;
		
		public Pair(String word, int index) {
			super();
			this.word = word;
			this.index = index;
		}

		public int compareTo(Pair p) {
			return word.compareTo(p.word);
		}
		
	}
}
