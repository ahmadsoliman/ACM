package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class JAVAC {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String in;
		StringBuffer res;
		while((in = br.readLine())!=null){
			res = new StringBuffer();
			if(in.contains("_")){
				if(!in.toLowerCase().equals(in) || in.contains("__") || in.charAt(0)=='_' || in.charAt(in.length()-1)=='_'){
					System.out.println("Error!");
					continue;
				}
				for (int i = 0; i < in.length(); i++) {
					if(in.charAt(i)=='_'){
						if(i<in.length()-1)
							res.append(Character.toUpperCase(in.charAt(++i)));//might give WA on asgadg_
					}else{
						res.append(in.charAt(i));
					}
				}
				System.out.println(res);
			}else{
				if(Character.isUpperCase(in.charAt(0))){
					System.out.println("Error!");
					continue;
				}
				for (int i = 0; i < in.length(); i++) {
					if(Character.isUpperCase(in.charAt(i))){
						res.append('_');
						res.append(Character.toLowerCase(in.charAt(i)));
					}else{
						res.append(in.charAt(i));
					}
				}
				System.out.println(res);
			}
		}
	}
}
