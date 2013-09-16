#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

vi dist;

int main(){
    int t, n, i, j, u, v, w, deg, m, S, F;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d%d", &n, &m, &S, &F);
        S--; F--;

        vii g[100010];
        for(i=0; i<m; i++){
            scanf("%d%d%d", &u, &v, &w);
            u--; v--;
            g[u].push_back(ii(v,w));
            g[v].push_back(ii(u,w));
        }

        dist = vi(n, INF);
        dist[S]=0;

        priority_queue< ii, vii, greater<ii> > pq;
        pq.push(ii(0, S));

        while(!pq.empty()){
            ii front = pq.top(); pq.pop();
            w = front.first; u = front.second;
            if(u==F) break;
            if(w == dist[u]){
                for(j=0; j<g[u].size(); j++){
                    ii v = g[u][j];
                    if(dist[u]+v.second < dist[v.first]){
                        dist[v.first] = dist[u]+v.second;
                        pq.push(ii(dist[v.first], v.first));
                    }
                }
            }
        }

        if(dist[F]==INF) printf("NONE\n");
        else printf("%d\n", dist[F]);

    }
    return 0;
}
