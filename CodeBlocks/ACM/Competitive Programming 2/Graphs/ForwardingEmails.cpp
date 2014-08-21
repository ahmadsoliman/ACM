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

int graph[50005];
int vis[50005], val[50005];
int curround, loop;

int dfs(int u, int d){
    if(vis[u]==curround) {val[u]=d; loop=u; return 0;}
    if(vis[u]) return val[u];
    vis[u]=curround;

    int cur = 1+dfs(graph[u], d+1);

    if(loop>-1) val[u] = val[loop];
    else val[u] = cur;

    if(loop==u) loop=-1;

    return val[u];
}

int main(){
    int t,n,kase=1, u,v;

    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);

        for(int i=0; i<n; i++){
            scanf("%d %d", &u, &v);
            u--, v--;
            graph[u]=v;
        }
        memset(vis, 0, sizeof vis);
        memset(val, 0, sizeof val);
        curround=1;
        for(int i=0; i<n; i++) if(!vis[i]) loop=-1, dfs(i, 0), curround++;

        int ind=0;
        for(int i=0; i<n; i++){
            if(val[ind]<val[i]) ind=i;
//            printf("%d\n", val[i]);
        }
        printf("Case %d: %d\n", kase++, ind+1);
    }

    return 0;
}
