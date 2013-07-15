#include <stdio.h>
#include <string.h>

#define INF 1000000000000000000ll
#define min(x,y) ((x<y)?x:y)

int N, costs[100005][3];
long long dp[100005][3];

int main(){
    int i, j, kase=1;
    while(scanf("%d", &N)>0){
        if(N==0)
            break;
        for(i=0; i<N; i++) scanf("%d %d %d", &costs[i][0], &costs[i][1], &costs[i][2]);
        dp[N-1][0] = costs[N-1][0]+costs[N-1][1];
        dp[N-1][1] = costs[N-1][1];
        dp[N-1][2] = INF;
        for(i=N-2; i>=0; i--){
            dp[i][2] = costs[i][2] + min(dp[i+1][2], dp[i+1][1]);
            dp[i][1] = costs[i][1] + min(min(dp[i][2], dp[i+1][2]), min(dp[i+1][1], dp[i+1][0]));
            dp[i][0] = costs[i][0] + min(dp[i][1], min(dp[i+1][1], dp[i+1][0]));
        }
        printf("%d. %ld\n", kase++, dp[0][1]);
    }
    return 0;
}
