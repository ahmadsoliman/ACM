#include <stdio.h>
#include <string.h>

int N, K, dp[105][105];

int count(int n, int k){
    if(n==0){
        if(k==0)
            return 1;
    }
    if(k==0)
        return 0;
    if(dp[n][k]>-1)
        return dp[n][k];

    int countS=0, i;
    for(i=0; i<=n; i++)
        countS=(countS+count(n-i, k-1))%1000000;
    return dp[n][k]=countS;
}

int main(){
    while(scanf("%d %d", &N, &K)>0){
        if(N==0&&K==0)
            break;
        memset(dp, -1, sizeof dp);
        printf("%d\n", count(N,K));
    }
    return 0;
}
