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
ll dp[21][1048577][2];

ll recur(int u, int bm, int dir){
    bm |= (1<<u);
    if(bm==(1<<n)-1) return 1;

    if(dp[u][bm][dir]!=-1) return dp[u][bm][dir];

    ll res=0;
    if(dir==1) {
        for(int i=u+1; i<n; i++) {
            if(!(bm&(1<<i))) res+=recur(i, bm, !dir);
        }
    } else {
        for(int i=u-1; i>=0; i--) {
            if(!(bm&(1<<i))) res+=recur(i, bm, !dir);
        }
    }

    return dp[u][bm][dir]=res;
}

double dp2[25];
int vis[25];

double recur2(int n){
    if(n<2) return 1.0;
    if(vis[n]) return dp2[n];
    vis[n]=1;
    double sum=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i+j==n-1) sum+=recur2(i)*recur2(j);
        }
    }
    return dp2[n]=1.0*sum/(2*n);
}

ll fact(int n) {
    if(n<2) return 1;
    return n*fact(n-1);
}

int main() {
    int t,k;
    scanf("%d", &t);
    while(t--){
//        memset(dp, -1, sizeof dp);
        memset(vis, 0, sizeof vis);

        scanf("%d %d", &k, &n);
        if(n==1) { printf("%d 1\n", k); continue; }
//        ll res=0;
//        int halfl=n/2;
//        for(int i=0; i<halfl; i++){
//            res += 2*(recur(i, 0, 0) + recur(i, 0, 1));
//        }
//        if(n%2==1) res += recur(halfl, 0, 0) + recur(halfl, 0, 1);
        printf("%d %lld\n", k, (ll)ceil(fact(n)*recur2(n)*2));
    }
    return 0;

}
