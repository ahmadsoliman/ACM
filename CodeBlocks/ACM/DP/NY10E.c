#include <stdio.h>
#include <string.h>

int n;
long long dp[70][10];

long long recur(int i, int last){
    if(i==0)
        return 1;
    if(dp[i][last]!=-1)
        return dp[i][last];
    int k;
    long long sum=0ll;
    for(k=last; k<10; k++) sum += recur(i-1, k);
    return dp[i][last] = sum;
}

int main(){
    int t, kase=1;
    scanf("%d", &t);
    memset(dp, -1, sizeof dp);
    while(t--){
        scanf("%d %d", &n, &n);
        printf("%d %lld\n", kase++, recur(n,0));
    }
    return 0;
}
