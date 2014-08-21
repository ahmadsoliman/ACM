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

int n, p[100005], dp[100005][3];
vector<int> tree[100005];

int recur(int node, int taken){
    if(tree[node].size()==0){
        return 0;
    }
    if(dp[node][taken]!=-1) return dp[node][taken];
    int val=0;
    for(int i=0; i<tree[node].size(); i++){
        if(taken) val += min(1+recur(tree[node][i], 1), recur(tree[node][i], 0));
        else val += 1+recur(tree[node][i], 1);
    }
    return dp[node][taken]=val;
}

int main(){
    int u, v;
    memset(p, 0, sizeof p);
    scanf("%d", &n);
    for(int i=0; i<n-1; i++){
        scanf("%d %d", &u, &v);
        if(v<u) swap(u, v);
        tree[u-1].push_back(v-1);
        p[v-1]=1;
    }
    memset(dp, -1, sizeof dp);
    for(int i=0; i<n; i++){
        if(!p[i]){
            //printf("%d %d\n", recur(i, 0), 1+recur(i, 1));
            printf("%d\n", min(recur(i, 0), 1+recur(i, 1)));
            break;
        }
    }
    return 0;
}
