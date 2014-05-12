#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXSIEVE 1000000
#define MAXSIEVEHALF 500000
#define MAXSQRT 708

short a[500001];
int primes[500000];

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

int ndiv[1000005], qry[1000005];

int main(){
    int t, i,j,k, n, pow, curmax;
    sieve();

    for(i=1; i<=1000005; i++){
        n=i, j=0;
        ndiv[i]=1;
        while(n>1 && primes[j]*primes[j]<=n){
            pow=1;
            while(n%primes[j]==0) n/=primes[j], pow++;
            ndiv[i]*=pow;
            j++;
        }
        if(n>1) ndiv[i]*=2;
    }

    curmax=1;
    for(i=1; i<1000005; i++){
        if(ndiv[i]>=ndiv[curmax]) curmax=i;
        qry[i]=curmax;
    }

    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%d\n", qry[n]);
    }
    return 0;
}
