package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class PERMUT2 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String in = br.readLine();
		String[] arr;
		while(!in.equals("0")){
			arr = br.readLine().split(" ");
			
			boolean ambigous = true;
			for (int i = 0; i < arr.length; i++) {
				if(!arr[Integer.parseInt(arr[i])-1].equals(""+(i+1))){
					ambigous = false;
					break;
				}
			}
			if(ambigous)
				System.out.println("ambiguous");
			else
				System.out.println("not ambiguous");
			
			in = br.readLine();
		}
	}
}
