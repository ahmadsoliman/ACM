#include <stdio.h>
#include <string.h>

int n, dp[105][105][2];

int recur(int i, int k, int last){
    if(i==n&&k==0)
        return 1;
    if(i==n||k<0)
        return 0;
    if(dp[i][k][last]!=-1)
        return dp[i][k][last];
    return dp[i][k][last] = recur(i+1, k, 0) + recur(i+1, ((last)?(k-1):k), 1);
}

int main(){
    int t, k, kase;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &kase, &n, &k);
        memset(dp, -1, sizeof dp);
        printf("%d %d\n", kase, recur(0, k, 0));
    }
    return 0;
}
