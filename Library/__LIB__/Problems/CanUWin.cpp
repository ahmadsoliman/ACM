// kill all pawns using one knight, bfs knight shortest moves 

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int , ii> Pair;

#define INF 1000000000

#define X first
#define Y second.first
#define cst second.second
#define mp(a,b,c) make_pair(a, make_pair(b,c))

#define inboard(nx, ny) (nx>=0 && nx<8 && ny>=0 && ny<8)

int n, sp[8][8][8][8], dp[10][300];
char grid[8][8];

int dx[8]={2,2,1,1,-2,-2,-1,-1}, dy[8]={1,-1,2,-2,1,-1,2,-2};

void bfs(int x, int y){
    queue<Pair> q;
    q.push(mp(x,y,0));
    while(!q.empty()){
        Pair p = q.front();
        q.pop();
        if (sp[x][y][p.X][p.Y]!=-1)
            continue;
        sp[x][y][p.X][p.Y] = p.cst;
        for (int i=0;i<8;i++){
            int nx = p.X+dx[i], ny = p.Y+dy[i];
            if (inboard(nx, ny)&&grid[nx][ny]!='K'&&grid[nx][ny]!='p'&&sp[x][y][nx][ny]==-1){
                q.push(mp(nx,ny,p.cst+1));
            }
        }
    }
}

vector<ii> pawns;
int done;

void fill_sp(){
    memset(sp,-1,sizeof sp);
    for (int i=0;i<8;i++)
    for (int j=0;j<8;j++){
        if (grid[i][j]=='k'||grid[i][j]=='P'){
            bfs(i,j);
        }
        if(grid[i][j]=='k') pawns.insert(pawns.begin(), ii(i,j));
        if(grid[i][j]=='P') pawns.push_back(ii(i,j));
    }
    done = (1<<(pawns.size()-1))-1;
}


int recur(int last, int bm){
    if(bm==done) return 0;

    if(dp[last][bm]!=-1) return dp[last][bm];

    int cur, minv=INF;
    for(int i=0; i<pawns.size()-1; i++){
        if(!(bm&(1<<i))){
            cur = sp[pawns[last].first][pawns[last].second][pawns[i+1].first][pawns[i+1].second]+
                recur(i+1, bm|(1<<i));
            minv=min(minv, cur);
        }
    }
    return dp[last][bm]=minv;
}


int main(){
    int t, i,j,k, minv;

    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i=0; i<8; i++) scanf("%s", grid[i]);

        pawns.clear();
        fill_sp();

        memset(dp, -1, sizeof dp);
        minv = recur(0, 0);
        //printf("%d\n", minv);
        if(minv<=n) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
