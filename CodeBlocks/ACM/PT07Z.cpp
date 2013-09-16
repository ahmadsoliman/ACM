#include <stdio.h>
#include <string.h>
#include <vector>


using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

vi g[10010];
int vis[10010], maxN, maxD;

void dfs(int u, int d){
    if(d>maxD){
        maxD=d;
        maxN=u;
    }
    vis[u]=1;
    int i, v;
    for(i=0; i<g[u].size(); i++){
        v=g[u][i];
        if(!vis[v]){
            dfs(v, d+1);
        }
    }
}

int main(){
    int n, i,j, u,v;

    scanf("%d", &n);

    for(i=0; i<n-1; i++){
        scanf("%d %d", &u, &v);
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    maxN=-1;
    maxD=-1;
    dfs(0, 0);
    u = maxN;

    memset(vis, 0, sizeof(int)*n);
    maxN=-1;
    maxD=-1;
    dfs(u, 0);

    printf("%d\n", maxD);

    return 0;
}
