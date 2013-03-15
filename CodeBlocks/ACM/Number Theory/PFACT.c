#include <stdio.h>
#define MAX 100001

int primes[MAX];//primes[i] = 0 if prime, greater for smallest prime divisor

void sieve(){
    int i,j, sqrtM=317;
    primes[0]=1;primes[1]=1;
    for(i=2; i<sqrtM; i++){
        if(primes[i]>0)continue;
        primes[i]=i;
        for(j=i*i; j<MAX; j+=i)if(primes[j]==0)primes[j]=i;
    }
    for(i=sqrtM; i<MAX; i++){
        if(primes[i]==0)primes[i]=i;
    }
}

int main(){
    sieve();
    int i,j, p;
    for(i=2; i<MAX; i++){
        printf("%d:", i);
        j=i;
        p = primes[j];
        while(j>1){
            j/=primes[j];
            if(p!=primes[j]){
                printf(" %d", p);
                p=primes[j];
            }
        }
        printf("\n");
    }
    return 0;
}
