#include <stdio.h>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <algorithm>

using namespace std;

int n, vis[10005];
vector<int> tree[10005];
int p[10005];

void recur(int node){
    if(vis[node]) return;
    vis[node]=1;
    if(tree[node].size()==0) {
        printf("%d", node+1);
        return;
    }
    if(tree[node].size()==1) {
        printf("%d ", node+1);
        recur(tree[node][0]);
        return;
    }
    printf("%d ", node+1);
    recur(tree[node][0]);
    printf("\n");
    for(int i=1; i<tree[node].size(); i++){
        recur(tree[node][i]);
    }
}

int main(){
    int t, u, v;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        memset(p, 0, sizeof p);
        for(int i=0; i<n-1; i++){
            scanf("%d %d", &u, &v);
            u--, v--;
            if(p[v]) swap(u, v);
            tree[u].push_back(v);

            p[v]=1;
        }
        memset(vis, 0, sizeof vis);
        for(int i=0; i<n; i++) {
            if(!p[i]) {
                recur(i);
                break;
            }
        }
    }
    return 0;
}
