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

int x[105],y[105],ni[105],mi[105];
double dists[105][105];
vector<int> res;

double dist(int x1, int y1, int x2, int y2){
    return hypot(x1 - x2, y1 - y2);
}

int main(){
    int t, N, cur, sum;
    double D;
    scanf("%d", &t);
    while(t--){
        sum=0;
        scanf("%d %lf", &N, &D);
        for(int i=0; i<N; i++){
            scanf("%d %d %d %d", &x[i], &y[i], &ni[i], &mi[i]);
            sum+=ni[i];
        }
        for(int j=0; j<N; j++)
        for(int k=j+1; k<N; k++)
            dists[j][k]=dist(x[j],y[j],x[k],y[k]);

        res.clear();
        for(int i=0; i<N; i++){
            memset(graph, 0, sizeof graph);
            n = 1+2*N;
            cur = sum-ni[i];

            for(int j=0; j<N; j++) graph[0][1+2*j]=ni[j], graph[1+2*j][1+2*j+1]=mi[j];

            for(int j=0; j<N; j++)
            for(int k=j+1; k<N; k++)
                if(dists[j][k]<D || fabs(D-dists[j][k])<1e-9) graph[1+2*j+1][1+2*k]=graph[1+2*k+1][1+2*j]=1000000000;

            int f = maxFlow(0, 1+2*i);
            if(f==sum) res.push_back(i);
        }
        if(res.size()==0) printf("-1\n");
        else{
            printf("%d", res[0]);
            for(int i=1; i<res.size(); i++) printf(" %d", res[i]);
            printf("\n");
        }
    }
    return 0;
}
