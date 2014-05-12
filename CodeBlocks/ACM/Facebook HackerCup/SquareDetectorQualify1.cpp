#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

char grid[100][100];

int main(){
    freopen("sq.in", "r", stdin);
    freopen("sq.out", "w", stdout);

    int t, n, i,j,k, startx, starty, endx, endy, w, kase=1, f;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        startx=-1;
        for(i=0; i<n; i++) {
            scanf("%s", grid[i]);
            if(startx==-1) for(j=0; j<n; j++) if(grid[i][j]=='#') { startx=i, starty=j; break; }
        }
        if(startx==-1) { printf("Case #%d: NO\n", kase++); continue; }

        endx=-1;
        for(i=n-1; i>=0; i--) {
            for(j=n-1; j>=0; j--) if(grid[i][j]=='#') { endx=i, endy=j; break;}
            if(endx!=-1) break;
        }


        f=0;
        if(endy-starty!=endx-startx) f=1;
        if(!f) for(i=0; i<startx; i++) for(j=0; j<n; j++) if(grid[i][j]=='#') { f=1; break;}
        if(!f) for(i=endx+1; i<n; i++) for(j=0; j<n; j++) if(grid[i][j]=='#') { f=1; break;}
        if(!f) for(i=0; i<n; i++) for(j=0; j<starty; j++) if(grid[i][j]=='#') { f=1; break;}
        if(!f) for(i=0; i<n; i++) for(j=endy+1; j<n; j++) if(grid[i][j]=='#') { f=1; break;}

        if(!f) for(i=startx; i<=endx; i++) for(j=starty; j<=endy; j++) if(grid[i][j]=='.') { f=1; break;}

        if(f) printf("Case #%d: NO\n", kase++);
        else printf("Case #%d: YES\n", kase++);
    }
    return 0;
}
