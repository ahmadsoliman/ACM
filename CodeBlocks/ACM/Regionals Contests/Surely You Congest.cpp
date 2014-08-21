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
vector<vector<ii> > graph;
vector<ii> network[25010];
int vis[25010], ps[25010];

int getw(int u, int v){
    for(int i=0; i<graph[u].size(); i++) if(graph[u][i].first==v) return graph[u][i].second;
    return 0;
}

void updatew(int u, int v, int w){
    for(int i=0; i<graph[u].size(); i++)
        if(graph[u][i].first==v) { graph[u][i].second+=w; return; }
    graph[u].push_back(ii(v,w));
}

int maxFlow(int src, int sink){
    int flow=0, u,v, par, len=-1;
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
            updatew(u,v,-maxflow);
            updatew(v,u,maxflow);
            v = u;
        }

        flow+=maxflow;
    }
    return flow;
}

int dist[25100];
vector<vector<ii> > newg;

void dijkstra(int node){
    newg = vector<vector<ii> >(nodes);
    priority_queue<iii, vector<iii>, greater<iii> > pq;
    pq.push(iii(0, ii(node, -1)));
    int u,v;
    while(!pq.empty()){
        iii p = pq.top(); pq.pop();
        u=p.second.first;
        v=p.second.second;
        if(p.first>dist[u]) continue;
        else if(p.first==dist[u]) {
            newg[u].push_back(ii(v,1));
            continue;
        }
        dist[u]=p.first;
        if(v!=-1){
            newg[u].push_back(ii(v,1));
        }

        for(int i=0; i<network[u].size(); i++){
            pq.push(iii(dist[u]+network[u][i].second, ii(network[u][i].first, u)));
        }
    }
}

int cars[1010];
map<int,vector<int> >  comps;

int main(){
    int n,m,c, u,v,w;
    while(scanf("%d %d %d", &n, &m, &c)>0){
        nodes = n+1;
        for(int i=0; i<nodes; i++) dist[i]=1000000000, network[i].clear();
        for(int i=0; i<m; i++){
            scanf("%d %d %d", &u, &v, &w);
            u--,v--;
            network[u].push_back(ii(v,w));
            network[v].push_back(ii(u,w));
        }

        dijkstra(0);
        comps.clear();

        int carsDT=0;
        memset(cars, 0, sizeof cars);
        for(int i=0; i<c; i++){
            scanf("%d", &u);
            u--;
            cars[i]=u;
            if(u==0) {
                carsDT++;
                continue;
            }
            if(comps.find(dist[u])==comps.end()){
                vector<int> vec;
                vec.push_back(i);
                comps[dist[u]]=vec;
            }else{
                comps[dist[u]].push_back(i);
            }
        }
        int cnt=0;
        vector<int> vec;
        for(map<int, vector<int> >::iterator it=comps.begin(); it!=comps.end(); it++){
            graph = newg;
            vec = it->second;
            for(int i=0; i<vec.size(); i++){
                graph[nodes-1].push_back(ii(cars[vec[i]],1));
            }
            cnt += maxFlow(nodes-1, 0);
        }

        printf("%d\n", cnt+carsDT);
    }
    return 0;
}
/*
3 3 2
1 2 42
2 3 1
2 3 1
2 3
4 4 5
1 2 5
1 3 4
4 2 5
4 3 6
4 4 4 4 1
4 4 5
1 2 5
1 3 4
4 2 5
4 3 6
4 4 4 3 1
*/














