#include <stdio.h>

long long modulo(long long x, long long m){
    while(x<0)x+=m;
    return x%m;
}

/*
// calculates (a*b)%c taking into account that a*b might overflow
long long mulmod(long long a,long long b,long long c){
    long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}
*/

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


int main(){
    int t, caseNum=1;
    long long res, r, A, N, P, M;
    scanf("%d", &t);
    while(t--){
        scanf("%lld %lld %lld %lld", &A, &N, &P, &M);

        if(modulo(A-1,P)==0)
            res = (M*((powmod(powmod(A, N, P), P-2, P)*(N+1))%P))%P;
        else{
            res = (((((M*powmod(powmod(A,N,P), P-2, P))%P)*powmod(A-1, P-2, P))%P)*(powmod(A, N+1, P)-1))%P;
        }

        printf("Case %d: %lld\n", caseNum++, res%P);
    }
    return 0;
}

