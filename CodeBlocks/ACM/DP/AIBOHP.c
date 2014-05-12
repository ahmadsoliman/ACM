#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define max(x,y) ((x>y)?x:y)

char s[6105], rev[6105];
short dp[6105][6105];

int main(){
    int t, len, i,j,k;
    scanf("%d", &t);
    while(t--){
        scanf("%s", s);
        len = strlen(s);
        for(i=0; i<len; i++) rev[len-i-1]=s[i];

        for(i=0; i<len; i++){
            for(j=0; j<len; j++){
                if(s[i]==rev[j]){
                    dp[i][j] = 1;
                    if(i>0&&j>0) dp[i][j]+=dp[i-1][j-1];
                } else{
                    dp[i][j]=0;
                    if(i>0) dp[i][j]=dp[i-1][j];
                    if(j>0 && dp[i][j-1]>dp[i][j]) dp[i][j]=dp[i][j-1];
                }
                //printf("%d ", dp[i][j]);
            }
            //printf("\n");
        }
        printf("%d\n", len-dp[len-1][len-1]);
    }
    return 0;
}
/*

*/
