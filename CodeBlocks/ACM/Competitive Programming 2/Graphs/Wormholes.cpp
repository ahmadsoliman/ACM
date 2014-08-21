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

//vector<ii> g[1005];
vector<iii> es;

int main() {
    int t,n,m,u,v,w;
    scanf("%d", &t);

    while(t--){
        scanf("%d %d", &n, &m);

        es.clear();
        //for(int i=0; i<n; i++) g[i].clear();

        for(int i=0; i<m; i++){
            scanf("%d %d %d", &u,&v,&w);
            //g[u].pb(ii(v,w));
            es.pb(iii(u,ii(v,w)));
        }
        int s=0, t=n-1;

        vector<int> dists(n, 1000000000);
        dists[s]=0;

        for(int i=0; i<n-1; i++){
            bool nochange=true;
            for(int j=0; j<es.size(); j++){
                u = es[j].first, v = es[j].second.first, w = es[j].second.second;
                if(dists[v]>dists[u]+w) nochange = false, dists[v] = dists[u]+w;
            }
            if(nochange) break;
        }
        // check for neg cycles
        bool negCycle=false;
        for(int j=0; j<es.size(); j++){
            u = es[j].first, v = es[j].second.first, w = es[j].second.second;
            if(dists[v]>dists[u]+w) { negCycle=true; break; }
        }

        if(negCycle) printf("possible\n");
        else printf("not possible\n");
    }
    return 0;

}
