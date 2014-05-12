#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXSIEVE 1000
#define MAXSIEVEHALF 500
#define MAXSQRT 23

typedef long long ll;

short a[MAXSIEVEHALF];
int primes[500];

int sieve() {
    int i,j,k;
    primes[0]=2;
    for(i=1,k=1; i<MAXSQRT; i++){
        if(a[i]==0){
            primes[k++]=i+i+1;
            for(j=2*i*i+i+i; j<MAXSIEVEHALF; j+=i+i+1) a[j]=1;
        }
    }
    for(; i<MAXSIEVEHALF; i++) if(a[i]==0) primes[k++]=i+i+1;
    return k;
}

int prime[500], power[500];

int main(){
    ll n,b, cnt, cprimes=sieve(), tmpb, sqrtb, i,j, cfact, lastp, lnb, val;
    while(scanf("%lld %lld", &n, &b)){
        if(n==0&&b==0) return 0;

        i=cfact=0;
        sqrtb=sqrt(tmpb=b)+1;
        memset(power, 0, sizeof power);
        while(tmpb>1 && i<cprimes && primes[i]<=sqrtb){
            if(tmpb%primes[i]==0){
                prime[cfact]=primes[i];
                while(tmpb%primes[i]==0 && ++power[cfact]) tmpb/=primes[i];
                cfact++;
                sqrtb=sqrt(tmpb);
            }
            i++;
        }
        if(tmpb>1){
            prime[cfact]=tmpb;
            power[cfact++]=1;
        }
        ll minv=2000000000000000000ll, curv, powp;
        i=cfact-1;
        powp=pow(prime[i],power[i]);
        /*for(i=0; i<cfact; i++){
            lastp=n;
            lnb = 0;
            while(lastp>=prime[i]) lnb++, lastp/=prime[i];

            val=0, powp=pow(prime[i],2);
            for(j=2; j<=lnb; j++){
                val+=(j-1);
                if(powp<=n) val+=(n/powp - 1)/prime[i], powp*=prime[i];
            }
            curv=(n/prime[i]+val)/power[i];
            if(curv<minv) minv=curv;
        }*/
        ll zeros=0, fives = prime[i];
        while(fives<=n){
            zeros+=n/fives;
            fives*=prime[i];
        }
        printf("%lld\n", zeros/power[i]);
    }
    return 0;
}

/*
16 4
7
2 4 6 8 10 12 14 16
1 2 1 3 1  2  1  1 = 12

3 10
60 10
100 10
1024 10
23456 10
8735373 10
*/
