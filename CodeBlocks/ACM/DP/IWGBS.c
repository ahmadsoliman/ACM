#include <stdio.h>

int res, dp[10005][2], vis[10005][2], kase;

int recur(int n, int last){
    if(n==0) return 1;
    if(last!=-1&&vis[n][last]==kase) return dp[n][last];
    if(last!=-1) vis[n][last]=kase;
    res = recur(n-1, 1) + ((last)?recur(n-1, 0):0);
    if(last!=-1) dp[n][last]=res;
    return res;
}

int main(){
    int n;
    kase=1;
    while(scanf("%d", &n)>0) {
        printf("%d\n", recur(n, -1));
        kase++;
    }
    return 0;
}
