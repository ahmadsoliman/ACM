/*j ID: ahmadad1
PROG: castle
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

using namespace std;

#define inBoard(x,y) (x>=0 && x<2*n && y>=0 && y<2*m)

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

// rows, cols
int n,m, dirVal[4]={8,4,2,1}, board[150][150], vis[150][150];
int dx[4]={0,0,2,-2}, dy[4]={2,-2,0,0};

int walls[4];
void build(int i, int j, int w){
    for(int k=0; k<4; k++) {
        walls[k]=0;
        if(w>=dirVal[k]) w-=dirVal[k], walls[k]=1;
    }
    // cell pos = (2*i+1, 2*j+1)
    i = 2*i+1, j=2*j+1;

    // south, east, north, west
    if(walls[0]) board[i+1][j]=1;
    if(walls[1]) board[i][j+1]=1;
    if(walls[2]) board[i-1][j]=1;
    if(walls[3]) board[i][j-1]=1;
}

int roomNum[150][150];
vvii rooms;

void dfs(int i, int j){
    if(vis[i][j]) return;
    vis[i][j]=1;
    rooms.back().push_back(ii(i,j));
    for(int k=0; k<4; k++){
        if(inBoard(i+dx[k], j+dy[k]) && board[i+dx[k]/2][j+dy[k]/2]==0) dfs(i+dx[k], j+dy[k]);
    }
}

int dfs2(int i, int j){
    if(vis[i][j]) return 0;
    vis[i][j]=1;
    int sum=1;
    for(int k=0; k<4; k++){
        if(inBoard(i+dx[k], j+dy[k]) && board[i+dx[k]/2][j+dy[k]/2]==0) sum+=dfs2(i+dx[k], j+dy[k]);
    }
    return sum;
}

int main() {
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);

    int i,j,k, maxr, maxnr, maxx, maxy, cur, f;

    scanf("%d %d", &m, &n);
    memset(board, 0, sizeof board);
    for(i=0; i<=2*m; i++) board[0][i]=board[2*n][i]=1;
    for(i=0; i<=2*n; i++) board[i][0]=board[i][2*m]=1;

    //for(i=1; i<2*n; i+=2) for(j=2; j<=2*m; j+=2) board[i][j-1]=1;
    //for(i=2; i<=2*n; i+=2) for(j=1; j<2*m; j+=2) board[i-1][j]=1;

    for(i=0; i<n; i++) for(j=0; j<m; j++) scanf("%d", &k), build(i,j, k);

    /*for(i=0; i<=2*n; i++) {
        for(j=0; j<=2*m; j++) printf("%c", (board[i][j])?'#':'.');
        printf("\n");
    }*/

    maxr=0;
    memset(vis, 0, sizeof vis);
    for(i=1; i<2*n; i+=2) for(j=1; j<2*m; j+=2)
        if(!vis[i][j]) rooms.push_back(vii()), dfs(i,j), maxr=max(maxr, (int)rooms.back().size());

    for(i=0; i<rooms.size(); i++){
        for(j=0; j<rooms[i].size(); j++){
            roomNum[rooms[i][j].first][rooms[i][j].second]=i;
        }
    }

    printf("%d\n", rooms.size());
    printf("%d\n", maxr);

    maxnr=0;

    f=0;
    // horizontal walls
    for(i=1; i<2*n; i+=2) {
        for(j=2; j<2*m; j+=2) {
            if(board[i][j]==0) continue;
            if(roomNum[i][j-1]==roomNum[i][j+1]) continue;
            board[i][j]=0;
            memset(vis, 0, sizeof vis);
            cur=dfs2(i, j-1);
            if(cur>maxnr){
                maxnr=cur;
                maxx=i, maxy=j-1;
            }else if(cur==maxnr){
                if(j-1<maxy || (j-1==maxy&&i>maxx)) maxx=i, maxy=j-1;
            }
            board[i][j]=1;
        }
    }

    //vertical walls
    for(i=2; i<2*n; i+=2) {
        for(j=1; j<2*m; j+=2) {
            if(board[i][j]==0) continue;
            if(roomNum[i-1][j]==roomNum[i+1][j]) continue;
            board[i][j]=0;
            memset(vis, 0, sizeof vis);
            cur=dfs2(i+1, j);
            if(cur>maxnr){
                f=1;
                maxnr=cur;
                maxx=i+1, maxy=j;
            }else if(cur==maxnr){
                if(j<maxy || (j==maxy&&i+1>=maxx)) f=1, maxx=i+1, maxy=j;
            }
            board[i][j]=1;
        }
    }

    printf("%d\n", maxnr);
    printf("%d %d %c\n", maxx/2+1, maxy/2+1, ((f)?'N':'E'));

    return 0;
}
/*
#######
# # # #
#######
# # # #
#######

-1-2-3-4-5-
########### -
##.#.###.## 1
#.........# -
##.#.###.## 2
#..#......# -
########.## 3
##...#.#..# -
##.#.#.#### 4
#.........# -
##.#.#.#### 5
########### -

-1-2-3-4-5-
########### -
#.....#...# 1
#.........# -
#.....#...# 2
#..#......# -
#.#.#.#...# 3
##...#.#..# -
#.......#.# 4
#.........# -
#.......#.# 5
########### -

*/
