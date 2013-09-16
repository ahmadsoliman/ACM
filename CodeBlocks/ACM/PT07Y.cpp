#include <stdio.h>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

vi g[10010];
int vis[10010], p[10010], tree, c;

void dfs(int u){
    vis[u]=1;
    c++;
    int i, v;
    for(i=0; i<g[u].size(); i++){
        v=g[u][i];
        if(vis[v]){
            if(v!=p[u]){
                tree=0;
                return;
            }
        }else {
            p[v]=u;
            dfs(v);
        }
    }
}

int main(){
    int n, m, i,j, u,v, allvis;

    scanf("%d %d", &n, &m);

    if(m!=n-1){
        printf("NO\n");
        return 0;
    }

    for(i=0; i<m; i++){
        scanf("%d %d", &u, &v);
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    tree=1;
    c=0;
    dfs(0);

    if(tree && c==n)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
