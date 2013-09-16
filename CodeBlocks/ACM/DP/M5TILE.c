#include <stdio.h>

long long dp[100][70][70];

long long recur(int col, int c1, int c2){
    if(dp[col][c1][c2]!=-1)
        return dp[col][c1][c2];
    if(col==0){
        int i,ones=0;
        for(i=0; i<5; i++) if(c1&(1<<i)) ones++;
        if(ones%2==1) return dp[col][c1][c2] = 1;
        return dp[col][c1][c2] = 0;
    }
    int i;
    for(i=0; i<5; i++){
        if((c1&(1<<i))) continue;
        return dp[col][c1][c2] = ((i<4 && !(c1&(1<<i)) && !(c1&(1<<(i+1))))? recur(col, c1|(1<<i)|(1<<(i+1)), c2) : 0) +
            ((!(c1&(1<<i)) && !(c2&(1<<i)))? recur(col, c1|(1<<i), c2|(1<<i)) : 0);
    }
    return dp[col][c1][c2] = recur(col-1, c2, 0);
}

int main(){
    int i;
    memset(dp, -1, sizeof dp);
    for(i=1; i<=17; i++) printf("%lld\n", recur(2*i-1, 0, 0));
    return 0;
}
