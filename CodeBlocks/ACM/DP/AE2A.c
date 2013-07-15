#include <stdio.h>
#include <string.h>
#include <math.h>

int dp[7000][7000];

int k, sol;

int recur(int n){
    if(n==0 && k==0) return 0;
    if(n==0) return -INF;
    int i;
    for(i=1; i<=6; i++) recur(n-1, k-i);
    return c;
}

int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        memset(dp, -1, sizeof dp);
        sol=0;
        recur(n, k);
        printf("%d\n", (int)(sol*100/pow(6,n)));
    }
    return 0;
}
