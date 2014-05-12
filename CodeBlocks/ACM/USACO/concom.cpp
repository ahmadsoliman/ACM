/*j ID: ahmadad1
PROG: concom
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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n, per[105][105], vis[105];

map<int, int> iti, iti2;

vvi graph;

vi dfs(int u){
    if(vis[u]) return graph[u];
    vis[u]=1;

    for(int i=0; i<graph[u].size(); i++){
        vi cur = dfs(graph[u][i]);
        for(int j=0; j<cur.size(); j++){
            if(find(graph[u].begin(), graph[u].end(), cur[j])==graph[u].end()) graph[u].push_back(cur[j]);
        }
    }
    return graph[u];
}

set<ii> res;

int main() {
    //freopen("concom.in", "r", stdin);
    //freopen("concom.out", "w", stdout);

    int i,j,k, trip, u,v,p;

    scanf("%d", &trip);

    n=0;
    memset(per, 0, sizeof per);
    for(i=0; i<trip; i++){
        scanf("%d %d %d", &u, &v, &p);

        if(iti.find(u)!=iti.end()){
            u=iti[u];
        }else iti.insert(ii(u, n)), iti2.insert(ii(n,u)), u=n++;

        if(iti.find(v)!=iti.end()){
            v=iti[v];
        }else iti.insert(ii(v, n)), iti2.insert(ii(n,v)), v=n++;

        per[u][v]=p;
    }

    graph = vvi(n, vi());

    for(i=0; i<n; i++) for(j=0; j<n; j++) if(per[i][j]>50) graph[i].push_back(j);

    for(i=0; i<n; i++){
        for(k=0; k<graph[i].size(); k++){
            for(j=0; j<n; j++){
                per[i][j]+=per[graph[i][k]][j];
            }
        }
    }

    for(i=0; i<n; i++) for(j=0; j<n; j++) if(per[i][j]>50) graph[i].push_back(j);

    memset(vis, 0, sizeof vis);
    for(i=0; i<n; i++) if(!vis[i]) dfs(i);

    for(i=0; i<n; i++) for(j=0; j<graph[i].size(); j++) if(i!=graph[i][j]) res.insert(ii(iti2[i],iti2[graph[i][j]]));

    for(set<ii>::iterator it=res.begin(); it!=res.end(); it++) printf("%d %d\n", (*it).first, (*it).second);

    return 0;
}
