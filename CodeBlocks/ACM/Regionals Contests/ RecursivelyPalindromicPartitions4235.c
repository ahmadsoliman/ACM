#include <string.h>
#include <stdio.h>

int dp[1000010];

int recur(int n){
    if(n==0||n==1) return 1;
    if(dp[n]!=-1) return dp[n];
    int b, c=0, a;
    for(b=0; b<=n; b++){
        if(b&1) continue;
        c+=recur(b/2);
    }
    return dp[n]=c;
}

int main(){
    int kase=1, t, n;
    scanf("%d", &t);
    memset(dp, -1, sizeof dp);
    while(t--){
        scanf("%d", &n);
        printf("%d %d\n", kase++, recur(n));
    }
    return 0;
}
