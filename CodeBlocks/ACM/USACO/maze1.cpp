/*j ID: ahmadad1
PROG: maze1
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
typedef pair<char, int> ci;
typedef pair<int, char> ic;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

#define inboard(x,y) (x>=0 && x<h && y>=0 && y<w)

char grid[205][85], in[100];
int dist[17000];
int vis[17000];
int dx[4]={0,0,1,-1}, dy[4]={1,-1,0,0};

queue<ii> q;

int main() {
    freopen("maze1.in", "r", stdin);
    freopen("maze1.out", "w", stdout);

    int i,j,k, h,w, exit1=-1, exit2=-1, x,y, np;

    sscanf(gets(in), "%d %d", &w, &h);

    h = 2*h+1;
    w = 2*w+1;

    for(i=0; i<h; i++){
        gets(grid[i]);
    }

    for(i=0, j=0; i<h; i++) if(grid[i][j]==' ') { if(exit1==-1) exit1=w*i+j; else if(exit2==-1) exit2=w*i+j; }
    if(exit2==-1) for(i=0, j=w-1; i<h; i++) if(grid[i][j]==' ') { if(exit1==-1) exit1=w*i+j; else if(exit2==-1) exit2=w*i+j; }
    if(exit2==-1) for(i=0, j=0; j<w; j++) if(grid[i][j]==' ') { if(exit1==-1) exit1=w*i+j; else if(exit2==-1) exit2=w*i+j; }
    if(exit2==-1) for(i=h-1, j=0; j<w; j++) if(grid[i][j]==' ') { if(exit1==-1) exit1=w*i+j; else if(exit2==-1) exit2=w*i+j; }

    memset(dist, 0, sizeof dist);
    memset(vis, 0, sizeof vis);

    q.push(ii(0, exit1));
    while(!q.empty()){
        ii state=q.front(); q.pop();
        if(vis[state.second]) continue;
        vis[state.second]=1;
        dist[state.second]=state.first;

        x=state.second/w, y=state.second%w;

        for(i=0; i<4; i++){
            if(inboard(x+dx[i], y+dy[i]) && grid[x+dx[i]][y+dy[i]]==' '){
                np = (x+dx[i])*w+(y+dy[i]);
                if(vis[np]) { continue; }
                q.push(ii(state.first+1, np));
            }
        }
    }

    memset(vis, 0, sizeof vis);
    q.push(ii(0, exit2));
    while(!q.empty()){
        ii state=q.front(); q.pop();

        if(vis[state.second]) continue;
        vis[state.second]=true;
        dist[state.second]=min((int)dist[state.second], state.first);

        x=state.second/w, y=state.second%w;

        for(i=0; i<4; i++){
            if(inboard(x+dx[i], y+dy[i]) && grid[x+dx[i]][y+dy[i]]==' '){
                np = (x+dx[i])*w+(y+dy[i]);
                if(vis[np]) continue;
                q.push(ii(state.first+1, np));
            }
        }
    }

    int res=0;
    for(i=1; i<h; i+=2){
        for(j=1; j<w; j+=2){
            res = max(res, (int)dist[i*w+j]);
        }
    }

    printf("%d\n", 1+res/2);

    return 0;
}
/*
9 1
+-+-+-+-+ +-+-+-+-+
|                 |
+-+-+-+-+ +-+-+-+-+
*/
