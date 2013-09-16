#include <stdio.h>

#define INF 100000000
#define min(x,y) ((x<y)?x:y)
#define max(x,y) ((x>y)?x:y)

int R, C, g[505][505], dp[505][505];

int main(){
    int t, i, j, a, b;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &R, &C);
        for(i=0; i<R; i++) for(j=0; j<C; j++) scanf("%d", &g[i][j]);
        dp[R-1][C-1]=1;
        for(i=R-1; i>=0; i--) {
            for(j=C-1; j>=0; j--) {
                if(i==R-1&&j==C-1) continue;
                dp[i][j]=INF;
                if(i<R-1) dp[i][j] = dp[i+1][j];
                if(j<C-1 && dp[i][j+1]<dp[i][j]) dp[i][j] = dp[i][j+1];
                dp[i][j]-=g[i][j];
                if(dp[i][j]<=0) dp[i][j]=1;
            }
        }
        printf("%d\n", dp[0][0]);
    }
    return 0;
}
