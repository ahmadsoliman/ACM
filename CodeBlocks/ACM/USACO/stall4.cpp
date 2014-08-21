/*j ID: ahmadad1
PROG: stall4
LANG: C++
*/
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

int graph[505][505];
int vis[505], ps[505];

int main(){
    freopen("stall4.in", "r", stdin);
    freopen("stall4.out", "w", stdout);

    memset(graph, 0, sizeof graph);
    int n,m;
    scanf("%d %d", &n, &m);
/*
source: 0
cows: 1-n
machinces: n+1-n+m
sink: n+m+1
*/

    int u,v,cap, par, k;
    for(int i=1; i<=n; i++) {
        graph[0][i]=1;
        scanf("%d", &k);
        for(int j=0; j<k; j++){
            scanf("%d", &u);
            graph[i][n+u]=1;
        }
    }
    for(int i=n+1; i<=n+m; i++){
        graph[i][n+m+1]=1;
    }

    int flow=0, cnt=0;
    while(1){
        memset(vis, 0, sizeof vis);
        memset(ps, 0, sizeof ps);
        priority_queue<iii> q;
        q.push(iii(2000000000, ii(0,-1)));
        int maxflow=0;
        while(!q.empty()){
            iii p = q.top(); q.pop();
            u = p.second.first;
            par = p.second.second;
            if(vis[u]) continue;
            vis[u]=1;
            ps[u]=par;
            if(u==n+m+1){
                maxflow=p.first;
                break;
            }
            for(int i=0; i<=n+m+1; i++){
                if(graph[u][i]>0){
                    q.push(iii(min(p.first, graph[u][i]), ii(i, u)));
                }
            }
        }
        if(maxflow==0) break;
        v = n+m+1;
        while(ps[v]!=-1){
            u = ps[v];
            graph[u][v]-=maxflow;
            graph[v][u]+=maxflow;
            v = u;
        }
        cnt++;
        flow+=maxflow;
    }
    printf("%d\n", flow);

    return 0;
}












