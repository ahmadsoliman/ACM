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

int k1, k2, dp[105][105][11][2];
#define MOD 100000000

int recur(int n1, int n2, int cnt, int type){
    if(n1==0&&n2==0) return 1;
    if(dp[n1][n2][cnt][type]!=-1) return dp[n1][n2][cnt][type];

    int sum=0;
    if(n1>0 && !(type==0 && cnt==k1)){
        sum+=recur(n1-1, n2, (type==0)?cnt+1:1, 0);
        sum%=MOD;
    }
    if(n2>0 && !(type==1 && cnt==k2)){
        sum+=recur(n1, n2-1, (type==1)?cnt+1:1, 1);
    }
    return dp[n1][n2][cnt][type]=sum%MOD;
}

int main() {
    int n1, n2;
    scanf("%d %d %d %d", &n1, &n2, &k1, &k2);
    memset(dp, -1, sizeof dp);
    printf("%d\n", recur(n1, n2, 0, 0));

    return 0;

}
