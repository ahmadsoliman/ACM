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
vector<ii> graph[60005];
int vis[60005], ps[60005];

int getw(int u, int v){
    for(int i=0; i<graph[u].size(); i++) if(graph[u][i].first==v) return graph[u][i].second;
    return 0;
}

void updatew(int u, int v, int w){
    for(int i=0; i<graph[u].size(); i++)
        if(graph[u][i].first==v) { graph[u][i].second=w; return; }
    graph[u].push_back(ii(v,w));
}

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
            for(int i=0; i<graph[u].size(); i++){
                if(graph[u][i].second>0){
                    q.push(iii(min(p.first, graph[u][i].second), ii(graph[u][i].first, u)));
                }
            }
        }
        if(maxflow==0) break;
        v = sink;
        while(ps[v]!=-1){
            u = ps[v];
            int uv = getw(u,v), vu = getw(v,u);
            updatew(u,v,uv-maxflow);
            updatew(v,u,vu+maxflow);
            v = u;
        }
        cnt++;
        flow+=maxflow;
    }
    return flow;
}
