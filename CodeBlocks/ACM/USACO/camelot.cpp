/*j ID: ahmadad1
PROG: camelot
LANG: C++
*/
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
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;

int n,m, knc, kx, ky, knx[1005], kny[1005];
char in[10];

int dist[31][31][31][31], vis[1000];

int dx[8]={1,-1,1,-1,2,-2,2,-2},
    dy[8]={2,-2,-2,2,1,-1,-1,1};
int dxk[8]={0,0,1,-1, 1,1,-1,-1},
    dyk[8]={1,-1,0,0, 1,-1,1,-1};
int dxk2[16]={0,0,1,1,-1,-1,    2,2,2,2,2,-2,-2,-2,-2,-2},
    dyk2[16]={2,-2,2,-2,2,-2,    0,1,-1,2,-2,0,1,-1,2,-2};

#define inboard(x,y) (x>=0 && x<n && y>=0 && y<m)

void preBFS(){
    int i,j,k, u,v, x,y;
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            memset(vis, 0, sizeof vis);
            queue<ii> q;
            u=i*m+j;
            q.push(ii(0, u));

            while(!q.empty()){
                ii state=q.front(); q.pop();

                vis[state.second]=1;
                x = state.second/m; y = state.second%m;
                dist[i][j][x][y]=state.first;

                for(k=0; k<8; k++){
                    if(inboard(x+dx[k], y+dy[k])){
                        v = m*(x+dx[k])+y+dy[k];
                        if(!vis[v]) {
                            vis[v]=1;
                            q.push(ii(state.first+1, v));
                        }
                    }
                }
            }
        }
    }
}

int main() {
    freopen("camelot.in", "r", stdin);
    freopen("camelot.out", "w", stdout);

    int i,j,k,r, u,v, x,y, knmoves, minm;

    scanf("%d %d", &n, &m);
    scanf("%s %d", in, &kx), ky=in[0]-'A', kx--;

    knc=0;
    while(scanf("%s %d", in, &knx[knc])>0) kny[knc]=in[0]-'A', knx[knc]--, knc++;

    for(i=0; i<n; i++) for(j=0; j<m; j++)
        for(k=0; k<n; k++) for(r=0; r<m; r++) dist[i][j][k][r]=100000000;
    preBFS();

    minm=100000000;

    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            knmoves=0;
            for(k=0; k<knc; k++) knmoves+=dist[knx[k]][kny[k]][i][j];
            minm=min(minm, knmoves+dist[kx][ky][i][j]);

            for(k=0; k<knc; k++){
                knmoves-=dist[knx[k]][kny[k]][i][j];
                minm=min(minm, knmoves+dist[knx[k]][kny[k]][kx][ky]+dist[kx][ky][i][j]);

                for(r=0; r<8; r++){
                    x=kx+dxk[r], y=ky+dyk[r];
                    if(!inboard(x,y)) continue;
                    minm=min(minm, knmoves+dist[knx[k]][kny[k]][x][y]+dist[x][y][i][j]+1);
                }

                for(r=0; r<16; r++){
                    x=kx+dxk2[r], y=ky+dyk2[r];
                    if(!inboard(x,y)) continue;
                    minm=min(minm, knmoves+dist[knx[k]][kny[k]][x][y]+dist[x][y][i][j]+2);
                }

                knmoves+=dist[knx[k]][kny[k]][i][j];
            }
        }
    }
    printf("%d\n", minm);

    return 0;
}





