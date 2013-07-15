#include <stdio.h>
#include <string.h>

#define min(x,y) ((x<y)?x:y)

int n, c[101], f[101], dp[101][501], dp2[101][501];

int recur(int i, int b){
    if(i==n){
        dp2[i][b] = 0;
        return dp[i][b] = 0;
    }
    if(dp[i][b]!=-1)
        return dp[i][b];
    int d=recur(i+1, b), e=0;
    if(b>=c[i]) e=f[i]+recur(i+1,b-c[i]);
    if(d>e){
        dp2[i][b] = dp2[i+1][b];
        return dp[i][b] = d;
    }else if(d<e){
        dp2[i][b] = c[i]+dp2[i+1][b-c[i]];
        return dp[i][b] = e;
    }else{
        dp2[i][b] = min(dp2[i+1][b], c[i]+dp2[i+1][b-c[i]]);
        return dp[i][b] = d;
    }
}

int main(){
    int b,i,m,x,y;
    while(scanf("%d %d", &b, &n)>0){
        if(b==0&&n==0) return 0;
        for(i=0; i<n; i++) scanf("%d %d", &c[i], &f[i]);

        memset(dp, -1, sizeof dp);
        x=recur(0, b);
        printf("%d %d\n", dp2[0][b], x);
    }
    return 0;
}
