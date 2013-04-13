package SPOJ;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class MIRRORED {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String in = br.readLine();
		System.out.println("Ready");
		String space = "  ";
		char c1, c2;
		do{
			c1 = in.charAt(0);
			c2 = in.charAt(1);
			if(c1=='q')
				if(c2=='p')
					System.out.println("Mirrored pair");
				else
					System.out.println("Ordinary pair");
			else if(c1=='p')
					if(c2=='q')
						System.out.println("Mirrored pair");
					else
						System.out.println("Ordinary pair");
			else if(c1=='d')
					if(c2=='b')
						System.out.println("Mirrored pair");
					else
						System.out.println("Ordinary pair");
			else if(c1=='b')
					if(c2=='d')
						System.out.println("Mirrored pair");
					else
						System.out.println("Ordinary pair");
			else
				System.out.println("Ordinary pair");
			in = br.readLine();
		}while(!in.equals(space));
	}
}
