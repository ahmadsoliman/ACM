/*j ID: ahmadad1
PROG: money
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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef unsigned long long ll;

int v, val[30];
ll dp[26][10005];

ll recur(int i, int n){
    if(n==0) return 1;
    if(i==v) return 0;

    if(dp[i][n]!=-1) return dp[i][n];

    ll a=recur(i+1, n), b=0;
    if(val[i]<=n) b=recur(i, n-val[i]);

    return dp[i][n]=a+b;
}

int main() {
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);

    int i,j,k;

    int n;

    scanf("%d %d", &v, &n);
    for(i=0; i<v; i++) scanf("%d", &val[i]);

    memset(dp, -1, sizeof dp);
    printf("%llu\n", recur(0, n));

    return 0;
}
