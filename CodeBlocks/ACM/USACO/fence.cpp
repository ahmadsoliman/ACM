/*j ID: ahmadad1
PROG: fence
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
typedef long long ll;

vector<ii> graph[555];
vi res;

void dfs(int u){
    for(int i=0; i<graph[u].size(); i++){
        if(graph[u][i].second) continue;
        graph[u][i].second=1;

        for(int j=0; j<graph[graph[u][i].first].size(); j++){
            if(graph[graph[u][i].first][j].first==u && graph[graph[u][i].first][j].second==0){
                graph[graph[u][i].first][j].second=1;
                break;
            }
        }
        dfs(graph[u][i].first);
    }
    res.push_back(u);
}

int main() {
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);

    int i,j,k, e,n, u,v, minn=10000, maxn=0, odde;

    scanf("%d", &e);
    for(i=0; i<e; i++){
        scanf("%d %d", &u, &v);
        minn=min(minn, min(u,v));
        maxn=max(maxn, max(u,v));
        graph[u].push_back(ii(v,0));
        graph[v].push_back(ii(u,0));
    }

    for(i=minn; i<=maxn; i++) sort(graph[i].begin(), graph[i].end());
    odde=minn;
    for(i=minn; i<=maxn; i++) if(graph[i].size()%2) { odde=i; break; }

    dfs(odde);
    for(i=res.size()-1; i>=0; i--) printf("%d\n", res[i]);

    return 0;
}





