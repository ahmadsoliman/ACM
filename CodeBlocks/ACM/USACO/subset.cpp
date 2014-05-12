/*j ID: ahmadad1
PROG: subset
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

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n;
long long dp[50][5000];

long long recur(int i, int s){
    if(i==n+1) return s==0;
    if(dp[i][s+2500]!=-1) return dp[i][s+2500];

    return dp[i][s+2500]=recur(i+1, s+i)+recur(i+1, s-i);
}

int main() {
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);

    scanf("%d", &n);
    memset(dp, -1, sizeof dp);
    printf("%d\n", (int)(recur(1,0)/2));
    return 0;
}
