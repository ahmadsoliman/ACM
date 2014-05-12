/*j ID: ahmadad1
PROG: cowtour
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
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int x[200], y[200];
char in[200];

vdi graph[155];

double dist(int i, int j){
    return hypot(x[j]-x[i], y[j]-y[i]);
}

int vis[155], comp[155];
double compDiam[155];

void dfs(int i, int c){
    if(vis[i]) return;
    comp[i]=c;
    vis[i]=1;

    for(int j=0; j<graph[i].size(); j++){
        dfs(graph[i][j].second, c);
    }
}

double dijkstra(int u){
    priority_queue<di, vdi, greater<di> > pq;
    pq.push(di(0,u));
    memset(vis, 0, sizeof vis);

    double d=0;

    while(!pq.empty()){
        di state=pq.top(); pq.pop();
        u=state.second;

        if(vis[u]) continue;
        vis[u]=1;
        d = max(d, state.first);

        for(int i=0; i<graph[u].size(); i++){
            if(vis[graph[u][i].second]) continue;
            pq.push(di(state.first+graph[u][i].first, graph[u][i].second));
        }
    }
    return d;
}

double maxdist[155];
int adjMat[155][155];

int main() {
    freopen("cowtour.in", "r", stdin);
    freopen("cowtour.out", "w", stdout);

    int n, i,j,k,r,l;
    double d;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d %d", &x[i], &y[i]);

    for(i=0; i<n; i++){
        scanf("%s", in);
        for(j=0; j<n; j++)
            if(in[j]=='1')
                d=dist(i,j),
                graph[i].push_back(di(d, j)),
                graph[j].push_back(di(d, i));
    }

    double minDiam=100000000, maxd=0;

    int c=0;
    memset(vis, 0, sizeof vis);
    for(i=0; i<n; i++){
        if(!vis[i]){
            dfs(i, c++);
        }
    }

    for(i=0; i<n; i++){
        maxdist[i]=dijkstra(i);
    }

    for(k=0; k<c; k++) {

        compDiam[k]=0;
        for(i=0; i<n; i++) if(comp[i]==k) compDiam[k]=max(compDiam[k], dijkstra(i));
        maxd=max(maxd, compDiam[k]);

        //printf("%d %.6lf\n", c, compDiam[k]);
    }

    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(comp[i]==comp[j]) continue;
            d=dist(i, j);
            minDiam = min(minDiam, d+maxdist[i]+maxdist[j]);
        }
    }

    printf("%.6lf\n", max(maxd, minDiam));

    return 0;
}
