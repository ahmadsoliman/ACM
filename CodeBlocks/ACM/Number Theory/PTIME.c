#include <stdio.h>
#include <string.h>

#define MAXSIEVE 10000
#define MAXSIEVEHALF 5000
#define MAXSQRT 72

short a[5000];
int primes[2000], e[2000];

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

int main(){
    int n, i, j, tmp, countP=sieve();
    scanf("%d", &n);
    for(i=2; i<=n; i++){
        tmp=i;j=0;
        while(tmp>1 && tmp>=primes[j]){
            while(tmp>1 && tmp%primes[j]==0) {tmp/=primes[j]; e[j]++;}
            j++;
        }
    }

    printf("2^%d", e[0]);
    for(i=1; i<countP; i++){
        if(e[i]>0) printf(" * %d^%d", primes[i], e[i]);
    }

    return 0;
}
