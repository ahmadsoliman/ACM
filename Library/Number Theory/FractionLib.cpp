#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> frac;

#define n first
#define d second

int gcd(ll a, ll b){
    if(a==b && a==0) return 1;
    int n=((a<0)?-1:1)*a, m=((b<0)?-1:1)*b;
    ll tmp;
    if(n>m) tmp=n, n=m, m=tmp;
    while(n>0) tmp=n, n=m%n, m=tmp;
    return m;
}

frac simplify(frac f){
    ll d=gcd(f.n, f.d);
    return frac(f.n/d, f.d/d);
}

frac add(frac f1, frac f2){
    return simplify(frac((f1.n*f2.d)+(f2.n*f1.d), f1.d*f2.d));
}

frac subtract(frac f1, frac f2){
    return simplify(frac((f1.n*f2.d)-(f2.n*f1.d), f1.d*f2.d));
}

frac mul(frac f1, frac f2){
    ll d1=gcd(f1.n, f2.d);
    ll d2=gcd(f2.n, f1.d);
    return simplify(frac((f1.n/d1)*(f2.n/d2), (f1.d/d2)*(f2.d/d1)));
}

int main(){

    return 0;
}
