#include <stdio.h>
#define MAX (100000000)
#define MOD (1000000007)

int dp[MAX];

int main(){
    int t,i;
    dp[0]=1;dp[1]=2;dp[2]=5;dp[3]=12;
    for(i=4; i<MAX; i++)dp[i]=((dp[i-1]+(2*dp[i-2])%MOD)%MOD+((3*dp[i-3])%MOD+dp[i-4])%MOD)%MOD;
    long long N = 0ll;
    scanf("%d", &t);
    while(t--){
        scanf("%lld", &N);
        printf("%d\n", dp[N-1]);
    }
    return 0;
}
