package COCI;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Poredak {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		
		String[] ordered = br.readLine().split(" ");
		String[] unordered = br.readLine().split(" ");
		
		int[] orderedIndices = new int[N];
		for (int i = 0; i < orderedIndices.length; i++) {
			for (int j = 0; j < orderedIndices.length; j++) {
				if(unordered[i].equals(ordered[j])){
					orderedIndices[i] = j;
					break;
				}
			}
		}
		
		int score=0;
		for (int i = 0; i < unordered.length; i++) {
			int indexInOrdered=orderedIndices[i];
			for (int j = i+1; j < unordered.length; j++) {
				if(indexInOrdered<orderedIndices[j])
					score++;
			}
		}
		System.out.println(score+"/"+((N*(N-1))/2));
	}
}
