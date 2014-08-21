#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXSIEVE 1000010
#define MAXSIEVEHALF 500010
#define MAXSQRT 708

typedef long long ll;

short a[500010];
int primes[500000];

int sieve(){
    int i, j, k;
    primes[0]=2;
    for(i=1,k=1;i<MAXSQRT;i++)
        if(a[i]==0){
            primes[k++]=i+i+1;
            for(j=2*i*i+i+i;j<MAXSIEVEHALF;j+=i+i+1)
                a[j]=1;
        }
    for(; i<MAXSIEVEHALF; i++)if(a[i]==0)primes[k++]=i+i+1;
    return k;
}

int f[1000015];
ll g[1000005];

void modifiedSieve(){
    int i,j, k;
    for(i=2; i<=1000; i++){
        for(k=2, j=(i<<1); j<1000010; j+=i, k++){
            f[j]+=i+((k>1000)?((j==i*i)?0:k):0);
        }
    }
}

int main(){
    int t, n, i,j,k, sqrtn,pow,ppow, primesC=sieve();

    g[0]=0;g[1]=0;

    memset(f, 0, sizeof f);
    modifiedSieve();
    for(i=2; i<1000001; i++) g[i]=g[i-1]+f[i]+1;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%lld\n", g[n]);
    }
    return 0;
}
