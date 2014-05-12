#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXSIEVE 10010
#define MAXSIEVEHALF 5005
#define MAXSQRT 71

short a[5005];
int primes[5000];

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

int main(){
    sieve();
    int n, tmpn, i,j, c;
    while(scanf("%d", &n)>0){
        if(n==0) return 0;
        i=0; c=0;
        while(n>=primes[i]){
            tmpn=n; j=i;
            while(tmpn>0) tmpn-=primes[j++];
            if(tmpn==0) c++;
            i++;
        }
        printf("%d\n", c);
    }
    return 0;
}
