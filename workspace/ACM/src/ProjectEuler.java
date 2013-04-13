import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class ProjectEuler{
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		BigInteger sum = new BigInteger("0");
		for (int i = 0; i < 100; i++) {
			sum = sum.add(new BigInteger(br.readLine()));
		}
		System.out.println(sum);
	}
}//5537376230390876637302048746832985971773659831892672