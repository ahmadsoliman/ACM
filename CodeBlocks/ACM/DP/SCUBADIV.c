#include <stdio.h>
#include <string.h>

#define INF 1000000000

int c, oxy[1005], nitro[1005], w[1005], dp[1005][25][85];

int recur(int i, int o, int n){
    if(o<=0&&n<=0)
        return 0;
    if(i==c)
        return INF;

    if(o<0)
        o=0;
    if(n<0)
        n=0;

    if(dp[i][o][n]!=-1)
        return dp[i][o][n];

    int a = recur(i+1, o, n), b = recur(i+1, o-oxy[i], n-nitro[i]) + w[i];
    return dp[i][o][n] = (a<b)?a:b;
}

int main(){
    int t, o, n, i;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &o, &n);
        scanf("%d", &c);

        memset(dp, -1, sizeof dp);

        for(i=0; i<c; i++) scanf("%d %d %d", &oxy[i], &nitro[i], &w[i]);
        printf("%d\n", recur(0, o, n));
    }
    return 0;
}
