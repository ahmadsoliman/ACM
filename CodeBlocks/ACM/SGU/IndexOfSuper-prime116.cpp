#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXSIEVE 10005
#define MAXSIEVEHALF 5002
#define MAXSQRT 71

short a[MAXSIEVEHALF];
int primes[2000], superPrimes[300];

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

int superSieve(int pc){
    int i, cnt=0, ind;
    for(i=0; i<pc; i++){
        ind=i+1;
        if(ind==2 || (ind>1 && ind%2==1 && a[ind>>1]==0)) superPrimes[cnt++]=primes[i];
    }
    return cnt;
}

int res[200], cntr;
short dp[10005][130];

short recur(int n, int i){
    if(n==0) return dp[n][i]=0;
    if(i<0) return dp[n][i]=30000;

    if(dp[n][i]!=-1) return dp[n][i];

    if(superPrimes[i]>n) return dp[n][i]=recur(n, i-1);

    int a=recur(n, i-1), b=1+recur(n-superPrimes[i], i);

    if(a<=b) return dp[n][i]=a;
    return dp[n][i]=b;
}

void recons(int n, int i){
    if(n==0) return;

    if(superPrimes[i]>n) { recons(n, i-1); return; }

    int a=dp[n][i-1], b=1+dp[n-superPrimes[i]][i];

    if(a<=b) recons(n, i-1);
    else res[cntr++]=superPrimes[i], recons(n-superPrimes[i], i);
}

int main(){
    int n, i, cnt, pc=sieve(), spc=superSieve(pc);

    scanf("%d", &n);

    memset(dp, -1, sizeof dp);
    cnt = recur(n, spc-1);

    if(cnt<30000) {
        cntr=0;
        recons(n, spc-1);
        printf("%d\n", cntr);
        printf("%d", res[0]);
        for(i=1; i<cntr; i++) printf(" %d", res[i]);
        printf("\n");
    }else printf("0\n");
    return 0;
}
