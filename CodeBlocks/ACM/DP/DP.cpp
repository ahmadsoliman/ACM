#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <math.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

struct mp{
    int first,second;
    mp(int x, int y){
        first=x;
        second=y;
    }
    mp(){
        first=second=-1;
    }
};

int m,n, c, done, memo[55][55], kase;
mp dp[20][1048577];
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1}, vis[55][55];

ii store;
vector<ii> bs;

char grid[55][55];

#define inboard(x,y) (x>=0 && x<m && y>=0 && y<n)

void dijkstra(){
    memset(vis, 0, sizeof vis);
    priority_queue<iii, vector<iii>, greater<iii> > q;
    q.push(iii(0, ii(store.first, store.second)));
    int x1,y1;
    while(!q.empty()){
        iii state=q.top(); q.pop();
        ii u = state.second;
        x1=u.first, y1=u.second;

        if(vis[x1][y1]) continue;
        vis[x1][y1]=1;
        memo[x1][y1]=state.first;

        if(grid[x1][y1]=='$' || grid[x1][y1]=='X'){
            for(int i=0; i<4; i++){
                if(inboard(x1+dx[i], y1+dy[i])) q.push(iii(state.first+2, ii(x1+dx[i], y1+dy[i])));
            }
        }else{
            for(int i=0; i<4; i++){
                if(inboard(x1+dx[i], y1+dy[i])){
                    if(grid[x1+dx[i]][y1+dy[i]]=='$' || grid[x1+dx[i]][y1+dy[i]]=='X'){
                        q.push(iii(state.first+2, ii(x1+dx[i], y1+dy[i])));
                    }else{
                        int diff=abs((grid[x1][y1]-'0')-(grid[x1+dx[i]][y1+dy[i]]-'0'));
                        if(diff==0) q.push(iii(state.first+1, ii(x1+dx[i], y1+dy[i])));
                        else if(diff==1) q.push(iii(state.first+3, ii(x1+dx[i], y1+dy[i])));
                    }
                }
            }
        }
    }
}

mp recur(int i, int bm){
    if(i==c) {
        int late1=-1, late0=-1;
        for(int j=c-1; j>=0; j--) if((bm&(1<<j))==1) { late1=j; break; }
        for(int j=c-1; j>=0; j--) if((bm&(1<<j))==0) { late0=j; break; }

        return mp((late1>=0)?-1*memo[bs[late1].first][bs[late1].second]:0,
                  (late0>=0)?-1*memo[bs[late0].first][bs[late0].second]:0);
    }
    if(dp[i][m].first!=-1) return dp[i][bm];

    int t=memo[bs[i].first][bs[i].second]*2;
    mp a=recur(i+1, bm), b=recur(i+1, bm|(1<<i));

    a.second+=t;
    b.first+=t;

    if(max(a.first, a.second)<=max(b.first, b.second)) return dp[i][bm]=a;
    return dp[i][bm]=b;
}

int main(){
    int t, i,j,k;
    kase=1;
    mp e;

    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &m, &n);
        store=ii(-1,-1);
        bs.clear();
        memset(memo, -1, sizeof memo);

        for(i=0; i<m; i++) {
            scanf("%s", grid[i]);
            for(j=0; j<n; j++){
                if(grid[i][j]=='X') store=ii(i,j);
                else if(grid[i][j]=='$') bs.push_back(ii(i,j));
            }
        }
        if(store.first==-1 || bs.size()==0) {
            printf("0\n");
            continue;
        }
        c=bs.size();
        done=(1<<c)-1;

        dijkstra();
        mp r = recur(0, 0);
        printf("%d\n", max(r.first, r.second));

        if(t){
            for(i=0; i<c; i++) for(j=0; j<done+1; j++) dp[i][j]=e;
        }
        kase++;
    }
    return 0;
}
/*
2
3 7
3442211
34$221X
3442211
3 7
001000$
$010X0$
0010000
*/
