#include <stdio.h>
#include <string.h>

int n, x[1005], y[1005], dp[1005];

int recur(int i){
    if(i==n)
        return 0;
    if(last>-1 && dp[last][i]!=-1)
        return dp[last][i];

    int a = ((last>-1)?((last==0)?abs(y[i-1]-y[i]):abs(x[i-1]-y[i])):0) + x[i] + recur(0, i+1),
        b = ((last>-1)?((last==0)?abs(y[i-1]-x[i]):abs(x[i-1]-x[i])):0) + y[i] + recur(1, i+1);
    return dp[last][i] = (a>b)?a:b;
}

int main(){
    int i;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d %d", &x[i], &y[i]);
    memset(dp, -1, sizeof dp);
    printf("%d\n", recur(-1, 0));
    return 0;
}
