#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAXSIEVE 65536
#define MAXSIEVEHALF 32768
#define MAXSQRT 128

short a[32768];// 0 if prime

short primes[33000];

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

int factors[100];

int main(){
    int t, n, i, j, flag, phiN, primitiveRoot, factNum, tmpPhiN, rootPhiN;

    sieve();

    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);

        phiN = n-1;

        //factorize phiN
        factNum=0;
        rootPhiN=sqrt(phiN);
        tmpPhiN=phiN;
        for(i=0; primes[i]<=rootPhiN && tmpPhiN>1; i++){
            if(tmpPhiN%primes[i]==0){
                factors[factNum++]=primes[i];
                while(tmpPhiN%primes[i])tmpPhiN/=primes[i];
            }
        }
        if(tmpPhiN>1){
            factors[factNum++]=primes[i];
        }

         //find a primitive root
        primitiveRoot=-1;
        for(i=n-1; i>=2; i--){
            flag=1;
            for(j=0; j<factNum; j++){
                if(powmod(i, phiN/factors[j], n)==1){
                    flag=0;
                    break;
                }
            }
            if(flag){
                primitiveRoot=i;
                break;
            }
        }
        printf("%d\n", primitiveRoot);
    }
    return 0;
}
