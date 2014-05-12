/*j ID: ahmadad1
PROG: rockers
LANG: C++
*/
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

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;

int n, nums[25], tott, dp[26][21][21];

int recur(int i, int m, int t){
    if(i==n) return 0;

    if(dp[i][m][t]!=-1) return dp[i][m][t];

    int a=recur(i+1, m, t), b=0;
    if(nums[i]<=t) b=1+recur(i+1, m, t-nums[i]);
    else if(m>0) b=recur(i, m-1, tott);

    return dp[i][m][t]=max(a,b);
}

int main() {
    freopen("rockers.in", "r", stdin);
    freopen("rockers.out", "w", stdout);

    int i,j,k, t,m;

    scanf("%d %d %d", &n, &tott, &m);
    for(i=0; i<n; i++) scanf("%d", &nums[i]);

    memset(dp, -1, sizeof dp);
    printf("%d\n", recur(0, m-1, tott));

    return 0;
}





