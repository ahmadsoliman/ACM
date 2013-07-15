#include <stdio.h>

int dp[10001];

int main(){
    int n,i, fact;
    for(i=1, dp[0]=1, fact = 1; i<10001; i++){
        fact *= i;
        while(fact%10==0) fact/=10;
        fact %= 100000;
        dp[i] = fact%10;
    }

    while(scanf("%d", &n)>0) {

        printf("%5d -> %d\n", n, dp[n]);
    }
    return 0;
}
