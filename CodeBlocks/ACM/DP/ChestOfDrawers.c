#include <stdio.h>

long long dp[70][70][2];

void recur(int n, int s, int prev){
    if(n==0){
        if(s==0)
            dp[n][s][prev]=1;
        else
            dp[n][s][prev]=0;
        return;
    }
    if(dp[n][s][prev]>-1)
        return;
    if(prev){
        recur(n-1,s,0);
        recur(n-1,s-1,1);
        dp[n][s][1] = dp[n-1][s][0]+dp[n-1][s-1][1];
    }else{
        recur(n-1,s,0);
        recur(n-1,s,1);
        dp[n][s][0] = dp[n-1][s][0]+dp[n-1][s][1];
    }
}

int main(void){
    int n, s, i, j;
    while(1){
        scanf("%d %d", &n, &s);
        if(n<0 && s<0)
            break;
        for(i=0; i<=n ; i++){
            for(j=0; j<=s ; j++){
                dp[i][j][0]=-1ll;
                dp[i][j][1]=-1ll;
            }
        }
        recur(n, s, 1);
        printf("%lld\n", dp[n][s][1]);
    }
    return 0;
}
