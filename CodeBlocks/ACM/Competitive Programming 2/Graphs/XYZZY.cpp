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

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vector<iii> es;
vector<ii> g[105];
int vis[105], neg[105][105], valid[105];

int dfs(int u, int t){
    if(vis[u]) return 0;
    vis[u]=1;
    if(u==t) return 1;
    for(int i=0; i<g[u].size(); i++) if(dfs(g[u][i].first, t)) return 1;
}

int main(){
    int n, c,k,u,v,w;
    while(scanf("%d", &n)>0){
        if(n==-1) break;
        for(int i=0; i<n; i++) g[i].clear();
        es.clear();
        for(int i=0; i<n; i++){
            scanf("%d %d", &c, &k);
            u=i+1;
            for(int j=0; j<k; j++){
                scanf("%d", &v);
                g[u].pb(ii(v,c));
                es.pb(iii(u, ii(v,-c)));
            }
        }
        g[0].pb(ii(1,100));
        es.pb(iii(0,ii(1,-100)));
        n++;

        int s=0, t=n-1;

        for(int i=0; i<n; i++){
            memset(vis, 0, sizeof vis);
            valid[i]=dfs(i,t);
        }
        vector<int> dists(n, 1000000000);
        dists[s]=0;

        for(int i=0; i<n-1; i++){
            for(int j=0; j<es.size(); j++){
                u = es[j].first, v = es[j].second.first, w = es[j].second.second;
                if(dists[v]>dists[u]+w) dists[v] = dists[u]+w;
            }
        }
        // check for neg cycles
        memset(neg, 0, sizeof neg);
        for(int j=0; j<es.size(); j++){
            u = es[j].first, v = es[j].second.first, w = es[j].second.second;
            if(dists[v]>dists[u]+w) neg[u][v]=1;
        }

        memset(vis, 0 , sizeof vis);

        bool solv=false;
        priority_queue<ii> pq;
        pq.push(ii(0,0));

        while(!pq.empty()){
            ii p = pq.top(); pq.pop();
            u = p.first, w = p.second;
            if(vis[u]) continue;
            vis[u]=1;
            if(u==t) { solv=true; break;}
            for(int i=0; i<g[u].size(); i++){
                if(w+g[u][i].second>0){
                    if(neg[u][g[u][i].first] && valid[u]) {solv=true; break;}
                    pq.push(ii(g[u][i].first, w+g[u][i].second));
                }
            }
        }

        if(solv) printf("winnable\n");
        else printf("hopeless\n");
    }
    return 0;
}
/*
5

*/
