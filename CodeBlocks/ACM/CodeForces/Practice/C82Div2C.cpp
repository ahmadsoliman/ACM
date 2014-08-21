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

int m, cnt[20], c[20], d[20], dp[1005][20];

int recur(int n, int i){
    if(i==m) return 0;
    if(dp[n][i]!=-1) return dp[n][i];

    int maxv=0;
    for(int j=0; j<=cnt[i]; j++){
        if(n<j*c[i]) break;
        maxv = max(maxv, j*d[i]+recur(n-j*c[i], i+1));
    }
    return dp[n][i]=maxv;
}

int main() {
    int n, a,b;
    scanf("%d %d %d %d", &n, &m, &c[0], &d[0]);

    cnt[0]=n/c[0];
    m++;
    for(int i=1; i<m; i++){
        scanf("%d %d %d %d", &a, &b, &c[i], &d[i]);
        cnt[i]=a/b;
    }

    memset(dp, -1, sizeof dp);
    printf("%d\n", recur(n, 0));

    return 0;

}
