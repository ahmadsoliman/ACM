#include <stdio.h>
#include <math.h>

#define MAXSIEVE 31622800
#define MAXSIEVEHALF 15811400
#define MAXSQRT 3980

int primes[1951965];

char a[MAXSIEVE/16+2];

int sieve(){
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
    return k;
}

long long prime[500];
int power[500];

int main(){
    int k = sieve();
    long long n, sqrtn;
    int i,j, cnt;
    while(scanf("%lld", &n)>0){
        if(n==0) return 0;
        sqrtn=sqrt(n)+1;
        i=cnt=0;
        memset(power, 0, sizeof power);
        while(n>1 && i<k && primes[i]<=sqrtn){
            if(n%primes[i]==0){
                prime[cnt]=primes[i];
                while(n%primes[i]==0 && ++power[cnt]) n/=primes[i] ;
                cnt++;
                sqrtn=sqrt(n);
            }
            i++;
        }
        if(n>1){
            prime[cnt]=n;
            power[cnt++]=1;
        }
        for(i=0; i<cnt; i++){
            printf("%lld^%lld", prime[i], power[i]);
            if(i<cnt-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
