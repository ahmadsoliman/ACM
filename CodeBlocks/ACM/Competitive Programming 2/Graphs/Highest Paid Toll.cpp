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

vector<ii> graph[10005];
int vis[10005];

int main(){
    int ts;
    scanf("%d", &ts);

    int n,m,p, s,t;
    int u,v,w;
    while(ts--){
        scanf("%d %d %d %d %d", &n,&m,&s,&t,&p);
        s--,t--;

        for(int i=0; i<n; i++) graph[i].clear();
        for(int i=0; i<m; i++){
            scanf("%d %d %d", &u, &v, &w);
            u--,v--;
            graph[u].push_back(ii(v,w));
        }

        memset(vis, 0, sizeof vis);
        int maxt=-1;
        priority_queue<iii> pq;
        pq.push(iii(0, ii(s, p)));
        while(!pq.empty()){
            iii c = pq.top(); pq.pop();
            u = c.second.first;
            if(vis[u]) continue;
            vis[u]=1;

            if(u==t) {maxt=c.first; break;}

            for(int i=0; i<graph[u].size(); i++)
                if(c.second.second>=graph[u][i].second)
                    pq.push(iii(max(c.first, graph[u][i].second),ii(graph[u][i].first, c.second.second-graph[u][i].second)));
        }
        printf("%d\n", maxt);
    }
    return 0;
}




