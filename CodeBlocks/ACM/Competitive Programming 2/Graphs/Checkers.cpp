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

#define inboard(x,y) (x>=0&&y>=0&&x<n&&y<n)

int n,brd[105][105], dp[105][105];

int recur(int x, int y){
    if(x==0) return 1;
    if(dp[x][y]!=-1) return dp[x][y];

    dp[x][y]=0;
    if(inboard(x-1,y-1) && !brd[x-1][y-1]) dp[x][y]+=recur(x-1,y-1);
    else if(inboard(x-1,y-1) && brd[x-1][y-1] && inboard(x-2,y-2)  && !brd[x-2][y-2]) dp[x][y]+=recur(x-2,y-2);

    if(inboard(x-1,y+1) && !brd[x-1][y+1]) dp[x][y]+=recur(x-1,y+1);
    else if(inboard(x-1,y+1) && brd[x-1][y+1] && inboard(x-2,y+2)  && !brd[x-2][y+2]) dp[x][y]+=recur(x-2,y+2);
    dp[x][y]%=1000007;

    return dp[x][y];
}

char in[1000];

int main(){
    int t, startx, starty, kase=1;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        memset(brd, 0, sizeof brd);
        for(int i=0; i<n; i++){
            scanf("%s", in);
            for(int j=0; j<n; j++) {
                if(in[j]=='W') startx=i, starty=j;
                else if(in[j]=='B') brd[i][j]=1;
            }
        }
        memset(dp, -1, sizeof dp);
        printf("Case %d: %d\n", kase++, recur(startx, starty));
    }
    return 0;
}
