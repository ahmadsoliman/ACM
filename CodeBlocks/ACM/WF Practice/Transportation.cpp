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

int n, K, dp[105][105][105];
vector<iii> graph[200];
int vis[200], ps[200], ind[200];

ll maxFlow(int src, int sink){
    int flow=0, u,v;
    memset(dp, 0, sizeof dp);
    while(1){
        memset(vis, 0, sizeof vis);
        memset(ps, 0, sizeof ps);
        memset(ind, 0, sizeof ind);
        priority_queue<iiii, vector<iiii>, greater<iiii> > q;
        q.push(iiii(ii(0,-1), ii(src,-1)));
        int maxflow=0;
        while(!q.empty()){
            iiii p = q.top(); q.pop();
            u = p.second.first;
            if(vis[u]) continue;
            vis[u]=1;
            ps[u]=p.second.second;
            ind[u]=p.first.second;
            if(u==sink){
                maxflow=1;
                break;
            }
            for(int i=0; i<graph[u].size(); i++){
                if(graph[u][i].second.first>0){
                    q.push(iiii(ii(graph[u][i].second.second*pow(dp[u][graph[u][i].first][graph[u][i].second.second]+1,2), i), ii(graph[u][i].first, u)));
                }
            }
        }
        if(maxflow==0) break;
        v = sink;
        while(ps[v]!=-1){
            u = ps[v];
            graph[u][ind[v]].second.first--;
            graph[v].push_back(iii(u, ii(1, 0)));
            dp[u][v][graph[u][ind[v]].second.second]++;
            v = u;
        }
        flow+=maxflow;
    }
    if(flow<K) return -1;
    ll res=0;
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
    for(int k=0; k<100; k++)
        res+=dp[i][j][k]*dp[i][j][k]*k;
    return res;
}

int main(){
    int N, M, u,v, as, cs;
    while(scanf("%d %d %d", &N, &M, &K)>0){
        for(int i=0; i<=N; i++) graph[i].clear();
        for(int i=0; i<M; i++){
            scanf("%d %d", &u, &v);
            scanf("%d %d", &as, &cs);
            graph[u].push_back(iii(v,ii(cs, as)));
        }
        n = N+1;
        graph[0].push_back(iii(1, ii(K,0)));
        printf("%lld\n", maxFlow(0, N));
    }
    return 0;
}




