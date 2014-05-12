#include <stdio.h>
#include <string.h>
#include <math.h>

double pw,pd,pl, dp[2000][2000];
int vis[2000][2000], kase;

double recur(int n, int p){
    if(p<=0) return 1;
    if(n==0) return 0;
    if(vis[n][p]==kase) return dp[n][p];
    vis[n][p]=kase;
    return dp[n][p]=pw*recur(n-1, p-3)+pd*recur(n-1, p-1)+pl*recur(n-1, p);
}

int main(){
    kase=1;
    int n,p, nw,nd,nl,nt, i,j,k;
    while(scanf("%d %d", &n, &p)>0){
        if(n==0&p==0) return 0;
        scanf("%d %d %d", &nw, &nd, &nl);
        nt=nw+nd+nl;
        pw=1.0*nw/nt;
        pd=1.0*nd/nt;
        pl=1.0*nl/nt;

        printf("%.1lf\n", 100*recur(n, p));
        kase++;
    }
    return 0;
}
