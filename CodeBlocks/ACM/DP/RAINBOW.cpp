#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define INF 1000000000

int w[1005], dp[1005][1005], visdp[1005][1005], kase=1;
vvi g;
vector< set<int> > comps;
vi vis, compsw, compsc;

void dfs(int u, int k){
    if(vis[u]) return;
    vis[u]=1;
    comps[k].insert(u);
    for(int i=0; i<g[u].size(); i++){
        if(!vis[g[u][i]]) dfs(g[u][i], k);
    }
}

int recur(int i, int C){
    if(i==compsw.size()) return 0;
    if(C==0) return 0;
    if(visdp[i][C]==kase) return dp[i][C];
    int a=recur(i+1, C), b=0;
    if(C>=compsw[i]) b=compsc[i]+recur(i+1, C-compsw[i]);
    visdp[i][C]=kase;
    return dp[i][C]=max(a,b);
}

int main(){
    int i,j,k, u,v, C,n;
    set<int>::iterator it;

    while(scanf("%d %d", &n, &C)>0){
        if(n==0 && C==0) return 0;
        g = vvi(n, vi());
        for(i=0; i<n; i++) scanf("%d", &w[i]);
        for(i=0; i<n; i++){
            scanf("%d", &k);
            while(k--){
                scanf("%d", &v);
                v--;
                g[i].push_back(v);
                g[v].push_back(i);
            }
        }
        k=-1;
        vis = vi(n, 0);
        comps.clear();
        for(i=0; i<n; i++) {
            if(!vis[i]) {
                comps.push_back(set<int>());
                k++;
                dfs(i, k);
            }
        }
        compsw = vi(comps.size(),0);
        compsc = vi(comps.size(),0);
        for(i=0; i<comps.size(); i++){
            compsc[i]=comps[i].size();
            for(it=comps[i].begin(); it!=comps[i].end(); it++){
                compsw[i]+=w[*it];
            }
        }
        printf("%d\n", recur(0, C));
        kase++;
    }

    return 0;
}

