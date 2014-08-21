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

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int nodes;
int graph[110][110];
int network[110][110];
int vis[110], ps[110];

int maxFlow(int src, int sink, int g){
    int flow=0, cnt=0, u,v, par, maxe=0;
    while(1){
        memset(vis, 0, sizeof vis);
        memset(ps, 0, sizeof ps);
        priority_queue<iiii, vector<iiii>, greater<iiii> > q;
        q.push(iiii(ii(0,2000000000), ii(src,-1)));
        int maxflow=0;
        while(!q.empty()){
            iiii p = q.top(); q.pop();
            u = p.second.first;
            par = p.second.second;
            if(vis[u]) continue;
            vis[u]=1;
            ps[u]=par;
            if(u==sink){
                maxe = max(maxe, p.first.first);
                maxflow=p.first.second;
                break;
            }
            for(int i=0; i<nodes; i++){
                if(graph[u][i]>0){
                    q.push(iiii(ii(max(p.first.first, network[u][i]), min(p.first.second, graph[u][i])), ii(i, u)));
                }
            }
        }
        if(maxflow==0) break;
        v = sink;
        while(ps[v]!=-1){
            u = ps[v];
            graph[u][v]-=maxflow;
            graph[v][u]+=maxflow;
            v = u;
        }
        cnt++;
        flow+=maxflow;
        if(flow>=g) break;
    }
    if(flow<g) return -1;
    return maxe*100;
}

int main(){
    int t, n, m, k, l, g, u,v,w;

    scanf("%d", &t);
    while(t--){
        memset(graph, 0, sizeof graph);
        memset(network, 0, sizeof network);
        scanf("%d %d %d %d %d", &n, &m, &k, &l, &g);
        nodes = n + 2;
        for(int i=0; i<m; i++){
            scanf("%d %d %d", &u, &v, &w);
            u--,v--;
            graph[u][v]=graph[v][u]=w;
            network[u][v]=network[v][u]=w;
        }
        for(int i=0; i<k; i++) scanf("%d", &u), u--, graph[nodes-2][u]=2000000000;
        for(int i=0; i<l; i++) scanf("%d", &u), u--, graph[u][nodes-1]=2000000000;
        printf("%d\n", maxFlow(nodes-2, nodes-1, g));
    }

    return 0;
}




