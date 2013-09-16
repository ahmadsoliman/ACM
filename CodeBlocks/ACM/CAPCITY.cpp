#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

#define DFS_WHITE 0

vi g[100010], AdjList[100010], sccin;
vector< set<int> > scc;

int dfsNumberCounter, numSCC;
vi dfs_num, dfs_low, S, visited;

void tarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    S.push_back(u);
    visited[u] = 1;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        int v = AdjList[u][j];
        if (dfs_num[v] == DFS_WHITE)
            tarjanSCC(v);
        if (visited[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if (dfs_low[u] == dfs_num[u]) {
        scc.push_back(set<int>());
        while (1) {
            int v = S.back(); S.pop_back(); visited[v] = 0;
            scc[scc.size()-1].insert(v);
            if (u == v) break;
        }
    }
}

int main(){
    int n, m, i,j,k,l, u,v, incnt, found;
    scanf("%d %d", &n, &m);
    for(i=0; i<m; i++){
        scanf("%d %d", &u, &v);
        u--; v--;
        g[u].push_back(v);
        AdjList[v].push_back(u);
    }

    dfs_num.assign(n, DFS_WHITE); dfs_low.assign(n, 0); visited.assign(n, 0);
    dfsNumberCounter = numSCC = 0;
    for (i = 0; i < n; i++) if (dfs_num[i] == DFS_WHITE) tarjanSCC(i);

    found=-1;
    set<int> :: iterator it, same;
    for(i=0; i<scc.size(); i++){
        incnt=0;
        for(it=scc[i].begin(); it!=scc[i].end(); it++) {
            for(j=0; j<g[*it].size(); j++){
                same = scc[i].find(g[*it][j]);
                if(same==scc[i].end()) { incnt++; break; }
            }
            if(incnt>0) break;
        }
        if(incnt==0){
            if(found==-1) found=i;
            else { printf("0\n"); return 0;}
        }
    }
    if(found==-1) { printf("0\n"); return 0;}

    vi res;
    for(it=scc[found].begin(); it!=scc[found].end(); it++) res.push_back(*it);
    sort(res.begin(), res.end());

    printf("%d\n", res.size());
    for(i=0; i<res.size(); i++) {
        printf("%d", res[i]+1);
        if(i<res.size()-1) printf(" ");
    }
    printf("\n");
    return 0;
}
