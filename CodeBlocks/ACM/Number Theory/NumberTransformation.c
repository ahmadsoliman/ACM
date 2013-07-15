#include <stdio.h>
#include <string.h>

#define MAXSIEVE 1000
#define MAXSIEVEHALF 500
#define MAXSQRT 23

short a[500], k;
int primes[500];

void sieve(){
    int i, j;
    primes[0]=2;
    for(i=1,k=1;i<MAXSQRT;i++)
        if(a[i]==0){
            primes[k++]=i+i+1;
            for(j=2*i*i+i+i;j<MAXSIEVEHALF;j+=i+i+1)
                a[j]=1;
        }
    for(; i<MAXSIEVEHALF; i++)if(a[i]==0)primes[k++]=i+i+1;
}

#define INF 1000000000
int dp[1001][1001];

int recur(int S, int T){
    if(S==T)
        return 0;
    if(S>T)
        return INF;
    if(dp[S][T]!=-1)
        return dp[S][T];
    int i, min=INF, cur;
    for(i=0; primes[i]<S && primes[i]+S<=T; i++){
        if(S%primes[i]==0){
            cur = recur(S+primes[i], T);
            if(cur<min)
                min = cur;
        }
    }
    return dp[S][T] = min+1;
}

int main(){
    int S, T, cur, kase=1;
    sieve();
    memset(dp, -1, sizeof dp);
    while(scanf("%d %d", &S, &T)>0){
        if(S==0&&T==0)break;
        cur = recur(S, T);
        if(cur>=INF)
            cur = -1;
        printf("Case %d: %d\n", kase++, cur);
    }
    return 0;
}
