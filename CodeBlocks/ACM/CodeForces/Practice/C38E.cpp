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

int dp[3010][3010];
vii m;

int recur(int i, int last){
    if(i==m.size()) return 0;
    if(dp[i][last]!=-1) return dp[i][last];
    return dp[i][last]=min(m[i].first-m[last].first+recur(i+1, last), m[i].second+recur(i+1, i));
}

int main() {
    int n,x,c;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d %d", &x, &c);
        m.pb(ii(x,c));
    }
    sort(m.begin(), m.end());

    memset(dp, -1, sizeof dp);
    printf("%d\n", m[0].second+recur(1,0));

    return 0;

}
