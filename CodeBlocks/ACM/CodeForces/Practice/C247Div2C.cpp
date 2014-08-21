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

#define MOD 1000000007
int k,d, dp[105][5];

int recur(int n, int f){
    if(n==0){
        if(f) return 1;
        return 0;
    }
    if(dp[n][f]!=-1) return dp[n][f];
    int sum=0;
    for(int i=1; i<=min(k,n); i++){
        sum = (sum+recur(n-i, f||(i>=d)))%MOD;
    }
    return dp[n][f]=sum;
}

int main() {
    int n;
    scanf("%d %d %d", &n, &k, &d);
    memset(dp, -1, sizeof dp);
    printf("%d\n", recur(n, 0));
    return 0;

}
