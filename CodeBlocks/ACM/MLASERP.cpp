#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, ii> iiii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

#define inboard(x,y) (x>=0&&x<h&&y>=0&&y<w)

char grid[105][105];
int vis[105][105], dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

template <class T> struct greaterp : binary_function <T,T,bool> {
  bool operator() (const T& x, const T& y) const {return x.first.first>y.first.first;}
};

int main(){
    int h,w, i,j,k, done;

    ii S, F;

    done=0;
    scanf("%d %d", &w, &h);
    for(i=0; i<h; i++){
        scanf("%s", grid[i]);
        if(done==2) continue;
        for(j=0; j<w; j++){
            if(grid[i][j]=='C'){
                if(done==0) S=ii(i,j);
                else F=ii(i,j);
                done++;
            }
        }
    }

    priority_queue< iiii , vector<iiii>, greaterp<iiii> > q;

    for(i=0; i<4; i++){
        if(inboard(S.first+dx[i], S.second+dy[i]) && grid[S.first+dx[i]][S.second+dy[i]]!='*')
           q.push(iiii(ii(0, i), ii(S.first+dx[i], S.second+dy[i])));
    }

    memset(vis, 0, sizeof vis);

    while(!q.empty()){
        iiii pp = q.top(); q.pop();
        ii val=pp.first, u=pp.second;
        if(vis[u.first][u.second]) continue;
        vis[u.first][u.second]=1;
        if(u==F) { printf("%d\n", val.first); return 0;}
        for(i=0; i<4; i++){
            if(inboard(u.first+dx[i], u.second+dy[i]) && grid[u.first+dx[i]][u.second+dy[i]]!='*')
                q.push(iiii(ii(val.first+((val.second==i)?0:1), i), ii(u.first+dx[i], u.second+dy[i])));
        }
    }

    return 0;
}

