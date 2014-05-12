#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define INF 1000000000
#define EPS 1e-9

#define MAXSIEVE 2000010
#define MAXSIEVEHALF 1000005
#define MAXSQRT 1000

short a[MAXSIEVEHALF];
int primes[MAXSIEVEHALF];

void sieve(){
    int i, j, k;
    primes[0]=2;
    for(i=1,k=1;i<MAXSQRT;i++)
        if(a[i]==0){
            primes[k++]=i+i+1;
            for(j=2*i*i+i+i;j<MAXSIEVEHALF;j+=i+i+1)
                a[j]=1;
        }
    for(; i<MAXSIEVEHALF; i++)if(a[i]==0)primes[k++]=i+i+1;
}

int cntprimes[2000015], sqrprimes[2000015];

int main() {
    sieve();
    int n, i,j,k, L,U, sqrtn;
    double rest;
    cntprimes[0]=sqrprimes[0]=0;
    for(i=1; i<MAXSIEVE-2; i++){
        cntprimes[i]=cntprimes[i-1];
        sqrprimes[i]=sqrprimes[i-1];
        if(i==2 || (i!=1 && i%2==1 && a[i/2]==0)) {
            cntprimes[i]++;
            //if((i-1)%4!=0) continue;
            sqrtn=sqrt(i);
            for(j=1; j<=sqrtn; j++){
                rest = sqrt(i-j*j);
                if(fabs(rest-(int)rest)<EPS){
                    sqrprimes[i]++;
                    break;
                }
            }
        }
    }
    while(scanf("%d %d", &L, &U)>0){
        if(L==-1 && U==-1) return 0;
        if(L<=0 && U<=0) printf("%d %d 0 0\n", L, U);
        else if(L<=0) printf("%d %d %d %d\n", L, U, cntprimes[U], sqrprimes[U]);
        else printf("%d %d %d %d\n", L, U, cntprimes[U]-cntprimes[L-1], sqrprimes[U]-sqrprimes[L-1]);
    }
    return 0;
}
