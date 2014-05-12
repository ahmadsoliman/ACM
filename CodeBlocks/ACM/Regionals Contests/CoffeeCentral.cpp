#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <algorithm>

using namespace std;

int x[1000000], y[1000000];

int grid[1005][1005], dp[1005][1005];

int main(){
    int kase=1, dx,dy, n,q, m;
    while(scanf("%d %d %d %d", &dx, &dy, &n, &q)){
        if(!dx && !dy && !n && !q) break;

        memset(grid, 0, sizeof grid);
        for(int i=0; i<n; i++){
            scanf("%d %d", &x[i], &y[i]);
            grid[x[i]-1][y[i]-1]=1;
        }
        for(int i=0; i<dx; i++){
            for(int j=0; j<dy; j++){
                int north=0, west=0, northwest=0;
                if(i) north=dp[i-1][j];
                if(j) west=dp[i][j-1];
                if(i&&j) northwest=dp[i-1][j-1];
                dp[i][j]=north+west-northwest+grid[i][j];
            }
        }
        printf("Case %d:\n", kase++);
        while(q--){
            scanf("%d", &m);
            m--;

            int maxv=0, maxX,maxY, v, ax,ay,bx,by, north, west, northwest;
            for(int i=0; i<dx; i++){
                for(int j=0; j<dy; j++){
                    ax = max(0, i-m);
                    ay = max(0, j-m);
                    bx = min(dx-1, i+m);
                    by = min(dy-1, j+m);

                    north=0, west=0, northwest=0;
                    if(ax) north=dp[ax-1][j];
                    if(ay) west=dp[i][ay-1];
                    if(ax&&ay) northwest=dp[ax-1][ay-1];
                    v = dp[bx][by]-north-west+northwest;

                    if(v>maxv) maxv=v, maxX=i, maxY=j;
                    else if(v==maxv){
                        if(j<maxY) maxX=i, maxY=j;
                        else if(j==maxY) {
                            if(i<maxX) maxX=i;
                        }
                    }
                }
            }
            printf("%d (%d,%d)\n", maxv, maxX, maxY);
        }
    }
    return 0;
}
