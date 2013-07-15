#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIEVE 182
#define MAXSIEVEHALF 91
#define MAXSQRT 14

short a[MAXSIEVEHALF];
int primes[200];

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

int main(){
    int res, p, pe, n, i, k = sieve(), Ps[100], Es[100], nP;
    while(1){
        n = 1;
        char buf[100];
        char *line;
        fgets(buf, sizeof(buf), stdin);
        line = strtok(buf, " ");
        while(line != NULL){
            sscanf(line, "%d", &p);
            if(p==0)
                break;
            line = strtok(NULL, " ");
            sscanf(line, "%d", &pe);
            n *= pow(p, pe);
            line = strtok(NULL, " ");
        }
        if(n==1)
            break;
        n--;
        i = nP = 0;
        while(n>1&&i<k){
            pe = 0;
            while(n%primes[i]==0){
                pe++;
                n/=primes[i];
            }
            if(pe>0){
                Ps[nP] = primes[i];
                Es[nP] = pe;
                nP++;
            }
            i++;
        }
        if(n>1){
            Ps[nP] = n;
            Es[nP] = 1;
            nP++;
        }
        for(i=nP-1; i>=0; i--){
            printf("%d %d", Ps[i], Es[i]);
            if(i!=0)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
