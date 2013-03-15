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

//int isPrime(int n){
//    int i;
//    int a;
//    for(i=0; i<10; i++){
//        a = rand()%(n-1)+1;
//        if(powmod(a,n-1,n) != 1)return 0;
//    }
//    return 1;
//}

int Miller(int p,int iteration){
    if(p<2)return 0;
    if(p!=2 && p%2==0)return 0;
    long long s=p-1,i;
    while(s%2==0)s/=2;
    for(i=0;i<iteration;i++){
        long long a=rand()%(p-1)+1,temp=s;
        long long mod=powmod(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1){
            mod=(mod*mod)%p;
            temp *= 2;
        }
        if(mod!=p-1 && temp%2==0){
            return 0;
        }
    }
    return 1;
}
/* Miller-Rabin primality test, iteration signifies the accuracy of the test */

int main(){
    int a = 1,i=0;
    while(++i<50){
        if(Miller(a, 5))printf("1");
        else printf("0");
        a = (a + 1234567890)%2147483648;
    }
    return 0;
}
