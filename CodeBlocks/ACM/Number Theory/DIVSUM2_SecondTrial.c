#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAXSIEVE 100000000
#define MAXSIEVEHALF (MAXSIEVE/2)
#define MAXSQRT 5000

char a[MAXSIEVE/16+2];
#define isPrime(n) (a[(n)>>4]&(1<<(((n)>>1)&7)))

void sieve(){
    int i, j;
    memset(a, 255, sizeof(a));
    a[0]=0xFE;
    for(i=1;i<MAXSQRT;i++)
        if(a[i>>3]&(1<<(i&7)))
            for(j=i+i+i+1;j<MAXSIEVEHALF;j+=i+i+1)
                a[j>>3]&=~(1<<(j&7));
}

long long powmod(long long a, long long b, long long  c){
  long long result = 1;
  long long base = a;
  while (b){
    if (b & 1){
      result = result*base % c;
    }
    b >>= 1;
    base = base*base % c;
  }
  return result;
}

int isPrimeFermat(long long n){
    int i;
    long long a;
    for(i=0; i<10; i++){
        a = rand()%(n-1)+1;
        if(powmod(a,n-1,n) != 1)return 0;
    }
    return 1;
}

int primes[6000000];

int main(){
    sieve();
    primes[0]=2;
    int i,j=1;
    for(i=3; i<MAXSIEVE; i+=2)if(isPrime(i))primes[j++]=i;

    int t, sqrtN, pow;
    long long n, divSum, initialN, k;

    scanf("%d", &t);
    while(t--){
        scanf("%lld", &n);
        if(n<MAXSIEVE){
            if(n%2 && isPrime(n)){
                printf("1\n");
                continue;
            }
        }else{
            if(isPrimeFermat(n)){
                printf("1\n");
                continue;
            }
        }
        initialN=n;
        divSum=1;
        sqrtN = sqrtl(n);
        for(i=0; primes[i]<=sqrtN && primes[i]<n; i++){
            pow=0;
            while(n%primes[i]==0 && ++pow)n/=primes[i];
            if(pow>0){
                divSum*=(powl(primes[i], pow+1)-1)/(primes[i]-1);
                if(n<MAXSIEVE&&isPrime(n))break;
                sqrtN=sqrtl(n);
            }
        }
        if(n>1){
            divSum*=n+1;
        }
        printf("%lld\n", divSum-initialN);
    }
    return 0;
}
