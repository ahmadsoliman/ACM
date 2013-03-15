#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX (10000001)

int primes[10000001];

void sieve(){
    int i,j, sqrtM=3163;
    for(i=2; i<sqrtM; i++){
        if(primes[i])continue;
        for(j=i*i; j<MAX; j+=i)primes[j]=1;
}

int main(){
    sieve();
        int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);

    }
    return 0;
}
