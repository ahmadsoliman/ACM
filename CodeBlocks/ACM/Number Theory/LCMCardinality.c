#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXSIEVE 32000
#define MAXSIEVEHALF 16000
#define MAXSQRT 128

short a[MAXSIEVEHALF];
int primes[20000];

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

int primeDs[20];

int main(){
    int L, tmpL, c, i, j, d, sqrtL, k=sieve(), dN, sumE, sumPieE, pieE;
    while(scanf("%d", &L)){
        if(L==0)
            break;

        sqrtL = (int)sqrt((double)L);
        memset(primeDs, 0, sizeof primeDs);

        tmpL = L;
        d=-1;
        i = 0;
        while(tmpL>1 && primes[i]<=tmpL && i<k){
            if(tmpL%primes[i]==0) d++;
            while(tmpL%primes[i]==0){
                tmpL/=primes[i];
                primeDs[d]++;
            }
            i++;
        }
        if(tmpL>1) primeDs[++d]++;
        d++;

        dN = 1;
        sumE = 0;
        pieE = 1;
        for(i=0; i<d; i++){
            dN *= primeDs[i]+1;
            sumE += primeDs[i];
            pieE *= primeDs[i]+1;
        }

        sumPieE = 0;
        for(i=0; i<d; i++){
            sumPieE += pieE/(primeDs[i]+1) - 2;
        }

        c = dN + ((d>1)?0:0) + ((d>2)?sumPieE:0);//(d*(d-1))/2

        printf("%d %d\n", L, c);
    }
    return 0;
}
