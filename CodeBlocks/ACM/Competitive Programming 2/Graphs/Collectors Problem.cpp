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
            for(int i=0; i<nodes; i++){
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

int freq[15][30];

int main(){
    int t, n, m, k, s, kase=1;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);

        memset(freq, 0, sizeof freq);
        for(int i=0; i<n; i++){
            scanf("%d", &k);
            while(k--) scanf("%d", &s), freq[i][s]++;
        }

        m++;
        nodes = 1+n*m;
        memset(graph, 0, sizeof graph);

        for(int i=0; i<n; i++){
            for(int k=1; k<m; k++){
                if(freq[i][k]==0) graph[1+i*m+k][(i==0)?0:1+i*m]=1;
                else if(freq[i][k]>1) graph[1+i*m][1+i*m+k]=freq[i][k]-1;
            }
            for(int j=0; j<n; j++){
                if(i==j) continue;
                for(int k=1; k<m; k++){
                    if(freq[i][k]>1&&freq[j][k]==0) graph[1+i*m+k][1+j*m+k]=1000000000;
                }
            }
        }
        graph[0][1]=0;

        int cnt=0;
        for(int k=1; k<m; k++) if(freq[0][k]>0) cnt++;
        printf("Case #%d: %d\n", kase++, maxFlow(1,0)+cnt);
    }
    return 0;
}















