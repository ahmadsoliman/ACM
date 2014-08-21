#include <stdio.h>
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
    int a = 1,i=0;
    while(++i<3350001){
        if(millerIsPrime(a, 2))printf("1");
        else printf("0");
        a = (a + 1234567890)%2147483648;
    }
    return 0;
}
