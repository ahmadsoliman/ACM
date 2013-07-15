#include <stdio.h>
#include <string.h>

#define INF 10000000

int n, m, b, t[8], g[30][30], done;
double dp[30][260];

double recur(int a, int bm){
    if(a==b)
        return 0;
    if(bm==done)
        return INF;
    if(dp[a][bm]>-1)
        return dp[a][bm];
    int i,j;
    double curV, minV = INF;
    for(i=0; i<n; i++){
        if(!(bm & (1<<i))){
            for(j=0; j<m; j++){
                if(a!=j && g[a][j]!=-1){
                    curV = 1.0*g[a][j]/t[i] + recur(j, bm|(1<<i));
                    if(curV<minV)
                        minV = curV;
                }
            }
        }
    }
    return dp[a][bm] = minV;
}

int main(){
    int p, a, i, ai, bj, dij;
    double v;
    while(scanf("%d %d %d %d %d", &n, &m, &p, &a, &b)>0){
        if(n==0&&m==0&&p==0&&a==0&b==0) break;
        a--;
        b--;
        for(i=0; i<n; i++) scanf("%d", &t[i]);
        memset(g, -1, sizeof g);
        for(i=0; i<p; i++){
            scanf("%d %d %d", &ai, &bj, &dij);
            g[ai-1][bj-1] = dij;
            g[bj-1][ai-1] = dij;
        }
        for(i=0, done=0; i<n; i++) {done<<=1; done|=1;}
        memset(dp, -1, sizeof dp);
        v = recur(a, 0);
        if(v<INF) printf("%.3lf\n", v);
        else printf("Impossible\n");
    }
    return 0;
}
