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

int n,m,vis[10005];

ii dp[10005];

ii recur(int t){
    if(vis[t]++) return dp[t];
    if(t<n&&t<m) return dp[t]=ii(-t, 0);
    ii a(-1000000000,0),b(-1000000000,0);
    if(t>=m) a = recur(t-m), a.second++;
    if(t>=n) b = recur(t-n), b.second++;
    return dp[t]=max(a,b);
}

int main() {
    int t;
    while(scanf("%d %d %d", &n, &m, &t)>0){
        memset(vis, 0, sizeof vis);
        ii res = recur(t);
        if(res.first!=0) printf("%d %d\n", res.second, -res.first);
        else printf("%d\n", res.second);
    }
    return 0;

}
