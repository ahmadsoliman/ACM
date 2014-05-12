#include <stdio.h>
#include <string.h>
#include <math.h>

typedef long long ll;

#define MAXSIEVE 1010
#define MAXSIEVEHALF 506
#define MAXSQRT 23
#define EPS 1e-9

short a[505];
int primes[500];

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

unsigned long long seq[1000005], ans[1000005];

void preCompute(){
    /* a(n) = n*(1+Sum_{d|n} d*phi(d))/2
       a(n) =  n*(1+seq(n))/2

       seq(p^e) = (p^(2*e+1)+1)/(p+1)
    */
    int i,j, PF_idx, PF, N;
    unsigned long long pow1;
    for(i=1; i<1000001; i++){
        PF_idx = 0, PF = primes[PF_idx];
        N = i; seq[i]=1;
        while (N != 1 && (PF * PF <= N)) {
            pow1 = PF;
            while (N % PF == 0) { N /= PF; pow1*=PF*PF; }
            if(pow1>PF) seq[i] *= round((double)(pow1+1)/(PF+1)-EPS);
            PF = primes[++PF_idx];
        }
        if(N>1) seq[i]*=round((double)(N*N*N+1)/(N+1)-EPS);
        ans[i]=(i*(1+seq[i])/2.0);
    }
}

int main(){
    sieve();
    preCompute();
//int i; for(i=1; i<1001; i++) printf("%d %llu\n", i, ans[i]);
    int t, n;
    scanf("%d", &t);
    unsigned long long res;
    while(t--){
        scanf("%d", &n);
        printf("%llu\n", ans[n]);
    }
    return 0;
}

