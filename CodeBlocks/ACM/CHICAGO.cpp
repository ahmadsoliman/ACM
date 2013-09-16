#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 10000000
#define EPS 1e-8

vii g[105];
vector<double> dist;
int vis[105];

int main(){
    int n, m, i,j,k, u,v,w1, S,F;
    double w,d;
    while(scanf("%d", &n)>0){
        if(n==0) return 0;
        scanf("%d", &m);
        for(i=0; i<n; i++) g[i].clear();
        for(i=0; i<m; i++){
            scanf("%d %d %d", &u, &v, &w1);
            u--;v--;
            g[u].push_back(ii(v,w1));
            g[v].push_back(ii(u,w1));
        }
        S = 0;
        F = n-1;

        memset(vis, 0, sizeof vis);
        dist = vector<double>(n, 0.0);
        dist[S]=1.0;

        priority_queue< pair<double,int> > pq;
        pq.push(pair<double, int>(1.0, S));

        while(!pq.empty()){
            pair<double, int> front1 = pq.top(); pq.pop();
            w = front1.first; u = front1.second;
            if(u==F) break;
            if(!vis[u]){
                for(j=0; j<g[u].size(); j++){
                    pair<int, int> v = g[u][j];
                    d=dist[u]*(v.second/100.0);
                    if(d > dist[v.first]) {
                        dist[v.first] = d;
                        pq.push(pair<double,int>(d, v.first));
                    }
                }
            }
            vis[u]=1;
        }

        printf("%.6lf percent\n", dist[F]*100.0);

    }
    return 0;
}
