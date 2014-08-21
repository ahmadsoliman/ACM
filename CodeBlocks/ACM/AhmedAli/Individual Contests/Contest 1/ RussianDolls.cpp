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

int out[1010], in[1010], cost[1010], vis[1010];
vi graph[1010];
int dp[1010];

typedef struct doll{
    int out, ins, cost, ind;
    doll(){}
    doll(int o, int i, int c, int in){
        out=o;
        ins=i;
        cost=c;
        ind=in;
    }
};

bool operator <(const doll& x, const doll& y) {
    return x.ins < y.ins;
}

vector<doll> dolls;

int main() {
    int n;

    while(scanf("%d", &n)>0){
        for(int i=0; i<n; i++){
            scanf("%d %d %d", &out[i], &in[i], &cost[i]);
            doll d(out[i], in[i], cost[i], i);
            dolls.push_back(d);
        }

        memset(vis, 0, sizeof vis);
        for(int i=0; i<n; i++) if(!vis[i]) dfs(i);

        int res=0;
        printf("%d\n", res);
    }
    return 0;

}
