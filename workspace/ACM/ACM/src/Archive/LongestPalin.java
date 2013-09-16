package Archive;

import java.awt.Point;
import java.util.Arrays;

public class LongestPalin {
	public static String longestPalindrome(String str) {
		StringBuffer s = new StringBuffer(str);
		if(checkPalin(str)){
			return s.toString();
		}
		
        int len = s.length();
        int[][] dp = new int[len+1][len+1];
        
        int maxPalinLen = 0;
        Point maxStart = null;
        for (int i = 1; i <= len; i++) {
			for (int j = 1; j <= len; j++) {
				if(s.charAt(i-1)==s.charAt(len-j))
					dp[i][j] = dp[i-1][j-1] + 1;
				if(dp[i][j]>maxPalinLen){
					maxPalinLen = dp[i][j];
					maxStart = new Point(i,j);
				}
			}
		}
        //for (int i = 0; i < dp.length; i++)
			//System.out.println(Arrays.toString(dp[i]));
		
        StringBuffer res = new StringBuffer();
        int x = maxStart.x, y = maxStart.y;
        int index=y; 
        while(x>=0&&y>=0){
        	if(res.length()==maxPalinLen)
        		break;
        	res.append(s.charAt(len-index));
        	index--;
        	x--;
        	y--;
        }
        return res.toString();
    }
	public static boolean checkPalin(String str){
		StringBuffer s = new StringBuffer(str);
		int len = s.length();
		for (int i = 0; i < len/2; i++) {
			if(s.charAt(i)!=s.charAt(len-i-1)){
				return false;
			}
		}
		return true;
	}
	public static void main(String[] args) {
		System.out.println(longestPalindrome("euazbipzncptldueeuechubrcourfpftcebikrxhybkymimgvldiwqvkszfycvqyvtiwfckexmowcxztkfyzqovbtmzpxojfofbvwnncajvrvdbvjhcrameamcfmcoxryjukhpljwszknhiypvyskmsujkuggpztltpgoczafmfelahqwjbhxtjmebnymdyxoeodqmvkxittxjnlltmoobsgzdfhismogqfpfhvqnxeuosjqqalvwhsidgiavcatjjgeztrjuoixxxoznklcxolgpuktirmduxdywwlbikaqkqajzbsjvdgjcnbtfksqhquiwnwflkldgdrqrnwmshdpykicozfowmumzeuznolmgjlltypyufpzjpuvucmesnnrwppheizkapovoloneaxpfinaontwtdqsdvzmqlgkdxlbeguackbdkftzbnynmcejtwudocemcfnuzbttcoew"));
	}
}
