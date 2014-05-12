#include <stdio.h>
#include <string.h>
#include <math.h>

#define INF 1000000000

int g[155][155], dp[155][155];

int main(){
    int t, i,j,k,l, n, maxv, cur;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i=0; i<n; i++) for(j=0; j<n; j++) {
            scanf("%d", &g[i][j]);
            g[i+n][j]=g[i][j+n]=g[i+n][j+n]=g[i][j];
        }
        n++;
        maxv=-INF;
        for(i=1; i<2*n; i++) for(j=1; j<2*n; j++) dp[i][j]=g[i-1][j-1]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        for(i=1; i<n; i++) for(j=i; j<i+n-1; j++) for(k=1; k<n; k++) for(l=k; l<k+n-1; l++){
            cur = dp[j][l]-dp[j][k-1]-dp[i-1][l]+dp[i-1][k-1];
            if(cur>maxv) maxv=cur;
        }
        printf("%d\n", maxv);
    }
    return 0;
}
