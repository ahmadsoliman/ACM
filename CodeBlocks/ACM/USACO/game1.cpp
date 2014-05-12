/*j ID: ahmadad1
PROG: game1
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

int nums[105];
ii dp[105][105][2];

ii recur(int i, int j, int turn){
    if(i>j) return ii(0,0);

    if(dp[i][j][turn].first!=-1) return dp[i][j][turn];

    ii a=recur(i+1, j, !turn), b=recur(i, j-1, !turn);

    if(!turn) {
        a.first+=nums[i];
        b.first+=nums[j];
        if(a.first>b.first) return dp[i][j][turn]=a;
        return dp[i][j][turn]=b;
    }else{
        a.second+=nums[i];
        b.second+=nums[j];
        if(a.second>b.second) return dp[i][j][turn]=a;
        return dp[i][j][turn]=b;
    }
}

int main() {
    freopen("game1.in", "r", stdin);
    freopen("game1.out", "w", stdout);

    int i,j,k, n;

    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &nums[i]);

    for(i=0; i<n; i++) for(j=0; j<n; j++) dp[i][j][0]=dp[i][j][1]=ii(-1,-1);
    ii res=recur(0, n-1, 0);
    printf("%d %d\n", res.first, res.second);
    return 0;
}





