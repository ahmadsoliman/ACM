#include <stdio.h>
#include <string.h>
#include <vector>
#include <utility>
#define MOD 1000000007

using namespace std;

typedef struct{
    int n,w;
}mypair;

vector<mypair> tree[100005], tree2[100005];
int n, weights[100005];

void dfs(int node, int w){
    weights[node] = w;
    int i;
    for(i=0; i<tree[node].size(); i++)
        dfs(tree[node][i].n, (w*tree[node][i].w)%MOD);
}

int lca(int i, int j){
    if(i==j) return i;
    lca(tree2[i][0], j);
    lca(i, tree2[j][0]);
    lca(tree2[i][0], tree2[j][0]);
}

int main(){
    int a, b, w, i, j, tmp;
    long long sum=0;
    scanf("%d", &n);
    for(i=1; i<n; i++){
        scanf("%d %d %d", &a, &b ,&w);
        a--;b--;
        if(a>b){
            tmp=b;
            b=a;
            a=tmp;
        }
        mypair p;
        p.n = b;
        p.w = w;
        tree[a].push_back(p);

        p.n=a;
        tree2[b].push_back(p);
    }
    dfs(0, 1);

    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            sum = (sum+weights[j]+weights[i]-2*weights[lca(i,j)])%MOD;
        }
    }
    printf("%lld\n", sum);
    return 0;
}
