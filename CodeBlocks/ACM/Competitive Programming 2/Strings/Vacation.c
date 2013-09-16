#include <stdio.h>
#include <string.h>

char s1[110], s2[110];
int kase, i, j, n1, n2, dp[105][105];

int main(){
    kase=1;
    while(1){
        gets(s1);
        if(s1[0]=='#') return 0;
        gets(s2);

        n1 = strlen(s1);
        n2 = strlen(s2);

        for(i=0; i<n1; i++){
            for(j=0; j<n2; j++){
                if(s1[i]==s2[j]){
                    dp[i][j] = 1;
                    if(i>0&&j>0) dp[i][j]+=dp[i-1][j-1];
                } else{
                    dp[i][j]=0;
                    if(i>0) dp[i][j]=dp[i-1][j];
                    if(j>0 && dp[i][j-1]>dp[i][j]) dp[i][j]=dp[i][j-1];
                }
            }
        }

        printf("Case #%d: you can visit at most %d cities.\n", kase++, dp[n1-1][n2-1]);
    }
    return 0;
}
