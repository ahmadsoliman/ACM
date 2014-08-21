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
typedef pair<ii, ii> iiii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int f[5010], n;
int dp[5010][2][2];

int recur(int i, int zero, int fzero){
    if(i==n){
        if(zero&&fzero) return 1;
        return 0;
    }
    if(dp[i][zero][fzero]!=-1) return dp[i][zero][fzero];

    if(f[i]) return dp[i][zero][fzero]=recur(i+1, 0, fzero);

    if(zero) return dp[i][zero][fzero]=1+recur(i+1, 0, fzero);
    return dp[i][zero][fzero]=min(recur(i+1, 1, fzero), 1+recur(i+1, 0, fzero));
}

int main(){
    while(scanf("%d", &n)){
        if(n==0) break;

        for(int i=0; i<n; i++) scanf("%d", &f[i]);

        memset(dp, -1, sizeof dp);

        printf("%d\n", ((f[0]==0)?min(recur(1,1,1), 1+recur(1,0,0)):recur(0,0,0)));
    }

    return 0;
}
