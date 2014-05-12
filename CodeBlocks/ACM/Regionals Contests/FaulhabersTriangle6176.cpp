#include <string.h>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string>

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

frac dp[500][500];

int main(){
    int t, d, kase=1, i,j,k, n,m;

    dp[0][0]=frac(1,1);
    for(i=1; i<405; i++){
        frac rowsum(0,1);
        for(j=1; j<=i; j++){
            dp[i][j]=mul(frac(i,j+1), dp[i-1][j-1]);
            rowsum = add(rowsum, dp[i][j]);
        }
        dp[i][0]=subtract(dp[0][0],rowsum);
    }

    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &d, &n, &m);
        if(dp[n][m-1].d==1) printf("%d %lld\n", kase++, dp[n][m-1].n);
        else printf("%d %lld/%lld\n", kase++, dp[n][m-1].n, dp[n][m-1].d);
    }
    return 0;
}
