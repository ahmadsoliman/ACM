#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

ll gcd(ll n, ll m){
    if(n==0) return m;
    return gcd(m%n, n);
}

ii simplify(ii x){
    ll d = gcd(x.first, x.second);
    return ii(x.first/d, x.second/d);
}

ii subtract(ii x, ll deno){
    return simplify(ii(x.first*deno-x.second, x.second*deno));
}

int smaller(ii x, ll deno){
    if(1.0*x.first/x.second < 1.0/deno) return 1;
    return 0;
}

vi ans;

int main(){
    int m,n, i,j,k;
    ll deno;
    while(scanf("%d %d", &m, &n)>0){
        if(m==0 && n==0) return 0;
        ii r(m,n), newr;
        deno=2;
        ans.clear();
        while(r.first!=0){
            while(smaller(r, deno)) deno++;
            while((newr=subtract(r, deno)).second>=1000000) deno++;
            ans.push_back(deno);
            r = newr;
        }
        printf("%d", ans[0]);
        for(i=1; i<ans.size(); i++) printf(" %d", ans[i]);
        printf("\n");
    }
    return 0;
}
