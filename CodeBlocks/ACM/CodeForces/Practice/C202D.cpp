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

int g[3005][3005];
char in[3005];

int X,Y,n,m, dp[3005][3005];

int mod(ll x){
    if(x<0) return x+1000000007;
    return x%1000000007;
}

int recur(int x, int y){
    if(x==X && y==Y) return 1;
    if(dp[x][y]!=-1) return dp[x][y];
    int a=0,b=0;
    if(x+1<n&&!g[x+1][y]) a=recur(x+1,y);
    if(y+1<m&&!g[x][y+1]) b=recur(x,y+1);
    return dp[x][y]=(a+b)%1000000007;
}

int main() {
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++){
        scanf("%s", in);
        for(int j=0; j<m; j++){
            if(in[j]=='#') g[i][j]=1;
        }
    }

    int x,y,z,w;
    x=y=z=w=0;

    memset(dp, -1, sizeof dp);
    X = n-2, Y = m-1;
    if(!g[0][1] && !g[n-2][m-1]) x = recur(0,1);

    memset(dp, -1, sizeof dp);
    X = n-1, Y = m-2;
    if(!g[0][1] && !g[n-1][m-2]) y = recur(0,1);

    memset(dp, -1, sizeof dp);
    X = n-2, Y = m-1;
    if(!g[1][0] && !g[n-2][m-1]) z = recur(1,0);

    memset(dp, -1, sizeof dp);
    X = n-1, Y = m-2;
    if(!g[1][0] && !g[n-1][m-2]) w = recur(1,0);

    printf("%d\n", mod(((ll)x*w)%1000000007-((ll)y*z)%1000000007));

    return 0;

}
