#include <stdio.h>
#include <string.h>

int N, Q, D, M, arr[201];
long long dp[201][11][21];

int mod(int n, int m){
    while(n<0) n+=m;
    return n%m;
}
long long recur(int i, int left, int sum){
    if(left==0){
        if(mod(sum,D)==0)
            return 1;
        return 0;
    }
    if(i==N)
        return 0;

    if(dp[i][left][sum]!=-1)
        return dp[i][left][sum];

    return dp[i][left][sum] = recur(i+1, left, sum) + recur(i+1, left-1, mod(sum+arr[i],D));
}

int main(){
    int i, sets=1, queries;
    while(scanf("%d %d", &N, &Q)>0){
        if(N==0 && Q==0)
            break;
        for(i=0; i<N; i++) scanf("%d", &arr[i]);
        printf("SET %d:\n", sets++);
        queries=1;
        for(i=0; i<Q; i++) {
            scanf("%d %d", &D, &M);
            memset(dp, -1, sizeof dp);
            printf("QUERY %d: %lld\n", queries++, recur(0, M, 0));
        }
    }
    return 0;
}
