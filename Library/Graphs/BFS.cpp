#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

#define EPS 1e-9

using namespace std;

struct point {
    int x,y;
} pts[1010];

double dist(point p1, point p2){
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

int depth[1010];
vector<int> graph[1010];

int main(){
    int t, n, S, F, i,j, x,y, u, v, done;
    double L1, L2, len, d;

    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d %lf %lf", &n, &S, &F, &L1, &L2);
        S--;F--;
        len = L1+L2;
        for(i=0; i<n; i++) {
            scanf("%d %d", &pts[i].x, &pts[i].y);
            graph[i].clear();
        }

        for(i=0; i<n; i++) {
            for(j=i+1; j<n; j++) {
                d = dist(pts[i], pts[j]);
                if(d-len<EPS){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }


        memset(depth, -1, sizeof depth);
        queue<int> q;
        q.push(S);
        depth[S]=0;
        done=0;
        while(!q.empty() && !done){
            u = q.front(); q.pop();
            for(i=0; i<graph[u].size(); i++){
                v = graph[u][i];
                if(depth[v]==-1){
                    depth[v] = depth[u]+1;
                    q.push(v);
                }
                if(v==F) { done=1; break; }
            }
        }

        if(depth[F]==-1) printf("Impossible\n");
        else printf("%d\n", depth[F]);
    }
    return 0;
}
/*

2
4 1 4 2.000 1.000
0 0
0 4
4 0
4 4
9 1 4 2.000 3.000
0 7
-6 2
-3 3
6 2
-6 -3
3 -3
6 -3
-3 -7
0 -7

*/
