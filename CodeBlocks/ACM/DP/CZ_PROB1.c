#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define min(x,y) (((x)<(y))?(x):(y))
#define EPS 1e-8
#define MAXSIEVE 10000
#define MAXSIEVEHALF 5000
#define MAXSQRT 71

short a[5000];
int primes[2000];

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

int sqrs[10000], sqrprimes[550];
long long dp[10000][5];

long long recur(int n, int k){
    if(n==0) return 1;
    if(dp[n][k]!=-1) return dp[n][k];
    long long cnt=0; int i;
    for(i=min(k,n); i>0; i--){
        cnt += recur(n-i, i);
    }
    return dp[n][k]=cnt;
}

int main(){
    sieve();
    int t,n,k, i,j,l, issqr,b,sqrc=0;
    double sqrtb;

    for(i=0; i<1050; i++) sqrs[i]=i*i;
    for(i=0; i<1050; i++){
        issqr=0;
        for(j=1; sqrs[j]<primes[i]; j++){
            sqrtb = sqrt(primes[i]-sqrs[j]);
            if(fabs(sqrtb-(int)sqrtb)<EPS){ issqr=1; break; }
        }
        if(issqr) sqrprimes[sqrc++]=primes[i];
    }
    memset(dp, -1, sizeof dp);

    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        printf("%lld\n", recur(sqrprimes[n-1], k));
    }
    return 0;
}
