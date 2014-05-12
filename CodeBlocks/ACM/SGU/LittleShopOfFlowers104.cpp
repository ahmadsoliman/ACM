#include <stdio.h>
#include <math.h>
#include <string.h>

#define INF 1000000000

int F, V, val[105][105], dp[105][105];

int recur(int i, int j){
    if(i==F) return dp[i][j]=0;
    if(j==V) return dp[i][j]=-INF;

    if(dp[i][j]!=-1) return dp[i][j];

    int a=recur(i,j+1), b=val[i][j]+recur(i+1, j+1);

    if(a>b) return dp[i][j]=a;
    return dp[i][j]=b;
}

int res[105];

void recon(int i, int j){
    if(i==F) return;
    int a=dp[i][j+1], b=val[i][j]+dp[i+1][j+1];

    if(a>=b) {
        recon(i, j+1);
    }else{
        res[i]=j+1;
        recon(i+1, j+1);
    }
}

int main(){
    int i,j,k;
    memset(dp, -1, sizeof dp);
    scanf("%d %d", &F, &V);
    for(i=0; i<F; i++) for(j=0; j<V; j++) scanf("%d", &val[i][j]);
    printf("%d\n", recur(0,0));
    recon(0,0);
    printf("%d", res[0]);
    for(i=1; i<F; i++){
        printf(" %d", res[i]);
    }
    printf("\n");
    return 0;
}
