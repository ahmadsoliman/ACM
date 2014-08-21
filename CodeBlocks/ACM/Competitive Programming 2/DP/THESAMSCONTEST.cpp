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

ll dp[505][505], n;

ll recur(int i, int j){
    if(dp[i][j]!=-1) return dp[i][j];
    if(i<j){
        ll maxv=0;
        for(int k=i; k<j; k++){
            maxv=max(maxv, recur(i,k)+recur(k+1,j));
        }
        return dp[i][j]=maxv;
    }
    ll maxv=0;
    dp[i][j]=0;
    if(i<n){
        for(int k=i+1; k<=n; k++){
            maxv=max(maxv, recur(k,1)+recur(k,j));
        }
        dp[i][j]+=maxv;
    }
    maxv=0;
    if(j>0){
        for(int k=1; k<j; k++){
            maxv=max(maxv, recur(i,k)+recur(n,k));
        }
        dp[i][j]+=maxv;
    }
    return dp[i][j];
}

int main() {
    int m;
    while(scanf("%d %d", &n, &m)>0){
        memset(dp, -1, sizeof dp);
        dp[n][1]=m;
        printf("%lld\n", recur(1,n));
    }

    return 0;

}
