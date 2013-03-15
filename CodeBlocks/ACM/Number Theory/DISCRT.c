#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAXSIEVE 31700
#define MAXSIEVEHALF 15850
#define MAXSQRT 90

short a[MAXSIEVEHALF];

int primes[10000];

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

long long modulo(long long x, long long m){
    while(x<0)x+=m;
    return x%m;
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

//Extended Euclidean Algorithm
void eGCD(long long res[], long long m, long long n){
    if(m==0){
        res[0]=0;res[1]=1;res[2]=n;
        return;
    }
    long long tmp[3];
    eGCD(tmp, n%m, m);
    res[0]=tmp[1]-(n/m)*tmp[0]; res[1]=tmp[0];  res[2]=tmp[2];
}

int factors[100], roots[10005];

int main(){
    int n,k,a,p,e,phiN,halfPhiN,m,factNum,rootsNum,xTok, i,j,flag;

    scanf("%d %d %d", &n, &k, &a);

    //calculate phi(n) n = p^e
    double tmpP;
    p = n; e = 1;
    for(i=31; i>1; i--){
        tmpP = pow(n, 1.0/i);
        if(fmod(tmpP, 1)==0){
            p = (int)tmpP;
            e = i;
            break;
        }
    }
    phiN = (p-1)*pow(p,e-1);

    //factorize phiN
    factNum=0;
    halfPhiN=phiN/2;
    sieve();
    for(i=0; primes[i]<=halfPhiN; i++){
        if(phiN%primes[i]==0){
            factors[factNum++]=primes[i];
        }
    }



    long long extended[3];
    eGCD(extended, powmod(a, phiN-1, n), n);



/*
    xTok = modulo(extended[0], n);

    rootsNum=0;
    for(i=0; i<extended[2]; i++){
        roots[rootsNum++]=ceil(pow(modulo(xTok+i*n, n), 1.0/k));
    }

    rootsNum=0;
    for(i=2; i<n; i++){
        if(powmod(i, k, n)==a){
            roots[rootsNum++]=i;
        }
    }
*/
    printf("%d\n", rootsNum);
    for(i=0; i<rootsNum; i++){
        printf("%d\n", roots[i]);
    }

    return 0;
}

