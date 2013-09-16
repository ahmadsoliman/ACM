package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

//uva

public class CommonPermutation {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		  String s;
		  while ((s = br.readLine()) != null) {
	
			  String a = s, b =br.readLine();
			  int[] occurA = new int[26], occurB = new int[26];
			  for (int i = 0; i < a.length(); i++) {
				  char c = Character.toLowerCase(a.charAt(i));
				  if(c==' ')continue;
				  occurA[c-'a']++;
			  }
			  for (int i = 0; i < b.length(); i++) {
				  char c = Character.toLowerCase(b.charAt(i));
				  if(c==' ')continue;
				  occurB[c-'a']++;
			  }
			  
			  ArrayList<Character> res = new ArrayList<Character>();
			  for (int i = 0; i < occurA.length; i++) {
				  int min = Math.min(occurA[i], occurB[i]);
				  for (int j = 0; j < min; j++) {
					  res.add(new Character(Character.toLowerCase((char)(i+'a'))));
				  }
			  }
			  char[] resArray = new char[res.size()];
			  for (int i = 0; i < resArray.length; i++) {
				  resArray[i] = res.get(i).charValue();
			  }
			  Arrays.sort(resArray);
			  StringBuffer resString = new StringBuffer();
			  for (int i = 0; i < resArray.length; i++) {
				  resString.append(resArray[i]);
			  }
			  System.out.println(resString.toString());
		  }
	}
}
