#include <math.h>
#include <string.h>

#define MAXSIEVE 100000000
#define MAXSIEVEHALF 50000000
#define MAXSQRT 5000

char a[MAXSIEVE/16+2];
#define isPrime(n) (a[(n)>>4]&(1<<(((n)>>1)&7)))

void sieve(){
    int i, j, k;
    memset(a, 255, sizeof(a));
    a[0]=0xFE;
    printf("2\n");
    for(i=1, k=1;i<MAXSQRT;i++)
        if(a[i>>3]&(1<<(i&7))){
            if((k=(k+1)%100)==1) printf("%d\n", i+i+1);
            for(j=2*i*i+i+i;j<MAXSIEVEHALF;j+=i+i+1)
                a[j>>3]&=~(1<<(j&7));
        }
    for(; i<MAXSIEVEHALF; i++)if(a[i>>3]&(1<<(i&7))) if((k=(k+1)%100)==1) printf("%d\n", i+i+1);
}

int main(){
    sieve();
    return 0;
}

