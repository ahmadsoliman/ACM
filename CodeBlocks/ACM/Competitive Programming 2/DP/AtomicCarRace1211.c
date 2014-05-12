#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define min(x,y) ((x<y)?x:y)
#define EPS 1e-9

int n, ai[105], kase, vis[105][105];
double b,r,v,e,f, cumm[10010], dp[105][105];

double recur(int i, int last){
    if(i==n-1) return cumm[ai[i]-ai[last]];
    if(vis[i][last]==kase) return dp[i][last];
    double ac=recur(i+1, last), bc=b+recur(i+1, i)+cumm[ai[i]-ai[last]];
    vis[i][last]=kase;
    return dp[i][last]=min(ac, bc);
}

int main() {
    kase=1;
    int i,j;
    ai[0]=cumm[0]=0;
    while(scanf("%d", &n)>0){
        if(n==0) return 0;
        n++;
        for(i=1; i<n; i++) scanf("%d", &ai[i]);
        scanf("%lf", &b);
        scanf("%lf %lf %lf %lf", &r, &v, &e, &f);

        for(i=1; i<=ai[n-1]; i++) {
            cumm[i]=cumm[i-1];
            if(i-1<r) cumm[i]+=1.0/(v-f*(r-i+1));
            else cumm[i]+=1.0/(v-e*(i-r-1));
        }
        printf("%.4lf\n", recur(1, 0));
        kase++;
    }
    return 0;
}
