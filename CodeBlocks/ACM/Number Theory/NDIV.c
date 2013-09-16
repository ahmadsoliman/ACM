#include <stdio.h>
#include <math.h>

#define MAXSIEVE 31630
#define MAXSIEVEHALF 15815
#define MAXSQRT 126

short a[15815];
int primes[3500];

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
    int a,b,n, i,j,k, tmp,sqrtTmp, c=0, cPrimes=sieve();
    scanf("%d %d %d", &a, &b, &n);
    for(;a<=b;a++){
        tmp=a;i=0;sqrtTmp=sqrt(tmp);k=1;
        while(tmp>1 && primes[i]<=sqrtTmp){
            j=1;
            while(tmp%primes[i]==0 && ++j) tmp/=primes[i];
            if(j>1) sqrtTmp=sqrt(tmp);
            k*=j;
            if(k>=n) break;
            i++;
        }
        if(tmp>1) k*=2;
        if(k==n) c++;
    }
    printf("%d\n", c);
    return 0;
}
