#include <stdio.h>

#define MAXSIEVE 10000000
#define MAXSIEVEHALF 5000000
#define MAXSQRT 2240

short a[MAXSIEVEHALF];
int primes[1000000];

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
    long long n, l;
    int i, e, k = sieve();

    while(scanf("%ld", &n)>0){
        if(n==0)
            break;
        if(n<0){
            printf("-1\n");
            continue;
        }
        i = 0;
        e = 0;
        l = 0;
        while(n>1&&i<k){
            if(n%primes[i]==0){
                e++;
                l = primes[i];
                while(n%primes[i]==0){
                    n/=primes[i];
                }
            }
            i++;
        }
        if(n>1){
            e++;
            l = n;
        }
        if(e>1)
            printf("%ld\n", l);
        else
            printf("-1\n");
    }
    return 0;
}
