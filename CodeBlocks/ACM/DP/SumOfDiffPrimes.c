#include <stdio.h>
#include <string.h>

int dp[1125][1125][20];

#define MAXSIEVE 1125
#define MAXSIEVEHALF 565
#define MAXSQRT 35

short a[MAXSIEVEHALF];
int primes[1000];

void sieve(){
    int i, j, k;
    primes[0]=2;
    for(i=1,k=1;i<MAXSQRT;i++)
        if(a[i]==0){
            primes[k++]=i+i+1;
            for(j=2*i*i+i+i;j<MAXSIEVEHALF;j+=i+i+1)
                a[j]=1;
        }
    for(; i<MAXSIEVEHALF; i++)if(a[i]==0)primes[k++]=i+i+1;
}

int recur(int n, int i, int k){
    if(n==0 && k==0)
        return 1;
    if(n==0 || k==0)
        return 0;
    if(primes[i]>n)
        return 0;
    if(dp[n][i][k]!=-1)
        return dp[n][i][k];
    return dp[n][i][k] = recur(n, i+1 , k) + recur(n-primes[i], i+1, k-1);
}

int main(){
    int n, k, i;
    sieve();
    memset(dp, -1, sizeof dp);
    while(1){
        scanf("%d %d", &n, &k);
        if(n==0&&k==0)
            break;
        printf("%d\n", recur(n, 0, k));
    }
    return 0;
}
