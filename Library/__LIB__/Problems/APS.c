#include <stdio.h>
#define MAX 10000001

int primes[MAX];//primes[i] = 0 if prime, greater for smallest prime divisor

void sieve(){
    int i,j, sqrtM=3163;
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

long long dp[MAX];

int main(){
    int i,t,n;

    sieve();

    dp[0]=dp[1]=0;
    for(i=2; i<MAX; i++){
        dp[i]=dp[i-1]+primes[i];
    }

    scanf("%d", &t);
    while(t--){
        scanf("%d",&n);
        printf("%lld\n", dp[n]);
    }
    return 0;
}
