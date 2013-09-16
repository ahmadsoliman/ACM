    #include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000
#define inboard(x,y) (x>=0&&x<n&&y>=0&&y<m)

char in[200];
int dx[4]={0,0,1,-1}, dy[4]={1, -1, 0, 0};
int depth[200][200], vis[200][200], grid[200][200];
vector<int> graph[1010];

int main(){
    int t, n,m, S, F, i,j, x,y, u, v, done, d;

    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        S--;F--;

        queue<ii> q;
        for(i=0; i<n; i++) {
            scanf("%s", in);
            for(j=0; j<m; j++) {
                grid[i][j]= in[j]-'0';
                if(grid[i][j]==1) q.push(ii(i,j));
                depth[i][j]=0;
            }
        }

        ii u, v;

        done=0;
        memset(vis, 0, sizeof vis);
        while(!q.empty()){
            u = q.front(); q.pop();
            d=depth[u.first][u.second];
            for(i=0; i<4; i++){
                x = u.first+dx[i]; y = u.second+dy[i];
                if(inboard(x,y) && !vis[x][y] && grid[x][y]!=1){
                    vis[x][y]=1;
                    depth[x][y] = d+1;
                    q.push(ii(x,y));
                }
            }
        }

        for(i=0; i<n; i++){
            for(j=0; j<m; j++){
                printf("%d", depth[i][j]);
                if(j<m-1) printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}
