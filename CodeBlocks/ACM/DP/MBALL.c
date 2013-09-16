#include <stdio.h>

#define max(x,y) ((x>y)?x:y)

int t, n, i,j, v[10]={2,3,6,7,8};
long long dp[100005];

int main(){
    scanf("%d", &t);
    dp[0]=1;
    for(j=0; j<5; j++){
        for(i=v[j]; i<100002; i++){
            dp[i] += dp[i-v[j]];
        }
    }
    while(t--){
        scanf("%d", &n);
        printf("%lld\n", dp[n]);
    }
    return 0;
}
