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

vi graph[200100];
int dfs_num[200100], dfs_low[200100], vis[200100], dfsC, numSCC, scc[200100];
vi S;

void tarjanSCC(int u){
    dfs_num[u]=dfs_low[u]=dfsC++;
    S.push_back(u);
    vis[u]=1;
    for(int i=0; i<graph[u].size(); i++){
        if(dfs_num[graph[u][i]]==-1) tarjanSCC(graph[u][i]);
        if(vis[graph[u][i]]) dfs_low[u] = min(dfs_low[u], dfs_low[graph[u][i]]);
    }
    if(dfs_low[u]==dfs_num[u]){
        scc[u]=numSCC;
        while(1){
            int v = S.back(); S.pop_back();
            vis[v]=0;
            scc[v]=numSCC;
            if(u==v) break;
        }
        numSCC++;
    }
}

int main(){
    int n, m, u, v;
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
    }
    dfsC=numSCC=0;
    memset(vis, 0, sizeof vis);
    memset(dfs_low, 0, sizeof dfs_low);
    memset(dfs_num, -1, sizeof dfs_num);
    for(int i=0; i<n; i++) if(dfs_num[i]==-1) tarjanSCC(i);

    printf("%d\n", numSCC);
    for(int i=0; i<n; i++) printf("%d ", scc[i]);

    return 0;
}
/*
8 9
0 1
1 3
3 2
2 1
3 4
4 5
5 6
6 7
7 4

7 8
0 2
2 3
3 0
0 1
1 5
5 4
4 1
5 6
*/
