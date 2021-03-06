#include <stdio.h>

/* this function calculates (a*b)%c taking into account that a*b might overflow */
long long mulmod(long long a,long long b,long long c){
    unsigned long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}

unsigned long long powmod(long long a, long long b, long long  c){
  unsigned long long result = 1;
  unsigned long long base = a;
  while (b){
    if (b & 1){
      result = mulmod(result, base , c);
    }
    b >>= 1;
    base = mulmod(base, base , c);
  }
  return result;
}



int Miller(long long p,int iteration){
    if(p<2)return 0;
    if(p!=2 && p%2==0)return 0;
    long long s=p-1,i;
    while(s%2==0)s/=2;
    for(i=0;i<iteration;i++){
        long long a=rand()%(p-1)+1,temp=s;
        long long mod=powmod(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1){
            mod=mulmod(mod,mod,p);
            temp *= 2;
        }
        if(mod!=p-1 && temp%2==0){
            return 0;
        }
    }
    return 1;
}

int isPrime(long long n){
    long long i;
    long long a;
    for(i=0; i<5; i++){
        a = rand()%(n-1)+1;
        if(powmod(a,n-1,n) != 1)return 0;
    }
    return 1;
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
    int t;
    long long n;

    scanf("%d", &t);
    while(t--){
        scanf("%lld", &n);
        if(millerIsPrime(n,1))printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
