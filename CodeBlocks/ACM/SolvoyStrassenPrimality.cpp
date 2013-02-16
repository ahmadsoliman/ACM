#include <stdio.h>
#include <algorithm>

using namespace std;

long long modulo(long long a, long long b, long long  c){
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

//calculates Jacobian(a/n) n>0 and n is odd
int calculateJacobian(long long a,long long n){
    if(!a) return 0; // (0/n) = 0
    int ans=1;
    long long temp;
    if(a<0){
        a=-a;    // (a/n) = (-a/n)*(-1/n)
        if(n%4==3) ans=-ans; // (-1/n) = -1 if n = 3 ( mod 4 )
    }
    if(a==1) return ans; // (1/n) = 1
    while(a){
        if(a<0){
            a=-a;    // (a/n) = (-a/n)*(-1/n)
            if(n%4==3) ans=-ans;    // (-1/n) = -1 if n = 3 ( mod 4 )
        }
        while(a%2==0){
            a=a/2;    // Property (iii)
            if(n%8==3||n%8==5) ans=-ans;
        }
        swap(a,n);    // Property (iv)
        if(a%4==3 && n%4==3) ans=-ans; // Property (iv)
        a=a%n; // because (a/p) = (a%p / p ) and a%pi = (a%n)%pi if n % pi = 0
        if(a>n/2) a=a-n;
    }
    if(n==1) return ans;
    return 0;
}

/* Iterations determine the accuracy of the test */
int Solovoy(long long p,int iteration){
    if(p<2) return 0;
    if(p!=2 && p%2==0) return 0;
    int i;
    for(i=0;i<iteration;i++){
        long long a=rand()%(p-1)+1;
        long long jacobian=(p+calculateJacobian(a,p))%p;
        long long mod=modulo(a,(p-1)/2,p);
        if(!jacobian || mod!=jacobian){
            return 0;
        }
    }
    return 1;
}


/* this function calculates (a*b)%c taking into account that a*b might overflow */
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

int Miller(long long p,int iteration){
    if(p<2)return 0;
    if(p!=2 && p%2==0)return 0;
    long long s=p-1,i;
    while(s%2==0)s/=2;
    for(i=0;i<iteration;i++){
        long long a=rand()%(p-1)+1,temp=s;
        long long mod=modulo(a,temp,p);
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
        if(modulo(a,n-1,n) != 1)return 0;
    }
    return 1;
}


int main(){
    int t, i, prime;
    long long n=0ll;

    scanf("%d", &t);
    while(t--){
        scanf("%lld", &n);
        if(isPrime(n) && Miller(n,10) && Solovoy(n,10))printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

