#include <stdio.h>

unsigned int powmod(unsigned int a, unsigned int b, unsigned int c){
  unsigned int result = 1;
  unsigned int base = a;
  while (b){
    if (b & 1){
      result = result*base%c;
    }
    b >>= 1;
    base = base*base%c;
  }
  return result;
}

int millerIsPrime(unsigned int n, int itr){
    if(n==2) return 1;
    if(n<2||n%2==0) return 0;
    unsigned int b,res;
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
    int t;
    long long n;

    scanf("%d", &t);
    while(t--){
        scanf("%lld", &n);

        n--; if((n&1)==0)n--;
        while(n>0){
            if(millerIsPrime(n, 2)){
                printf("%u\n", n);
                break;
            }
            n-=2;
        }
    }
    return 0;
}
