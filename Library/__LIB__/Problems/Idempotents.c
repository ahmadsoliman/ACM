#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAXSIEVE 32000
#define MAXSIEVEHALF (MAXSIEVE/2)
#define MAXSQRT 90

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

//Extended Euclidean Algorithm
void eGCD(long long res[], long long m, long long n){
    if(m==0){
        res[0]=0;res[1]=1;res[2]=n;
        return ;
    }
    long long tmp[3];
    eGCD(tmp, n%m, m);
    res[0]=tmp[1]-(n/m)*tmp[0];res[1]=tmp[0];res[2]=tmp[2];
}

//Chinese Remainder Theorem , congruences[i][0] = ai & congruences[i][1] = ni
long long congruences[2][2];
long long CRT(int len){
    //check all n are co-prime

    //calculate N
    long long N=1ll;
    int i;
    for (i = 0; i < len; i++) {
        N*=congruences[i][1];
    }

    //calculate x
    long long x=0ll;
    for (i = 0; i < len; i++) {
        long long si = N/congruences[i][1];
        long long tmp[3];
        eGCD(tmp, congruences[i][1], si);
        x += tmp[1]*si*congruences[i][0];
    }
    return x;
}

int primes[5000];

int main(){
    int t, n, i, j=1, p, q, x1 ,x2;

    sieve();
    primes[0]=2;
    for(i=3; i<MAXSIEVE; i+=2)if(isPrime(i))primes[j++]=i;

    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i=0; primes[i]<n; i++)if(n%primes[i]==0){p=primes[i];break;}
        q=n/primes[i];

        congruences[0][0]=0;congruences[0][1]=p;
        congruences[1][0]=1;congruences[1][1]=q;
        x1 = (int)CRT(2);

        congruences[0][0]=0;congruences[0][1]=q;
        congruences[1][0]=1;congruences[1][1]=p;
        x2 = (int)CRT(2);

        printf("0 1");
        x1=x1%n;
        x2=x2%n;
        while(x1<0)x1+=n;
        while(x2<0)x2+=n;
        printf(" %d %d\n", (x1<x2)?x1:x2, (x1>x2)?x1:x2);

    }
    return 0;
}
