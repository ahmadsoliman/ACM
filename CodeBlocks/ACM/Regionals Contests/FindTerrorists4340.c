#include <stdio.h>
#include <math.h>

#define MAXSIEVE 1000000
#define MAXSIEVEHALF 500000
#define MAXSQRT 709

short a[500000], isPrime[1000000];
int primes[100000];

void sieve(){
    int i, j, k;
    primes[0]=2;
    isPrime[2]=1;
    for(i=1,k=1;i<MAXSQRT;i++)
        if(a[i]==0){
            primes[k++]=i+i+1;
            isPrime[i+i+1]=1;
            for(j=2*i*i+i+i;j<MAXSIEVEHALF;j+=i+i+1)
                a[j]=1;
        }
    for(; i<MAXSIEVEHALF; i++)if(a[i]==0)primes[k++]=i+i+1;
}

int main(){
    sieve();
    int t, L, H, i,j,k, numDiv, pow, n, sqrtN, entered;

    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &L, &H);
        entered=0;
        for(; L<=H; L++){
            i=0;
            n=L;
            sqrtN = (int)sqrt(n)+1;
            numDiv=1;
            while(n>1 && primes[i]<=sqrtN){
                pow=1;
                while(n%primes[i]==0 && ++pow) n/=primes[i];
                if(pow>1){
                    numDiv*=pow;
                    sqrtN=sqrt(n)+1;
                }
                i++;
            }
            if(n>1) numDiv*=2;
            if(numDiv>1 && (numDiv==2 || numDiv%2) && isPrime[numDiv]) {
                if(entered) printf(" ");
                else entered=1;
                printf("%d", L);
            }
        }
        if(!entered) printf("-1\n");
        else printf("\n");
    }
    return 0;
}
