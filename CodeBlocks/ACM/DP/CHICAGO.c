#include <stdio.h>
#include <string.h>
#include <math.h>

int n, g[105][105], vis[105];
double dp[105];

double recur(int i){
    if(i==n-1) return 1;
    vis[i]=1;
    double maxv=0, curv;
    int j;
    for(j=0; j<n; j++){
        if(!vis[j] && g[i][j]!=-1){
            curv=g[i][j]/100.0*recur(j);
            if(curv>maxv) maxv=curv;
        }
    }
    vis[i]=0;
    return dp[i]=maxv;
}

int main(){
    int m, i,j,k, u,v,w;
    while(scanf("%d", &n)>0){
        if(n==0) return 0;
        memset(g, -1, sizeof g);
        scanf("%d", &m);
        for(i=0; i<m; i++){
            scanf("%d %d %d", &u, &v, &w);
            u--;v--;
            g[u][v]=w;
            g[v][u]=w;
        }
        for(i=0; i<n; i++) dp[i]=-1;
        memset(vis, 0, sizeof vis);
        printf("%.6lf\n", recur(0)*100.0);
    }
    return 0;
}
