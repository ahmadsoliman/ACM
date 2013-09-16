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

vii g[10010];
map<string, int> names;
char name[20], n1[20], n2[20];
vi dist;

int main(){
    int t, n, i, j, u, v, w, deg, qN, S, F;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        names.clear();
        for(i=0; i<n; i++){
            scanf("%s", name);
            names.insert(pair<string,int>(string(name),i));

            scanf("%d", &deg);
            g[i].clear();
            for(j=0; j<deg; j++){
                scanf("%d %d", &v, &w);
                g[i].push_back(make_pair(v-1, w));
            }
        }
        scanf("%d", &qN);
        for(i=0; i<qN; i++){
            scanf("%s %s", n1, n2);
            S = names.find(string(n1))->second;
            F = names.find(string(n2))->second;

            dist = vector<int>(n, INF);
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

            printf("%d\n", dist[F]);
        }
    }
    return 0;
}
