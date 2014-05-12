#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <math.h>

using namespace std;

#define MAXSIEVE 1000005
#define MAXSIEVEHALF 500001
#define MAXSQRT 708

short a[500001];
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

int isprime(int n){
    if(n==2) return 1;
    if((n&1)==0) return 0;
    if(a[n>>1]==0) return 1;
    return 0;
}

int p[1000005];

int main(){
    int i,j,k, n,L,R, cprime=sieve();

    p[1]=0;
    for(i=2; i<1000003; i++){
        if(isprime(i)){ p[i]=-1; continue; }

        j=0;
        n=i;
        p[i]=0;
        while(n>1 && primes[j]*primes[j]<=n){
            k=p[i];
            while(n%primes[j]==0) p[i]++, n/=primes[j];
            j++;
        }
        if(n>1) p[i]++;
    }

    while(scanf("%d %d", &L, &R)>0){
        if(R==-1||L==-1) return 0;

    }

    return 0;
}
