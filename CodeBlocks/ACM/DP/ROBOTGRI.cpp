#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000
#define inboard(x,y) (x>=0&&x<n&&y>=0&&y<n)

ll r;
int n, dp[1005][1005], visdp[1005][1005], vis[1005][1005], vis2[1005][1005], MOD;
char grid[1005][1005];

int recur(int i, int j){
    if(i==n-1&&j==n-1) return 1;
    if(visdp[i][j]) return dp[i][j];
    int a=0, b=0;
    if(i<n-1 && grid[i+1][j]=='.') a=recur(i+1, j);
    if(j<n-1 && grid[i][j+1]=='.') b=recur(i, j+1);
    visdp[i][j]=1;
    r = (long long)a+b;
    if(r>MOD) r-=MOD;
    return dp[i][j]=r;
}

int dx[4]={1,0,0,-1}, dy[4]={0,1,-1,0};

int main(){
    MOD = (1<<31)-1;
    int i,j, res, doable, x, y;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%s", grid[i]);

    queue<ii> q1;
    q1.push(ii(0,0));
    ii u1,v1;
    doable=0;
    while(!q1.empty()){
        u1 = q1.front(); q1.pop();
        vis2[u1.first][u1.second]=1;
        if(u1.first==n-1 && u1.second==n-1) { doable=1; break; }
        for(i=0; i<2; i++){
            x=u1.first+dx[i], y=u1.second+dy[i];
            if(inboard(x, y) && grid[x][y]=='.' && !vis2[x][y])
                q1.push(ii(x,y));
        }
    }

    if(doable) { res = recur(0,0); printf("%d\n", res); }
    else{
        queue<ii> q;
        q.push(ii(0,0));
        ii u,v;
        doable=0;
        while(!q.empty()){
            u = q.front(); q.pop();
            vis[u.first][u.second]=1;
            if(u.first==n-1 && u.second==n-1) { doable=1; break; }
            for(i=0; i<4; i++){
                x=u.first+dx[i], y=u.second+dy[i];
                if(inboard(x, y) && grid[x][y]=='.' && !vis[x][y])
                    q.push(ii(x,y));
            }
        }
        if(doable) printf("THE GAME IS A LIE\n");
        else printf("INCONCEIVABLE\n");
    }
    return 0;
}

/*

5
.#...
.#...
...#.
...#.
.##..

*/
