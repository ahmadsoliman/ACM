#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIEVE 1000020
#define MAXSIEVEHALF 500010
#define MAXSQRT 708

#define max(x,y) (((x)>(y))?(x):(y))

short a[500020];
int primes[78600];

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

int powA[78600], powB[78600];

int main(){
    int A, B, i,j,k, cP=sieve(), X, D, tmp, maxp, kase=1;
    while(scanf("%d %d", &A, &B)>0){
        if(A==0) return 0;

        memset(powA, 0, sizeof powA);
        memset(powB, 0, sizeof powB);

        i=0;
        tmp=A;
        while(tmp>1 && primes[i]<=tmp){
            powA[i]=0;
            while(tmp%primes[i]==0 && ++powA[i]) tmp/=primes[i];
            i++;
        }
        maxp=max(primes[i-1],tmp);

        i=0;
        tmp=B;
        while(tmp>1 && primes[i]<=tmp){
            powB[i]=0;
            while(tmp%primes[i]==0 && ++powB[i]) tmp/=primes[i];
            i++;
        }
        maxp=max(maxp, max(tmp, primes[i-1]));

        X=0; D=0;
        for(i=0; primes[i]<=maxp; i++){
            if(powA[i]==0&&powB[i]==0) continue;
            X++;
            D += abs(powA[i]-powB[i]);
        }

        printf("%d. %d:%d\n", kase++, X, D);
    }
    return 0;
}
