#include <stdio.h>
#include <string.h>

int n, k, si[42];
long long dp[42][42];

long long recur(int i, int open){
    if(i==2*n && open==0)
        return 1;
    if(i==2*n)
        return 0;
    if(dp[i][open]!=-1)
        return dp[i][open];
    if(si[i] || open==0) return dp[i][open] = recur(i+1, open+1);
    return dp[i][open] = recur(i+1, open+1) + recur(i+1, open-1);
}

int main(){
    int t, i, s;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        memset(si, 0, sizeof si);
        memset(dp, -1, sizeof dp);
        for(i=0; i<k; i++) {
            scanf("%d", &s);
            si[--s] = 1;
        }
        printf("%ld\n", recur(0,0));
    }
    return 0;
}
