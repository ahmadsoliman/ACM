/*j ID: ahmadad1
PROG: comehome
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
typedef pair<char, int> ci;
typedef pair<int, char> ic;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int vis[100];
vvii graph;
map<char, int> cti;
map<int, char> itc;

int main() {
    freopen("comehome.in", "r", stdin);
    freopen("comehome.out", "w", stdout);

    int i,j,k, e, d, n=0, u,v, barni;
    char uc[2], vc[2], c;

    graph = vvii(60, vii());
    scanf("%d", &e);
    for(i=0; i<e; i++){
        scanf("%s %s %d", &uc, &vc, &d);

        if(cti.find(uc[0])==cti.end())  u=n, cti.insert(ci(uc[0], n)), itc.insert(ic(n++, uc[0]));
        else u=cti[uc[0]];

        if(cti.find(vc[0])==cti.end())  v=n, cti.insert(ci(vc[0], n)), itc.insert(ic(n++, vc[0]));
        else v=cti[vc[0]];

        if(uc[0]=='Z') barni=u;
        if(vc[0]=='Z') barni=v;

        graph[u].push_back(ii(v, d));
        graph[v].push_back(ii(u, d));
    }

    memset(vis, 0, sizeof vis);
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0, barni));

    while(!pq.empty()){
        ii state=pq.top(); pq.pop();
        u = state.second;
        vis[u]=1;

        c = itc[u];
        if(c!='Z' && c>='A'&&c<='Z'){
            printf("%c %d\n", c, state.first);
            break;
        }


        for(i=0; i<graph[u].size(); i++){
            v = graph[u][i].first;
            d = graph[u][i].second;
            if(vis[v]) continue;
            pq.push(ii(state.first+d, v));
        }
    }

    return 0;
}






