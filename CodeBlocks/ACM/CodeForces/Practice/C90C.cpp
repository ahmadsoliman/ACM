#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <math.h>
#include <bitset>

#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<ll, ll> llll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, llll> iiii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<iiii> viiii;
typedef vector<vii> vvii;

#define INF 4000000000000000000ll

viiii subjs;
int n,m,k;

ll dp[51][51][51][101];

ll recur(int d, int s, int lasts, int lastk){
    if(dp[d][s][lasts][lastk]!=-1) return dp[d][s][lasts][lastk];

    if(d==n) return dp[d][s][lasts][lastk]=0;
    if(s==m) return dp[d][s][lasts][lastk]=-INF;

    dp[d][s][lasts][lastk]=recur(d, s+1, lasts, lastk);
    ll a=subjs[s].second.first, b=subjs[s].second.second;
    int len = b-a+1;

    if(d==0){
        for(int i=0; i<len; i++){
            dp[d][s][lasts][lastk]=max(dp[d][s][lasts][lastk], subjs[s].second.first + i +recur(d+1, s+1, s, i));
        }
    }else if(subjs[s].first.first>subjs[lasts].first.first){
        ll x=k+(lastk+subjs[lasts].second.first), y=k*(lastk+subjs[lasts].second.first);

        if(x>=a&&x<=b) dp[d][s][lasts][lastk]=max(dp[d][s][lasts][lastk], x+recur(d+1, s+1, s, x-a));
        if(y>=a&&y<=b) dp[d][s][lasts][lastk]=max(dp[d][s][lasts][lastk], y+recur(d+1, s+1, s, y-a));
    }

    return dp[d][s][lasts][lastk];
}

void recons(int d, int s, int lasts, int lastk){
    if(d==n || s==m) return;

    ll ta = dp[d][s+1][lasts][lastk], tb=-INF, cur;
    int ti;


    ll a=subjs[s].second.first, b=subjs[s].second.second;
    int len = b-a+1;

    if(d==0){
        for(int i=0; i<len; i++){
            cur = subjs[s].second.first + i + dp[d+1][s+1][s][i];
            if(cur>tb) tb = cur, ti=i;
        }
    }else if(subjs[s].first.first>subjs[lasts].first.first){
        ll x=k+(lastk+subjs[lasts].second.first), y=k*(lastk+subjs[lasts].second.first);
        if(x>=a&&x<=b) {
            cur = x+dp[d+1][s+1][s][(x-a)];
            if(cur>tb) tb=cur, ti=x-a;
        }
        if(y>=a&&y<=b) {
            cur = y+dp[d+1][s+1][s][(y-a)];
            if(cur>tb) tb=cur, ti=y-a;
        }
    }

    if(ta>=tb) recons(d, s+1, lasts, lastk);
    else {
        printf("%d %I64d\n", subjs[s].first.second, subjs[s].second.first + ti);
        recons(d+1, s+1, s, ti);
    }
}

int main() {
    int c;
    ll a,b;
    scanf("%d %d %d", &n, &m, &k);

    for(int i=0; i<m; i++){
        scanf("%I64d %I64d %d", &a, &b, &c);
        subjs.pb(iiii(ii(c,i+1),llll(a,b)));
    }
    sort(subjs.begin(), subjs.end());

    memset(dp, -1, sizeof dp);
    ll res = recur(0, 0, 0, 0);

    if(res<0) printf("NO\n");
    else{
        printf("YES\n");
        recons(0,0,0,0);
    }

    return 0;

}
