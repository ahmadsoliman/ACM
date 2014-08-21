#include <stdio.h>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

int n, vis[20100], res[20100], code[20100], codeCnt;
vi graph[20100];

ii dfs(int u){
    if(vis[u]) {
        return ii(0, code[u]);
    }
    vis[u]=1;
    code[u]=codeCnt++;

    int curn=n-1;
    res[u]=n-1;
    int cnt=1, last=-1;
    for(int i=0; i<graph[u].size(); i++){
        ii cur = dfs(graph[u][i]);
        cnt  += cur.first;
        if(cur.second==-1 || cur.second==code[u]){
            res[u] += cur.first*(curn-cur.first);
            curn -= cur.first;
        }else{
            if(last==-1) last=cur.second;
            else last=min(last, cur.second);
        }
    }

    return ii(cnt, last);
}

int main(){
    freopen ("travel.in","r",stdin);
    freopen ("travel.out","w",stdout);

    int m, u,v;
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        scanf("%d %d", &u, &v);
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    memset(vis, 0, sizeof vis);
    memset(res, 0, sizeof res);
    memset(code, 0, sizeof code);
    codeCnt=0;
    dfs(0);
    for(int i=0; i<n; i++) printf("%d\n", res[i]);
    return 0;
}
