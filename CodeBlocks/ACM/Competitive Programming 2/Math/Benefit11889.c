#include <stdio.h>
#include <math.h>

#define MAXSIEVE 3170
#define MAXSIEVEHALF 1585
#define MAXSQRT 40

short a[1585];
int primes[1585];

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

int powA[4000], powC[4000];

int main(){
    int t, A,B,C, i,j, pc=sieve();
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &A, &C);
        if(C%A!=0) printf("NO SOLUTION\n");
        else {
            memset(powA, 0, sizeof powA);
            memset(powC, 0, sizeof powC);
            i=0;
            while(i<pc && primes[i]*primes[i]<=A){
                while(A%primes[i]==0) A/=primes[i], powA[primes[i]]++;
                i++;
            }
            if(A>1 && A<=primes[pc-1]) powA[A]++;

            i=0, B=1;
            while(i<pc && primes[i]*primes[i]<=C){
                while(C%primes[i]==0) C/=primes[i], powC[primes[i]]++;
                if(powC[primes[i]]>powA[primes[i]]) B*=pow(primes[i], powC[primes[i]]);
                i++;
            }
            if(C>1 && C<=primes[pc-1] && powA[C]==0) B*=C;
            else if(C!=A) B*=C;
            printf("%d\n", B);
        }
    }
    return 0;
}
