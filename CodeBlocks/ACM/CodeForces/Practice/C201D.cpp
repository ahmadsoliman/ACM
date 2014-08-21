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

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vector<int> g[1000005];

int vis[1000005], solv[1000005];

int dfs(int u, int t){
    if(vis[u]) return solv[u];
    vis[u]=1;
    solv[u]=0;
    if(u==t) return solv[u]=1;
    for(int i=0; i<g[u].size(); i++){
        solv[u] |= dfs(g[u][i], t);
    }
    return solv[u];
}

int main() {
    int n,m,u,v,s,t;
    scanf("%d %d", &n, &m);

    for(int i=0; i<m; i++){
        scanf("%d %d", &u, &v);
        u--,v--;
        g[u].push_back(v);
    }
    scanf("%d %d", &s, &t);
    s--,t--;

    dfs(s,t);

    if(solv[s]==0){
        printf("-1\n");
        return 0;
    }



    printf("%d\n", maxv);

    return 0;

}
