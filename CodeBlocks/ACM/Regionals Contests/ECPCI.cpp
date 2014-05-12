#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>

#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

typedef long long ll;
typedef pair<ll, ll> frac;

#define n first
#define d second

int gcd(ll a, ll b){
    int n=((a<0)?-1:1)*a, m=((b<0)?-1:1)*b;
    ll tmp;
    if(n>m) tmp=n, n=m, m=tmp;
    while(n>0) tmp=n, n=m%n, m=tmp;
    return m;
}

frac simplify(frac f){
    ll d=gcd(f.n, f.d);
    if(d==0) d=1;
    return frac(f.n/d, f.d/d);
}

frac add(frac f1, frac f2){
    return simplify(frac((f1.n*f2.d)+(f2.n*f1.d), f1.d*f2.d));
}

frac subtract(frac f1, frac f2){
    return simplify(frac((f1.n*f2.d)-(f2.n*f1.d), f1.d*f2.d));
}

frac mul(frac f1, frac f2){
    return simplify(frac(f1.n*f2.n, f1.d*f2.d));
}

bool smaller(frac f1, frac f2){
    if(1.0*f1.n/f1.d <= 1.0*f2.n/f2.d) return 1;
    return 0;
}

frac abs(frac f){
    if(f.n<0) f.n*=-1;
    return f;
}

set<frac> alls;
set<frac> allv;
vector<frac> last;

void recur(set<frac>::iterator it, frac f){
    if(it==alls.end()) return;

    it++;
    recur(it, f);
    f = add(f, *it);
    if(f.n<f.d){
        allv.insert(f);
        recur(it, f);
    }
}

int main(){
    //freopen("zanzibar.in", "r", stdin);
    int i,j,k, t, a,b, kase=1, low, high, mid;

    for(i=1; i<13; i++){
        for(j=i+1; j<=13; j++){
            alls.insert(frac(i, j));
        }
    }
    set<frac>::iterator mend = alls.end();
    set<frac>::iterator it;
    for(it=alls.begin(); it!=mend; it++){
        frac cur = *it;
        ll num=cur.n;
        while(cur.n+num<cur.d){
            cur.n+=num;
            alls.insert(cur);
        }
    }

    recur(alls.begin(), frac(0,1));
    for(it=alls.begin(); it!=alls.end(); it++){
        last.push_back(*it);
    }

    for(it=allv.begin(); it!=allv.end(); it++){
        last.push_back(*it);
    }

    sort(last.begin(), last.end(), smaller);

    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &a, &b);

        frac n(a,b), minf(1,1), curf;

        if(a==0){
            printf("Case %d: %d/%d\n", kase++, (int)last[0].n, (int)last[0].d);
            continue;
        }

        low = 0;
        high = last.size() - 1;
        while (low <= high) {
            mid = low + ((high - low) / 2);
            curf = subtract(n, last[mid]);
            if (curf.n<0)
                high = mid - 1;
            else if (curf.n>0)
                low = mid + 1;
            else{
                curf = abs(curf);
                if(smaller(curf, minf)){
                    minf=curf;
                }
                break;
            }
            curf = abs(curf);
            if(smaller(curf, minf)){
                minf=curf;
            }
        }
        if(minf.n==0) printf("Case %d: 0/%d\n", kase++, b);
        else printf("Case %d: %d/%d\n", kase++, (int)minf.n, (int)minf.d);
    }
    return 0;
}
