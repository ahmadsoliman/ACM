#include <stdio.h>
#include <string.h>
#include <math.h>

double dp[15][105];
int mark[15][105], N, M;

double recur(int n, int m){
    if(m<=0)
        return -10000;
    if(n==1){
        if(mark[n][m]<5)
            return dp[n][m]=-10000;
        else
            return dp[n][m]=mark[n][m];
    }
    if(dp[n][m]>-1)
        return dp[n][m];
    int i;
    double curMax, maxM=0;
    for(i=1; i<=m; i++){
        if(mark[n][i]<5)
            continue;
        curMax = (recur(n-1,m-i)+mark[n][i]);
        if(curMax>maxM)
            maxM=curMax;
    }
    return dp[n][m]=maxM;
}

int main(){
    int t, i, j;
    double marks,marksBf;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &N, &M);
        for(i=1; i<=N; i++){
            for(j=1; j<=M; j++){
                scanf("%d", &mark[i][j]);
            }
        }
        memset(dp, -1, sizeof dp);
        marksBf=recur(N,M)/N;
        marks=(round(marksBf*100)/100);
        if(marksBf>=5.0)
            printf("Maximal possible average mark - %.2lf.\n", marks);//not %d
        else
            printf("Peter, you shouldn't have played billiard that much.\n");
    }
    return 0;
}
