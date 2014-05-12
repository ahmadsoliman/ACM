#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXSIEVE 1000000
#define MAXSIEVEHALF 500000
#define MAXSQRT 708

short a[MAXSIEVEHALF];
int primes[MAXSIEVEHALF];

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

#define INF 1000000000

int main() {
    sieve();
    int n, halfn, i,j,k, found;
    while(scanf("%d", &n)>0){
        if(n==0) return 0;
        halfn=n>>1, found=0;
        for(i=1; primes[i]<=halfn; i++){
            k=n-primes[i];
            if((k&1) && a[k>>1]==0){
                found=1;
                printf("%d = %d + %d\n", n, primes[i], k);
                break;
            }
        }
        if(!found) printf("Goldbach's conjecture is wrong.\n");
    }
    return 0;
}
