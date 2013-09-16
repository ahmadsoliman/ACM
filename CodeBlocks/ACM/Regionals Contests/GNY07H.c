#include <stdio.h>

int w, dp[100][20][20];

int recur(int col, int c1, int c2){
    if(dp[col][c1][c2]!=-1)
        return dp[col][c1][c2];
    if(col==0){
        if(c1==0||c1==3||c1==9||c1==12||c1==15) return dp[col][c1][c2] = 1;
        return dp[col][c1][c2] = 0;
    }
    int i;
    for(i=0; i<4; i++){
        if((c1&(1<<i))) continue;
        return dp[col][c1][c2] = ((i<3 && !(c1&(1<<i)) && !(c1&(1<<(i+1))))? recur(col, c1|(1<<i)|(1<<(i+1)), c2) : 0) +
            ((!(c1&(1<<i)) && !(c2&(1<<i)))? recur(col, c1|(1<<i), c2|(1<<i)) : 0);
    }
    return dp[col][c1][c2] = recur(col-1, c2, 0);
}

int main(){
    int t, i, kase=1;
    memset(dp, -1, sizeof dp);
    scanf("%d", &t);
    while(t--){
        scanf("%d", &w);
        printf("%d %d\n", kase++, recur(w-1, 0, 0));
    }
    return 0;
}
