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

int main(){
    int m,w,k, u,v;
    while(scanf("%d %d", &m, &w)>0){
        if(!m&&!w) break;

        memset(graph, 0, sizeof graph);
        n = 2*m;
        graph[0][1]=graph[2*m-2][2*m-1]=1000000000;
        for(int i=1; i<m-1; i++) {
            scanf("%d", &k);
            k--;
            scanf("%d", &graph[2*k][2*k+1]);
        }

        for(int i=0; i<w; i++){
            scanf("%d %d %d", &u, &v, &k);
            u--,v--;
            graph[2*u+1][2*v]=graph[2*v+1][2*u]=k;
        }

        printf("%d\n", maxFlow(0, 2*m-1));
    }
    return 0;
}




