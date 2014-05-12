package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map.Entry;

public class STRINGS {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    int t, i,j,k, l1, l2, cnt=0, kase=1;
	    Integer strc;
	    
		t = Integer.parseInt(br.readLine().trim());
		String s1, s2;
		HashMap<String, Integer> m2;
		HashSet<String> m1;
		while(t-->0){
			s1 = br.readLine().trim();
			s2 = br.readLine().trim();
			l1 = s1.length();
			l2 = s2.length();
			k = Integer.parseInt(br.readLine().trim());
			
			m1 = new HashSet<>();
			for(i=0; i<l1; i++){
			    for(j=i+1; j<=l1; j++){
			    	m1.add(s1.substring(i, j));
			    }
			}
			/*
			m2 = new HashMap<>();
			for(i=0; i<l2; i++){
			    for(j=i+1; j<=l2; j++){
			    	strc = m2.get(s2.substring(i, j));
			    	if(strc==null) m2.put(s2.substring(i, j), 1);
			        else m2.put(s2.substring(i, j), strc+1);
			    }
			}
			
			cnt=0;
			for(Entry<String, Integer> e : m2.entrySet()){
				if(e.getValue()==k && m1.contains(e.getKey())) cnt++;
			}
			*/
			System.out.println("Case #"+ kase++ +":\n"+ cnt);
		}
	}
}
