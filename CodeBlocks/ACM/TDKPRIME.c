#include <math.h>
#include <string.h>

#define MAXSIEVE 86029000
#define MAXSIEVEHALF 43014500
#define MAXSQRT 4638

int primes[5000100];

char a[MAXSIEVE/16+2];
#define isPrime(n) (a[(n)>>4]&(1<<(((n)>>1)&7)))

void sieve(){
    int i, j, k;
    memset(a, 255, sizeof(a));
    a[0]=0xFE;
    primes[0]=2;
    for(i=1, k=1;i<MAXSQRT;i++)
        if(a[i>>3]&(1<<(i&7))){
            primes[k++]=i+i+1;
            for(j=2*i*i+i+i;j<MAXSIEVEHALF;j+=i+i+1)
                a[j>>3]&=~(1<<(j&7));
        }
    for(; i<MAXSIEVEHALF; i++)if(a[i>>3]&(1<<(i&7)))primes[k++]=i+i+1;
}

int main(){
    sieve();
    int t, m;

    scanf("%d",&t);

    while(t--){
        scanf("%d",&m);
        printf("%d\n", primes[m-1]);
    }
    return 0;
}
