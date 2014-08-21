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

vi g[101000];
vi nodes[101000];
set<int> sizes;
ll cnt[101000], v[101000];

map<ll, int> m;

void dfs(int u){
    if(g[u].size()==0) {
        cnt[u]=1;
        g[cnt[u]].pb(u);
        return;
    }
    cnt[u]=1;
    for(int i=0; i<g[u].size(); i++) dfs(g[u][i]), cnt[u]+=cnt[g[u][i]];
    g[cnt[u]].pb(u);
    sizes.insert(cnt[u]);
}

int isIso(int u, int v){

}

int main() {
//    freopen("tree.in","r",stdin);
//    freopen("tree.out", "w", stdout);

    int n, p;
    scanf("%d", &n);

    for(int i=1; i<n; i++){
        scanf("%d", &p);
        g[p-1].pb(i);
    }

    dfs(0);

    memset(v, 0, sizeof v);
    v[0]=1;
    int ind=2;
    sizes.insert(1);
    int s, u, k;

    for(set<int>::iterator it=sizes.begin(); it!=sizes.end(); it++){
        s=*it;
        for(int i=0; i<nodes[s].size(); i++){
            u = nodes[s][i];
            if(v[u]>0) continue;
            v[u]=ind++;
            for(int j=i+1; j<nodes[s].size(); j++){
                k = nodes[s][j];
                if(v[k]>0) continue;
                if(isIso(u, k)) v[k]=v[u];
            }
        }
    }


    printf("%d", v[0]);
    for(int i=1; i<n; i++) {
        printf(" %d", v[i]);
    }
    printf("\n");

    return 0;

}
