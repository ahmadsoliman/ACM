#include <stdio.h>
#include <math.h>

#define min(x,y) ((x<y)?x:y)
#define MAX (1000001)
int isPrime[MAX], primes[MAX];

void sieve(){
    memset(isPrime, 1, sizeof isPrime);
    int i,j, sqrtM=(int)sqrt(MAX), numOfPrimes=0;
    for(i=2; i<sqrtM; i++){
        if(!isPrime[i])continue;
        for(j=i*i; j<MAX; j+=i)isPrime[j]=0;
    }
    for(i=2; i<MAX; i++)if(isPrime[i])primes[numOfPrimes++]=i;
}

int gcd(int m, int n){
    if(m==0)return n;
    return gcd(n%m, m);
}

int main(){
    sieve();
    int t, x, y, i, GCD, countDiv, pow;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &x, &y);
        GCD = gcd(x,y);
        countDiv=1;
        for(i=0; primes[i]<=GCD; i++){
            if(isPrime[GCD]){
                countDiv*=2;
                break;
            }
            pow=1;
            while(GCD%primes[i]==0){
                pow++;
                GCD/=primes[i];
            }
            countDiv*=pow;
        }
        printf("%d\n", countDiv);
    }
    return 0;
}
