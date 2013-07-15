#include <stdio.h>
#include <string.h>

#define abs(x) ((x<0)?-1*x:x)
#define min(x,y) ((x<y)?x:y)

int coins[105], n;

int dp[105][100000];

int recur(int i, int a, int b){
    if(i==n){
        int r = a-b;
        return abs(r);
    }
    if(dp[i][a-b+50000]!=-1)
        return dp[i][a-b+50000];
    return dp[i][a-b+50000] = min(recur(i+1, a+coins[i], b),recur(i+1, a, b+coins[i]));
}

int main(){
    int t, i;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i=0; i<n; i++) scanf("%d", &coins[i]);
        memset(dp, -1, sizeof dp);
        printf("%d\n", recur(0,0,0));
    }
    return 0;
}
