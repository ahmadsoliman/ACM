#include <stdio.h>
#include <math.h>

long long dp[100];

int main(){
    int i, n;
    dp[1]=dp[1]=1;
    scanf("%d", &n);
    for(i=2; i<=n; i++) dp[i]=dp[i-1]+dp[i-2];
    long long res=0;
    for(i=1; i<=n; i++) res+=dp[i];
    printf("%lld\n", res);
    return 0;
}
