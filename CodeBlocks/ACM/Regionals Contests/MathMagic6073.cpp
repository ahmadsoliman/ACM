#include <stdio.h>
#include <math.h>
#include <string.h>

#define MOD 1000000007

int M;

int gcd(int n, int m){
    if(n==0) return m;
    return gcd(m%n, n);
}

int lcm(int n, int m){
    return n*(m/gcd(n,m));
}

int dp[101][1001][1001];

int recur(int k, int N, int LCM){
    if(k==0) {
        if(N==0&&LCM==M) return 1;
        return 0;
    }

    if(dp[k][N][LCM]!=-1) return dp[k][N][LCM];

    int i, sum=0, l;

    for(i=1;i<=N; i++){
        l=lcm(LCM, i);
        if(l<=M) sum = (sum+recur(k-1, N-i, l))%MOD;
    }
    return dp[k][N][LCM]=sum;
}

int main(){
    int n, k;
    while(scanf("%d %d %d", &n, &M, &k)>0){
        memset(dp, -1, sizeof dp);
        printf("%d\n", recur(k, n, 1));
    }
    return 0;
}
