package UVA;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class EuclidProblem {
	// Extended Euclidean Algorithm
	public static int[] eGCD(int m, int n) {
		if (m == 0)
			return new int[] { 0, 1, n };
		int[] tmp = eGCD(n % m, m);
		return new int[] { tmp[1] - (n / m) * tmp[0], tmp[0], tmp[2] };
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String in, comps[];
		while ((in = br.readLine()) != null) {
			comps = in.split(" ");
			int[] res = eGCD(Integer.parseInt(comps[0]),
					Integer.parseInt(comps[1]));
			System.out.println(Math.min(res[0], res[1]) + " "
					+ Math.max(res[0], res[1]) + " " + res[2]);
		}
	}
}
