package COCI;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Malcolm {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N, K;
		String[] pieces = br.readLine().split(" ");
		N = Integer.parseInt(pieces[0]);
		K = Integer.parseInt(pieces[1]);
		
		int[] names = new int[N];
		for (int i = 0; i < N; i++) {
			names[i] = br.readLine().length();
		}
		
		int goodFrnds=0;
		for (int i = 0; i < N; i++) {
			int len = names[i];
			for (int j = 1; j <= K; j++) {
				if(i+j<N && len==names[i+j])
					goodFrnds++;
			}
		}
		System.out.println(goodFrnds);
	}
}
