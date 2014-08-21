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
typedef pair<ii, ii> iiii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vector<int> graph[55];
map<string, int> sti;
char in[10000];
int dist[100], vis[100];

void dfs(int i){
    if(vis[i]) return;
    vis[i]=1;
    for(int j=0; j<graph[i].size(); j++) dfs(graph[i][j]);
}

int main(){
    int n,m,ind,kase=1;
    int u,v;
    while(scanf("%d %d", &n, &m)){
        if(!n&&!m) break;

        for(int i=0; i<n; i++) graph[i].clear();
        sti.clear();
        ind=0;
        for(int i=0; i<m; i++){
            scanf("%s", in);
            string name(in);
            map<string, int>::iterator it = sti.find(name);
            if(it==sti.end()) u = sti[name] = ind++;
            else u = sti[name];

            scanf("%s", in);
            name = string(in);
            it = sti.find(name);
            if(it==sti.end()) v = sti[name] = ind++;
            else v = sti[name];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        memset(vis, 0, sizeof vis);
        dfs(0);
        bool connected=true;
        for(int i=0; i<n && connected; i++) if(!vis[i]) connected=false;
        if(!connected){
            printf("Network %d: DISCONNECTED\n\n", kase++);
            continue;
        }

        int maxSperation=0;
        for(int i=0; i<n; i++){
            memset(dist, 0, sizeof dist);
            memset(vis, 0, sizeof vis);
            queue<ii> q;
            q.push(ii(i,0));
            while(!q.empty()){
                ii p = q.front(); q.pop();
                u = p.first;
                if(vis[u]) continue;
                vis[u]=1;
                dist[u]=p.second;
                for(int j=0; j<graph[u].size(); j++) {
                    q.push(ii(graph[u][j], dist[u]+1));
                }
            }
            for(int j=0; j<n; j++) maxSperation = max(maxSperation, dist[j]);
        }
        printf("Network %d: %d\n\n", kase++, maxSperation);
    }

    return 0;
}
