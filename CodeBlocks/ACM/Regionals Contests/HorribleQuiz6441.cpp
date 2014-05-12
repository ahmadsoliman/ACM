#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>

#define INF 1000000000

using namespace std;

int n, c[1500], w[1250], vis[1300][1300];
double dp[1300][1300];

double recur(int i, int m, int bal){
    if(i==n) return 0;

    double common=(c[i]-w[i])*bal;
    double a=1.0*(common+(100-c[i]-w[i])*bal) + recur(i+1, m, 1), b=1e9;
    if(m>0) b=1.0*(common-(100-c[i]-w[i])*bal) + recur(i+1, m-1, 1);

    return min(a,b);
}

int main(){
    int t, m, i,j,k, kase=1;
    double minv;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        for(i=0; i<n; i++) scanf("%d", &c[i]);
        for(i=0; i<n; i++) scanf("%d", &w[i]);

        memset(dp[n], 0 ,sizeof dp[n]);
        minv=1000000000;
        for(i=n-1; i>=0; i--){
            for(j=0; j<=m; j++){
                dp[i][j]=min((c[i]-w[i]+100-c[i]-w[i])+dp[i+1][j], (c[i]-w[i]-(100-c[i]-w[i]))+dp[i+1][j-1]);
                if(i==0) minv=min(minv, dp[i][j]);
            }
        }

        printf("Case #%d: %.3lf\n", kase++, minv*150);
    }
    return 0;
}
