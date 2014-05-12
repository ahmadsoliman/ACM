#include <stdio.h>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <algorithm>


#define INF 1000000000

using namespace std;

int n,m, origk;
long long dp[45][45][45][2];

long long recur(int i, int j, int k, int lastZero){
    if(j==m) return recur(i+1, 0, k, 0);
    if(i==n) return 1;

    if(dp[i][j][k][lastZero]!=-1) return dp[i][j][k][lastZero];

    long long l=recur(i, j+1, k, 1) , r=0;
    if(lastZero && k) r=recur(i, j+1, k-1, 0);
    else if(!lastZero) r=recur(i, j+1, k, 0);

    return dp[i][j][k][lastZero]= l + r;
}

int main(){
//    freopen("lunocode.in","r",stdin);
    int k;
    scanf("%d %d %d", &n, &m, &origk);

    memset(dp, -1, sizeof dp);
    printf("%lld\n", recur(0, 0, origk, 0));

    return 0;
}
