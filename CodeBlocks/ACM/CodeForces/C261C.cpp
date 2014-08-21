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

#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

typedef std::pair<int, int> myPair_type;

struct ii_comp{
  bool operator()(myPair_type const& lhs, myPair_type const& rhs){
    return lhs.second < rhs.second;
  }
};

vector<myPair_type> graph[300100];
vi cnts[300100];
int vis[300100];

int dfs(int u, int w){
    if(vis[u]){
        int maxv=0;
        for(int i=0; i<cnts[u].size(); i++) {
            if(cnts[u][i]==-1 && graph[u][i].second>w) cnts[u][i]=dfs(graph[u][i].first, graph[u][i].second)+1;
            if(graph[u][i].second>w) maxv=max(maxv, cnts[u][i]);
        }
        return maxv;
    }
    vis[u]=1;
    int maxv=0;
    for(int i=0; i<graph[u].size(); i++){
        if(cnts[u][i]==-1 && graph[u][i].second>w) {
            cnts[u][i] = dfs(graph[u][i].first, graph[u][i].second)+1;
            maxv=max(maxv, cnts[u][i]);
        }
    }
    return maxv;
}

vii l;

int main() {
    int n, m, u,v,w;
    scanf("%d %d", &n, &m);

    for(int i=0; i<m; i++){
        scanf("%d %d %d", &u, &v, &w);
        l.push_back(ii(w, u));
        graph[u-1].push_back(ii(v-1,w));
    }

    for(int i=0; i<n; i++) cnts[i]=vi(graph[i].size(), -1), sort(graph[i].begin(), graph[i].end(), ii_comp());

    memset(vis, 0, sizeof vis);

    sort(l.begin(), l.end());
    int maxv=0;
    for(int i=0; i<l.size(); i++) if(vis[l[i].second]==0) maxv = max(maxv, dfs(l[i].second, 0));
    printf("%d\n", maxv);

    return 0;

}
