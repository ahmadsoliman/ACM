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

const int INF = 2000000000;

struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic {
  int N;
  vector<vector<Edge> > G;
  vector<Edge *> dad;
  vector<int> Q;

  Dinic(int N) : N(N), G(N), dad(N), Q(N) {}

  void AddEdge(int from, int to, int cap) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }

  long long BlockingFlow(int s, int t) {
    fill(dad.begin(), dad.end(), (Edge *) NULL);
    dad[s] = &G[0][0] - 1;

    int head = 0, tail = 0;
    Q[tail++] = s;
    while (head < tail) {
      int x = Q[head++];
      for (int i = 0; i < G[x].size(); i++) {
	Edge &e = G[x][i];
	if (!dad[e.to] && e.cap - e.flow > 0) {
	  dad[e.to] = &G[x][i];
	  Q[tail++] = e.to;
	}
      }
    }
    if (!dad[t]) return 0;

    long long totflow = 0;
    for (int i = 0; i < G[t].size(); i++) {
      Edge *start = &G[G[t][i].to][G[t][i].index];
      int amt = INF;
      for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
	if (!e) { amt = 0; break; }
	amt = min(amt, e->cap - e->flow);
      }
      if (amt == 0) continue;
      for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
	e->flow += amt;
	G[e->to][e->index].flow -= amt;
      }
      totflow += amt;
    }
    return totflow;
  }

  long long GetMaxFlow(int s, int t) {
    long long totflow = 0;
    while (long long flow = BlockingFlow(s, t))
      totflow += flow;
    return totflow;
  }
};

int nodes;
int dist[25100];
vector<ii> newg;
vector<ii> network[25010];

void dijkstra(int node){
    newg.clear();
    priority_queue<iii, vector<iii>, greater<iii> > pq;
    pq.push(iii(0, ii(node, -1)));
    int u,v;
    while(!pq.empty()){
        iii p = pq.top(); pq.pop();
        u=p.second.first;
        v=p.second.second;
        if(p.first>dist[u]) continue;
        else if(p.first==dist[u]) {
            if(v!=-1) newg.push_back(ii(u,v));
            continue;
        }
        dist[u]=p.first;
        if(v!=-1){
            newg.push_back(ii(u,v));
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
            Dinic d(nodes);
            for(int i=0; i<newg.size(); i++) d.AddEdge(newg[i].first, newg[i].second, 1);

            vec = it->second;
            for(int i=0; i<vec.size(); i++){
                d.AddEdge(nodes-1,cars[vec[i]],1);
            }
            cnt += d.GetMaxFlow(nodes-1, 0);
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





