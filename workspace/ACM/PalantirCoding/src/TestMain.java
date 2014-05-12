import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import tables.SingleColumnTableRareResizes;
import tablesExceptions.NonPositiveHeightException;
import tablesExceptions.OutOfTableException;
import tablesExceptions.TablesException;

public class TestMain {
	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int n, nums[];
		n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());

		nums = new int[n];
		for (int i = 0; i < nums.length; i++) {
			nums[i] = Integer.parseInt(st.nextToken());
		}

		SingleColumnTableRareResizes sct;
		try {
			sct = new SingleColumnTableRareResizes(nums);
			
			while (true) {
				
				sct.resize(Integer.parseInt(br.readLine()), Integer.parseInt(br.readLine()));
			}
		} catch (TablesException e) { 
			e.printStackTrace();
		}



	}
}
