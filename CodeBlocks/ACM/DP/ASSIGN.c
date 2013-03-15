#include <stdio.h>
#include <string.h>

int likes[21][21], n;
long long dp[21][21];

long long recur(int i, int j){
    if(i==-1)return 1;
    if(dp[i][j]>-1)return dp[i][j];
    int k;
    long long sum=0ll;
    for(k=0; k<n; k++){
        if(likes[i][k])sum+=(dp[i][j] = recur(i-1, k));
    }
    return dp[i][j]=sum;
}

int main(){
    int t, i, j;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                scanf("%d", &likes[i][j]);
            }
        }
        memset(dp, -1, sizeof dp);
        long long sum=0ll;
        for(j=0; j<n; j++){
            if(likes[0][j])sum+=recur(n-2,j);
        }
        printf("%lld\n", sum);
    }
    return 0;
}
