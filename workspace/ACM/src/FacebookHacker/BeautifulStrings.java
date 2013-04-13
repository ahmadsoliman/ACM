package FacebookHacker;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class BeautifulStrings {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new FileReader("G:\\beautiful_stringstxt.txt"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("G:\\output.txt"));
		int t = Integer.parseInt(br.readLine()), product, beauty;
		String in;
		int[] chars;
		for (int i = 0; i < t; i++) {
			in = br.readLine().toLowerCase();
			chars=new int[200];
			for (int j = 0; j < in.length(); j++) {
				if(in.charAt(j)>'z'||in.charAt(j)<'a')continue;
				chars[in.charAt(j)]++;
			}
			Arrays.sort(chars);
			beauty=0;
			product=26;
			for (int j = chars.length-1; j >0 ; j--) {
				if(chars[j]==0)
					break;
				beauty+=chars[j]*product--;
			}
			bw.write("Case #"+(i+1)+": "+beauty);
			bw.newLine();
		}
		br.close();
		bw.close();
	}
}
