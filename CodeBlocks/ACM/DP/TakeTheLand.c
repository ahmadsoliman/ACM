#include <stdio.h>
#include <string.h>

int dp[105][105][105][105], map[105][105];

int main(){
    int M,N, i, j, k, l, column, row, maxArea, area;
    memset(dp, 1, sizeof dp);
    while(scanf("%d %d", &M, &N)>0){
        if(M==0 && N==0)
            break;
        for(i=0; i<M; i++){
            for(j=0; j<N; j++){
                scanf("%d", &map[i][j]);
            }
        }
        /*for(i=1; i<=M; i++){
            for(j=1; j<=N; j++){
                dp[0][i][0][j]=1;
            }
        }*/

        maxArea=0;
        for(i=1; i<=M; i++){
            for(k=0; k<i; k++){
                for(j=1; j<=N; j++){
                    for(l=0; l<j; l++){
                        dp[i][k][j][l]=dp[i-1][k][j][l] & dp[i][k][j-1][l] & !map[i-1][j-1];
                        area = (i-k)*(j-l);
                        if(dp[i][k][j][l] && area>maxArea)
                            maxArea=area;
                    }
                }
            }
        }
        printf("%d\n", maxArea);
    }
    return 0;
}
