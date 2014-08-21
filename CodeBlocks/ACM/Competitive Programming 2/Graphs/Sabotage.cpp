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

int n;
int graph[110][110];
int vis[110], ps[110];

int maxFlow(int src, int sink){
    int flow=0, cnt=0, u,v, par;
    while(1){
        memset(vis, 0, sizeof vis);
        memset(ps, 0, sizeof ps);
        priority_queue<iii> q;
        q.push(iii(2000000000, ii(src,-1)));
        int maxflow=0;
        while(!q.empty()){
            iii p = q.top(); q.pop();
            u = p.second.first;
            par = p.second.second;
            if(vis[u]) continue;
            vis[u]=1;
            ps[u]=par;
            if(u==sink){
                maxflow=p.first;
                break;
            }
            for(int i=0; i<n; i++){
                if(graph[u][i]>0){
                    q.push(iii(min(p.first, graph[u][i]), ii(i, u)));
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
    }
    return flow;
}

int network[105][105];

void dfs(int node){
    if(vis[node]) return;
    vis[node]=1;
    for(int i=0; i<n; i++) if(graph[node][i]>0) dfs(i);
}

int main(){
    int m, u,v,w;
    while(scanf("%d %d", &n, &m)>0){
        if(!n&&!m) break;

        memset(network, 0, sizeof network);
        memset(graph, 0, sizeof graph);

        for(int i=0; i<m; i++){
            scanf("%d %d %d", &u, &v, &w);
            u--,v--;
            network[u][v]=w;
            network[v][u]=w;
            graph[u][v]=w;
            graph[v][u]=w;
        }
        int f = maxFlow(0, 1);

        memset(vis, 0, sizeof vis);
        dfs(0);

        for(int i=0; i<n; i++) for(int j=0; j<n; j++) if(vis[i] && !vis[j] && network[i][j]>0 && graph[i][j]==0) printf("%d %d\n", i+1, j+1);
        printf("\n");

    }
    return 0;
}

