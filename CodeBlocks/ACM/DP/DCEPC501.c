#include <stdio.h>
#include <stdio.h>
#define max(x,y) ((x>y)?x:y)

int n, price[100001];
long long dp[100001];

long long recur(int i){
    if(i>=n) return 0;
    if(dp[i]!=-1) return dp[i];
    long long a=price[i]+recur(i+2),b=0,c=0;
    if(i<n-1) b=price[i]+price[i+1]+recur(i+4);
    if(i<n-2) c=price[i]+price[i+1]+price[i+2]+recur(i+6);
    return dp[i]=max(a,max(b,c));
}

int main(){
    int t, i;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0; i<n; i++) scanf("%d", &price[i]);
        memset(dp, -1, sizeof dp);
        printf("%lld\n", recur(0));
    }
    return 0;
}
