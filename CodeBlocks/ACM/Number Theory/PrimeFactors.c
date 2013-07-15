#include <stdio.h>

#define MAXSIEVE 50000
#define MAXSIEVEHALF 25000
#define MAXSQRT 225

short a[MAXSIEVEHALF];
int primes[30000];

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
    int n, i, e, k = sieve();
    while(scanf("%d", &n)>0){
        if(n==0)
            break;
        printf("%d = ", n);
        if(n<0){
            n*=-1;
            printf("-1 x ");
        }
        i = 0;
        e = 0;
        while(n>1&&i<k){
            while(n%primes[i]==0){
                if(e)
                    printf(" x ");
                else
                    e = 1;
                printf("%d", primes[i]);
                n/=primes[i];
            }
            i++;
        }
        if(n>1){
            if(e)
                printf(" x ");
            printf("%d", n);
        }
        printf("\n");
    }
    return 0;
}
