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

typedef unsigned long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

ll dp[100][100];

ll trib(int n, unsigned int back){
    ll sum=0;
    if(n<=0) return 1;
    if(n==1) return 1;
    if(dp[n][back]!=-1) return dp[n][back];
    for(int i=1;i<=back;i++) sum+=trib(n-i,back);
    return dp[n][back]=sum+1;
}

int main() {
    int n,k, kase=1;
    while(scanf("%d %d", &n, &k)>0){
        if(n>61 || k>60) break;
        memset(dp, -1, sizeof dp);
        printf("Case %d: %llu\n", kase++, trib(n,k));
    }

    return 0;

}
