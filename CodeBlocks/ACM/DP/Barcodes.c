#include <stdio.h>

long long dp[55][55][55];

int N,M,K;

void recur(int n, int k, int m){
    if(k<=0 || m<=0){
        dp[n][k][m]=0;
        return;
    }
    if(dp[n][k][m]>-1)
        return;
    if(n==1){
        if(k==1)
            dp[n][k][m]=1;
        else
            dp[n][k][m]=0;
        return;
    }
    recur(n-1,k-1,M);
    recur(n-1,k,m-1);
    dp[n][k][m] = dp[n-1][k-1][M] + dp[n-1][k][m-1];
}

int main(void){
    int i,j,k;
    while(scanf("%d %d %d", &N, &K, &M)>0){
        for(i=0; i<55; i++)
            for(j=0; j<55; j++)
                for(k=0; k<55; k++)
                    dp[i][j][k] = -1;
        recur(N,K,M);
        printf("%lld\n", dp[N][K][M]);
    }
    return 0;
}
