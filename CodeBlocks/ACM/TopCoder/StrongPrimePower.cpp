//SRM400 DIV 2

#include <math.h>
#include <string>
#include <vector>

using namespace std;

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

int isPrime(long long n){
    int i;
    long long a;
    for(i=0; i<3; i++){
        a = rand()%(n-1)+1;
        if(powmod(a,n-1,n) != 1)return 0;
    }
    return 1;
}

long long f(long long x, long long n){
    long long c = rand()%((long long)sqrtl(n)+1)+1;
    return (x*x + c)%n;
}

long long gcd(long long m, long long n){
    long long tmp;
    while(m>0){
        tmp = m;
        m = n%m;
        n = tmp;
    }
    return n;
}

long long prow(long long n){
    long long x=2, y=2, d=1, tmp;
    while(d == 1){
        x = f(x,n);
        y = f(f(y,n),n);
        if(x>y)tmp = x-y;
        else tmp = y-x;
        d = gcd(tmp, n);
    }
    if(d == n)
        return -1;
    return d;
}

vector<int> baseAndExponent(string n) {
    long long nl;
    int q=0;
    sscanf(n.c_str(), "%lld", &nl);
    vector<int> v;
    if(nl%2==0){
        while(nl%2==0&&++q)nl/=2;
        if(nl==1){
            v.push_back(2);
            v.push_back(q);
            printf("%d %d", 2, q);
        }
        return v;
    }
    if(isPrime(nl)) return v;

    long long p, tmp;
    do{
        tmp = prow(nl);
        if(tmp>0)p=tmp;
    }while(p<0 && !isPrime(p));

    while(nl%p==0&&++q)nl/=p;
    if(nl==1){
        v.push_back(p);
        v.push_back(q);
        printf("%lld %d", p, q);
    }
    return v;
}

int main(){
    baseAndExponent("100199359261369");

    return 0;
}
