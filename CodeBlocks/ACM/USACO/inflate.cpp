/*j ID: ahmadad1
PROG: inflate
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

int p[10005], t[10005], dp[2][10005];

/*
int recur(int i, int t){
    if(i==n || t==0) return 0;

    return max(recur(i+1, t), p[i]+recur(i, t-t[i]));
}
*/

int main() {
    freopen("inflate.in", "r", stdin);
    freopen("inflate.out", "w", stdout);

    int i,j,r,l, m,n, maxp=0;

    scanf("%d %d", &m, &n);
    for(i=0; i<n; i++) scanf("%d %d", &p[i], &t[i]);

    // pre
    memset(dp, 0, sizeof dp);

    for(i=0; i<n; i++){
        for(j=0; j<=m; j++){
            dp[i&1][j]=max(((j>=t[i])?dp[i&1][j-t[i]]+p[i]:0), ((i>0)?dp[!(i&1)][j]:0));
            maxp=max(maxp, dp[i&1][j]);
        }
    }

    printf("%d\n", maxp);
    return 0;
}


