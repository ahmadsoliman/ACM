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

int c[50100], w[100100], o1[50100], o2[50100], done[50100];
vi graph[200100];
int dfs_num[200100], dfs_low[200100], vis[200100], dfsC, numSCC, scc[200100];
vi S;

void tarjanSCC(int u){
    dfs_num[u]=dfs_low[u]=dfsC++;
    S.push_back(u);
    vis[u]=1;
    for(int i=0; i<graph[u].size(); i++){
        if(dfs_num[graph[u][i]]==-1) tarjanSCC(graph[u][i]);
        if(vis[graph[u][i]]) dfs_low[u] = min(dfs_low[u], dfs_low[graph[u][i]]);
    }
    if(dfs_low[u]==dfs_num[u]){
        scc[u]=numSCC;
        while(1){
            int v = S.back(); S.pop_back();
            vis[v]=0;
            scc[v]=numSCC;
            if(u==v) break;
        }
        numSCC++;
    }
}

int main(){
    freopen("chip.in","r",stdin);
    freopen("chip.out", "w", stdout);

    int n;
    scanf("%d", &n);
    memset(o1, -1, sizeof o1);
    for(int i=0; i<n; i++) scanf("%d", &c[i]);
    for(int i=0; i<2*n; i++) {
        scanf("%d", &w[i]);
        w[i]--;
        if(o1[w[i]]==-1) o1[w[i]]=i;
        else o2[w[i]]=i;
    }

    for(int i=0; i<n; i++){
        graph[2*o1[i]+1].push_back(2*o2[i]);
        graph[2*o2[i]+1].push_back(2*o1[i]);
    }

    for(int i=1; i<2*n; i++){
        if(c[w[i-1]]==c[w[i]]){
            graph[2*(i-1)].push_back(2*i+1);
            graph[2*i].push_back(2*(i-1)+1);
        }
    }
    if(c[w[0]]==c[w[2*n-1]]){
        graph[0].push_back(2*(2*n-1)+1);
        graph[2*(2*n-1)].push_back(1);
    }

    dfsC=numSCC=0;
    memset(vis, 0, sizeof vis);
    memset(dfs_low, 0, sizeof dfs_low);
    memset(dfs_num, -1, sizeof dfs_num);
    for(int i=0; i<4*n; i++) if(dfs_num[i]==-1) tarjanSCC(i);

    bool f=true;
    for(int i=1; i<4*n && f; i+=2) if(scc[i-1]==scc[i]) f=false;

    if(!f){
        printf("NO\n");
        return 0;
    }

    bool entered=false;
    memset(done, 0, sizeof done);
    printf("YES\n");
    for(int i=0; i<n; i++) {
        if(done[i]) continue;
        done[i]=1;
        if(scc[2*o1[i]]<scc[2*o1[i]+1]) {
            if(entered) printf(" ");
            else entered=true;
            printf("%d", o1[i]+1);
        }else{
            if(entered) printf(" ");
            else entered=true;
            printf("%d", o2[i]+1);
        }
    }

    return 0;
}





