#include <stdio.h>
#include <math.h>
#include <string.h>

#define max(x,y) ((x>y)?x:y)
#define MAX (10000)
int isPrime[MAX], primes[MAX];

void sieve(){
    memset(isPrime, 1, sizeof isPrime);
    int i,j, sqrtM=100, numOfPrimes=0;
    for(i=2; i<sqrtM; i++){
        if(!isPrime[i])continue;
        for(j=i*i; j<MAX; j+=i)isPrime[j]=0;
    }
    for(i=2; i<MAX; i++)if(isPrime[i])primes[numOfPrimes++]=i;
}

int nums[10];

int main(){
    sieve();
    int t, i, pow, maxN=0;
    for(t=0; t<10; t++){
        scanf("%d", &nums[t]);
        maxN=max(maxN,nums[t]);
    }
    long long countDiv=1;
    for(i=0; primes[i]<=maxN; i++){
        pow=1;
        for(t=0; t<10; t++){
            if(nums[t]==1)continue;
            while(nums[t]%primes[i]==0){
                pow++;
                nums[t]/=primes[i];
            }
        }
        countDiv=(countDiv*pow)%10;
    }
    printf("%lld", countDiv%10);
    return 0;
}
