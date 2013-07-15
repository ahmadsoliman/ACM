#include <stdio.h>
#include <string.h>

#define INF 1000000000

int n, times[101][101], risks[101][101], dp[101][251], dp2[101][251];

int recur(int a, int T){
    if(a==n-1) return 0;
    if(dp[a][T]!=-1)
        return dp[a][T];
    int curC, minC=INF, i, minT=INF;
    for(i=0; i<n; i++){
        if(i!=a&&times[a][i]<=T){
            curC = risks[a][i] + recur(i,T-times[a][i]);
            if(curC<minC) {
                minC = curC;
                minT = times[a][i]+dp2[i][T-times[a][i]];
            }
        }
    }
    dp2[a][T] = minT;
    return dp[a][T] = minC;
}

int main(){
    int t, T, i, j, res;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &T);
        for(i=0; i<n; i++) for(j=0; j<n; j++) scanf("%d", &times[i][j]);
        for(i=0; i<n; i++) for(j=0; j<n; j++) scanf("%d", &risks[i][j]);
        memset(dp, -1, sizeof dp);
        res = recur(0,T);
        if(res>=INF)
            printf("-1\n");
        else
            printf("%d %d\n", res, dp2[0][T]);
    }
    return 0;
}
