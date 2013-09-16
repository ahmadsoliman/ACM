#include <stdio.h>

int w, dp[100][20][20];

int recur(int col, int c1, int c2){
    if(dp[col][c1][c2]!=-1)
        return dp[col][c1][c2];
    if(col==0){
        if(c1==1||c1==4||c1==5||c1==7) return dp[col][c1][c2] = 1;
        return dp[col][c1][c2] = 0;
    }
    int i;
    for(i=0; i<3; i++){
        if((c1&(1<<i))) continue;
        return dp[col][c1][c2] = ((i<2 && !(c1&(1<<i)) && !(c1&(1<<(i+1))))? recur(col, c1|(1<<i)|(1<<(i+1)), c2) : 0) +
            ((!(c1&(1<<i)) && !(c2&(1<<i)))? recur(col, c1|(1<<i), c2|(1<<i)) : 0);
    }
    return dp[col][c1][c2] = recur(col-1, c2, 0);
}

int main(){
    int i;
    memset(dp, -1, sizeof dp);
    while(scanf("%d", &w)){
        if(w==-1) return 0;
        if(w==0) printf("1\n");
        else if(w==1) printf("0\n");
        else printf("%d\n", recur(w-1, 0, 0));
    }
    return 0;
}
