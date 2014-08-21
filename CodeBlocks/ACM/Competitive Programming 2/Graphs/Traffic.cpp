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
typedef pair<int, ll> ii;
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
int bus[1000];

int main() {
    int n,m,u,v,q,kase=1;
    ll w;

    while(scanf("%d", &n)==1){
        es.clear();
        for(int i=0; i<n; i++) scanf("%d", &bus[i]);

        scanf("%d", &m);
        for(int i=0; i<m; i++){
            scanf("%d %d", &u,&v);
            u--,v--;
            w = powl((ll)bus[v]-bus[u], 3);
//            g[u].pb(ii(v,w));
            es.pb(iii(u,ii(v,w)));
        }
        int s=0;

        vector<ll> dists(n, 4000000000000000000ll);
        dists[s]=0;

        for(int i=0; i<n-1; i++){
            bool nochange=true;
            for(int j=0; j<es.size(); j++){
                u = es[j].first, v = es[j].second.first, w = es[j].second.second;
                if(dists[v]>dists[u]+w) nochange = false, dists[v] = dists[u]+w;
            }
            if(nochange) break;
        }
        printf("Set #%d\n", kase++);
        scanf("%d", &q);
        while(q--){
            scanf("%d", &v);
            v--;
            if(dists[v]<3 || dists[v]>=4000000000000000000ll) printf("?\n");
            else printf("%lld\n", dists[v]);
        }

    }
    return 0;

}
