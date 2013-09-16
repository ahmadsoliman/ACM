#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> llll;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

ll h[100010], p[100010];

ll longabs(ll n){
    if(n<0) return n*-1;
    return n;
}

int main(){
    int n, m, i,j,k;
    scanf("%d %d", &n, &m);
    k=0;
    for(i=0; i<n; i++) { scanf("%I64d", &h[i]); }
    for(i=0; i<m; i++) { scanf("%I64d", &p[i]); }

    ll res=0;
    llll u;
    for(i=0, j=0; i<m; i++){
        if(i==0) {
            res = longabs(h[j++]-p[i]);
            u=llll(p[i],res);
        } else{
            if(j>=n) {
                ll o=u.second+longabs(u.first-p[i]);
                res = max(res, o);
                u=llll(p[i], o);
                continue;
            }
            ll o1=longabs(h[j]-p[i]), o2=u.second+longabs(u.first-p[i]);
            if(o2<=o1){
                res = max(res, o2);
                u=llll(p[i], o2);
            }else{
                res = max(res, o1);
                j++;
                u=llll(p[i], o1);
            }
        }
    }
    printf("%I64d\n", res);

    return 0;
}
