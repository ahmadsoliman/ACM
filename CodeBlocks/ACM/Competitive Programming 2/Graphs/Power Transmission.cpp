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
int graph[1100][1100];
int vis[1100], ps[1100];

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
int nodeCap[105];
int sources[105], sinks[105];

int main(){
    int N, m, u,v,w,b,d;
    while(scanf("%d", &N)>0){
        memset(network, 0, sizeof network);
        memset(graph, 0, sizeof graph);
        memset(sources, 0, sizeof sources);
        memset(sinks, 0, sizeof sinks);


        for(int i=0; i<N; i++) scanf("%d", &nodeCap[i]);
        scanf("%d", &m);
        for(int i=0; i<m; i++){
            scanf("%d %d %d", &u, &v, &w);
            u--,v--;
            network[u][v]=w;
        }

        scanf("%d %d", &b, &d);
        for(int i=0; i<b; i++) scanf("%d", &sources[i]), sources[i]--;
        for(int i=0; i<d; i++) scanf("%d", &sinks[i]), sinks[i]--;

        n = 2 + 2*N;
        for(int i=0; i<b; i++) graph[0][1+2*sources[i]]=1000000000;
        for(int i=0; i<d; i++) graph[1+2*sinks[i]+1][n-1]=1000000000;

        for(int i=0; i<N; i++) graph[1+2*i][1+2*i+1]=nodeCap[i];
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(network[i][j]>0)
                    graph[1+2*i+1][1+2*j]=network[i][j];
            }
        }

        printf("%d\n", maxFlow(0, n-1));
    }

    return 0;
}
