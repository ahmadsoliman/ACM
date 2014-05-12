/*j ID: ahmadad1
PROG: butter
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
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vii graph1[805];
int vis[805], dist[805][805];

void dijkstra(int u){
    memset(vis, 0, sizeof vis);
    priority_queue<ii, vii, greater<ii> > pq;
    pq.push(ii(0,u));

    while(!pq.empty()){
        ii state=pq.top(); pq.pop();
        if(vis[state.second]) continue;
        vis[state.second]=1;
        dist[u][state.second]=state.first;

        for(int i=0; i<graph1[state.second].size(); i++){
            ii cur=graph1[state.second][i];
            if(!vis[cur.first])
                pq.push(ii(state.first+cur.second, cur.first));
        }
    }
}

int main() {
    freopen("butter.in", "r", stdin);
    freopen("butter.out", "w", stdout);

    int n,p,c, i,j,k,r,l, u,v,d;

    scanf("%d %d %d", &n, &p, &c);

    vi newnodes;

    for(i=0; i<n; i++) {
        scanf("%d", &k);
        newnodes.push_back(k-1);
    }

    for(i=0; i<c; i++){
        scanf("%d %d %d", &u, &v, &d);
        u--,v--;
        graph1[u].push_back(ii(v,d)), graph1[v].push_back(ii(u,d));
    }

    memset(dist, 0 , sizeof dist);
    for(i=0; i<newnodes.size(); i++) dijkstra(newnodes[i]);

    /*
    for(i=0; i<p; i++){
        for(j=0; j<p; j++){
            printf("%d %d --> %d :: %d\n", i,j, dist[i][j], dist[j][i]);
        }
    }
    */

    int res=1000000000, cur;
    for(i=0; i<p; i++){
        cur=0;
        for(j=0; j<newnodes.size(); j++){
            //if(newnodes[j]==i) continue;
            cur+=dist[newnodes[j]][i];

            //printf("%d %d %d\n", i, newnodes[j], dist[newnodes[j]][i]);
        }

        res=min(res, cur);
    }

    printf("%d\n", res);

    return 0;
}
