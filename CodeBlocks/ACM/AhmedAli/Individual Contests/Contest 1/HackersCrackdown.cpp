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

int n;
vi graph[100];

int dp[65537][100];

int recur(int bm, int bm2){
    if(bm2==(1<<n)-1) return 1+recur(bm, 0);
    if(bm==(1<<n)-1) return 0;

    if(bm2<100 && dp[bm][bm2]!=-1) return dp[bm][bm2];

    int maxv=0;
    for(int i=0; i<n; i++){
        if(!(bm&(1<<i)) && !(bm2&(1<<i))){
            int tmp=bm, tmp2=bm2;
            tmp |= (1<<i);
            tmp2 |= (1<<i);
            for(int j=0; j<graph[i].size(); j++) tmp2 |= (1<<graph[i][j]);
            maxv = max(maxv, recur(tmp, tmp2));
        }
    }
    if(bm2<100) dp[bm][bm2]=maxv;
    return maxv;
}

int main() {
    int k, kase=1;

    while(scanf("%d", &n)>0){
        if(n==0) break;
        memset(dp, -1, sizeof dp);

        for(int u=0, v; u<n; u++){
            graph[u].clear();
            scanf("%d", &k);
            while(k-->0) scanf("%d", &v), graph[u].push_back(v);
        }
        printf("Case %d: %d\n", kase++, recur(0,0));
    }
    return 0;

}
