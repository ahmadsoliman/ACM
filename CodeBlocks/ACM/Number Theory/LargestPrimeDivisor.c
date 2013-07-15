#include <stdio.h>
#include <string.h>

#define MAXSIEVE 31623000
#define MAXSIEVEHALF 15811500
#define MAXSQRT 3980

char a[MAXSIEVE/16+2];
#define isPrime(n) (a[(n)>>4]&(1<<(((n)>>1)&7)))

int primes[10000000];

int sieve(){
    int i, j, k=0;
    memset(a, 255, sizeof(a));
    a[0]=0xFE;
    for(i=1;i<MAXSQRT;i++)
        if(a[i>>3]&(1<<(i&7)))
            for(j=i+i+i+1;j<MAXSIEVEHALF;j+=i+i+1)
                a[j>>3]&=~(1<<(j&7));
    primes[k++]=2;
    for(i=3; i<MAXSIEVE; i+=2)if(isPrime(i))primes[k++]=i;
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
