package Contests;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;

public class FuzzyGoogleSuggest4769 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(br.readLine().trim()), m;
		String s;
		Trie t=new Trie('#');
		for (int i = 0; i < n; i++) {
			s = br.readLine().trim();
			addw(t, s);
		}
		String in[];
		int thre, cnt;
		m=Integer.parseInt(br.readLine().trim());
		for (int i = 0; i < m; i++) {
			in = br.readLine().split("\\s");
			s=in[0].trim();
			thre=Integer.parseInt(in[1].trim());
			
			set=new HashSet<String>();
			for (int j = 0; j < s.length(); j++) {
				count(t, s.substring(j), thre);
			}
			System.out.println(set.size());
		}
	}
	static HashSet<String> set;
	public static void count(Trie t, String s, int thre){	
		if(thre<0) return;
		int c = s.charAt(0)-'a';
		for (int i = 0; i < 26; i++) {
			if(t.elems[i]!=null){
				if(s.length()==1){
					if(c==i||thre>0) {
						//TODO
					}
				}else count(t.elems[i], s.substring(1), (c==i)?thre:thre-1);
			}
		}
	}
	public static void addw(Trie t, String s){
		if(s.length()==0) return;
		t.add(s.charAt(0));
		addw(t.elems[s.charAt(0)-'a'], s.substring(1));
	}

	static class Trie{
		int cnt;
		char c;
		Trie[] elems;
		public Trie(char c1){
			this.cnt=1;
			this.c=c1;
			elems = new Trie[26];
		}
		public void add(char c){
			if(this.elems[c-'a']==null) this.elems[c-'a']=new Trie(c);
			else{
				this.cnt++;
			}
		}
	}
}
