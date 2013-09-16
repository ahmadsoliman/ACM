package FacebookHacker;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;

public class FindTheMin {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new FileReader("G:\\FindTheMin.txt"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("G:\\output.txt"));
		int t = Integer.parseInt(br.readLine()), n,k,b,c,r,count,found,nth;
		int[] m;
		String[] in;
		for (int i = 0; i < t; i++) {
			in = br.readLine().split(" ");
			n=Integer.parseInt(in[0]);
			k=Integer.parseInt(in[1]);
			m=new int[k];
			in = br.readLine().split(" ");
			m[0]=Integer.parseInt(in[0]);
			b=Integer.parseInt(in[1]);
			c=Integer.parseInt(in[2]);
			r=Integer.parseInt(in[3]);
			for (int j = 1; j < k; j++) {
				m[j]=(b*m[j-1]+c)%r;
			}
			Arrays.sort(m);
			System.out.println(Arrays.toString(m));
			nth=n-k;
			count=k + m[0];
			found = 0;
			if(count>=n){
				found=nth;
			}else{
				for (int j = 1; j < k; j++) {
					if(count+m[j]-m[j-1]>=n){
						for (int j2 = m[j-1]+1; j2 < m[j]; j2++) {
							count++;
							if(count==n){
								found = j2;
								break;
							}
						}
					}
					else
						count+=m[j]-m[j-1];
					if(found>0)
						break;
				}
			}
			if(count<n){
				found=m[k-1]+nth;
			}
			bw.write("Case #"+(i+1)+": "+found);
			bw.newLine();
		}
		br.close();
		bw.close();
	}
}

//5
//97 39
//34 37 656 97
//186 75
//68 16 539 186
//137 49
//48 17 461 137
//98 59
//6 30 524 98
//46 18
//7 11 9 46
