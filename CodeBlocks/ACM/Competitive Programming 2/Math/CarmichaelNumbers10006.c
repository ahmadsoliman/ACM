#include <stdio.h>
#include <math.h>

unsigned long long powmod(long long a, long long b, long long  c){
  unsigned long long result = 1;
  unsigned long long base = a;
  while (b){
    if (b & 1){
      result = result*base%c;
    }
    b >>= 1;
    base = base*base%c;
  }
  return result;
}

int millerIsPrime(long long n, int itr){
    if(n==2) return 1;
    if(n<2||n%2==0) return 0;
    unsigned long long b,res;
    while(itr--){
        b = rand()%(n-1) + 1;
        res = powmod(b, n, n);
        if(res!=b) return 0;
        res = powmod(b, (n-1)/2, n);
        if(!(res==1||res==n-1)) return 0;
    }
    return 1;
}

int main(){
    int n, i,j,f;
    while(scanf("%d", &n)>0){
        if(n==0) return 0;
        if(millerIsPrime(n, 10)) printf("%d is normal.\n", n);
        else {
            f=1;
            for(i=2; i<n; i++) if(powmod(i, n, n)!=i) {f=0; break;}
            if(f) printf("The number %d is a Carmichael number.\n", n);
            else printf("%d is normal.\n", n);
        }
    }
    return 0;
}
