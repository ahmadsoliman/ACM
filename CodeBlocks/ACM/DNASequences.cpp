#include <cstdlib>
#include <string>
#include <stdio.h>

using namespace std;

int dp[1010][1010];

int main(int argc, char *argv[]){

        string res = "";
		int k;
		scanf("%d", &k);
		while(k!=0){
            char in[1010];
            scanf("%s", in);
            string s1(in);
            printf("%s" , in);
            scanf("%s", in);
            string s2(in);

			int m = s1.length(), n=s2.length();

	        // compute length of LCS and all subproblems via dynamic programming
			for (int i = m-1; i>=0; i--) {
				for (int j = n-1; j>=0; j--) {
					if(s1[i]==s2[j])
						dp[i][j] = dp[i+1][j+1] + 1;
					else
						dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
				}

	        // recover LCS itself
			string lcs;
			int i, j ,kCount, maxLCS=0, len;
			int failed;

			// loop for m
			for (int l = 0; l < m; l++) {
				lcs = "";
				i = l; j = 0;
				while(i<m&&j<n)
					if(s1[i]==s2[j]){
						lcs+=s1[i];
						i++;
						j++;
					}else if(dp[i+1][j] >= dp[i][j+1])
						i++;
					else
						j++;

				failed = 0;
				//inner loop for m
				i = 0; j = 0; kCount = 0;
				len = lcs.length();
				if(len<maxLCS)
					break;
				while(i<m&&j<len)
					if(s1[i]==lcs[j]){
						i++;
						j++;
						kCount++;
					}else{
						i++;
						if(kCount>0 && kCount<k){
							failed = 1;
							break;
						}
						kCount=0;
					}
				if(kCount>0 && kCount<k)
					failed = 1;

				// inner loop for n
				i = 0; j = 0; kCount = 0;
				while(i<n&&j<len)
					if(s2[i]==lcs[j]){
						i++;
						j++;
						kCount++;
					}else{
						i++;
						if(kCount>0 && kCount<k){
							failed = 1;
							break;
						}
						kCount=0;
					}
				if(!(kCount>0 && kCount<k) && !failed && len>maxLCS)
					maxLCS = lcs.length();
			}

			// loop for n
            for (int l = 0; l < n; l++) {
				lcs = "";
				i = 0; j = l;
				while(i<m&&j<n)
					if(s1[i]==s2[j]){
						lcs+=s1[i];
						i++;
						j++;
					}else if(dp[i+1][j] >= dp[i][j+1])
						i++;
					else
						j++;

				failed = 0;
				//inner loop for m
				i = 0; j = 0; kCount = 0;
				len = lcs.length();
				if(len<maxLCS)
					break;
				while(i<m&&j<len)
					if(s1[i]==lcs[j]){
						i++;
						j++;
						kCount++;
					}else{
						i++;
						if(kCount>0 && kCount<k){
							failed = 1;
							break;
						}
						kCount=0;
					}
				if(kCount>0 && kCount<k)
					failed = 1;

				// inner loop for n
				i = 0; j = 0; kCount = 0;
				while(i<n&&j<len)
					if(s2[i]==lcs[j]){
						i++;
						j++;
						kCount++;
					}else{
						i++;
						if(kCount>0 && kCount<k){
							failed = 1;
							break;
						}
						kCount=0;
					}
				if(!(kCount>0 && kCount<k) && !failed && len>maxLCS)
					maxLCS = lcs.length();
			}

            res += maxLCS;
            res + "\n";

			scanf("%d", &k);
		}
		printf("%s" , res.c_str());
	}
    system("PAUSE");
    return EXIT_SUCCESS;
}
