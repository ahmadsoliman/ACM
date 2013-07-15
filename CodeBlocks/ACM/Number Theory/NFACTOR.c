#include <stdio.h>
#include <math.h>

#define MAXSIEVE 1005
#define MAXSIEVEHALF 505
#define MAXSQRT 25

short a[506];
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

int pre[1000001], pre2[1000001][11];

int main(){
    int t, a,b,n, i,j,k,f, c,tmp,sqrtTmp, cPrimes=sieve();

    for(i=2; i<1000001; i++){
        tmp=i;j=0;sqrtTmp=sqrt(tmp);f=1;
        while(tmp%primes[j]!=0) {
            j++;
            if(primes[j]>sqrtTmp) { f=0; break; }
        }
        if(f) {
            while(tmp%primes[j]==0) tmp/=primes[j];
            pre[i] = 1 + pre[tmp];
        }else pre[i]=1;
        for(j=0; j<11;j++) pre2[i][j] = pre2[i-1][j];
        if(pre[i]<11) pre2[i][pre[i]]++;
    }

    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &a ,&b, &n);
        if(n==0){
            if(a==1) printf("1\n");
            else printf("0\n");
        }else{
            printf("%d\n", pre2[b][n]-pre2[a][n]+((pre[a]==n)?1:0));
        }
    }
    return 0;
}
