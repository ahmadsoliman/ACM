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
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

ll d[100010], s[100010], minv[100010], sum[100010];

vector<int> tree[100010];
vector<int> g[100010];

void dfs1(int u, int par){
    for(int i=0; i<g[u].size(); i++){
        if(g[u][i]==par) continue;
        tree[u].pb(g[u][i]);
        dfs1(g[u][i], u);
    }
}

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    if(a==0 && b==0) return 1;
    if(a==0 || b==0) return a+b;
    return a*(b/gcd(a,b));
}

void dfs2(int u){
    d[u]=1;
    if(tree[u].size()==0) return;
    for(int i=0; i<tree[u].size(); i++){
        dfs2(tree[u][i]);
        d[u]=lcm(d[u], d[tree[u][i]]);
        s[u]+=s[tree[u][i]];
    }
    d[u]*=tree[u].size();
}

ll t,x,res;

void dfs3(int u){
    if(tree[u].size()==0) return;
    minv[u]=1000000000000000000ll, sum[u]=0;
    for(int i=0; i<tree[u].size(); i++) dfs3(tree[u][i]), minv[u]=min(minv[u], s[tree[u][i]]), sum[u]+=s[tree[u][i]];

    t = d[u]/tree[u].size();
    x = (minv[u]/t) * t;
    s[u] = x*tree[u].size();
    res+=sum[u]-x*tree[u].size();
}

int main() {
    int n,u,v;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &u);
        s[i]=u;
    }

    for(int i=0; i<n-1; i++){
        scanf("%d %d", &u, &v);
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs1(0, -1);
    for(int i=0; i<n; i++) g[i].clear();

    dfs2(0);

    res = 0;
    dfs3(0);
    printf("%lld\n", res);

    return 0;

}
