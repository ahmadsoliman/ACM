#include <stdio.h>
#include <string.h>
int likes[20][20], n;
long long dp[20][1048578];
long long recur(int i, int bm){
    if(i==n) return 1;
    if(dp[i][bm]!=-1) return dp[i][bm];
    int k, tmp;
    long long sum=0;
    for(k=0, tmp=1; k<n; k++, tmp<<=1)if(likes[i][k] && !(bm&tmp)) sum += recur(i+1, bm|tmp);
    return dp[i][bm]=sum;
}
int main(){
    int t, i, j, twoN;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i=0; i<n; i++) for(j=0; j<n; j++) scanf("%d", &likes[i][j]);
        twoN=(1<<n);
        for(i=0; i<n; i++) for(j=0; j<twoN; j++) dp[i][j]=-1;
        printf("%ld\n", recur(0,0));
    }
    return 0;
}
