#include <stdio.h>
/*c*/

int arr[105][105];
int dp[105][105];

int main(){
    int N, i , j, k ,l, up, left, corner, maxSum, sum;

    scanf("%d", &N);
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            up=0;left=0;corner=0;
            if(i>0)
                up=dp[i-1][j];
            if(j>0)
                left=dp[i][j-1];
            if(i>0&&j>0)
                corner=dp[i-1][j-1];

            dp[i][j] = arr[i][j] + up+left-corner;
        }
    }

    maxSum=0;
    for(i=0; i<N; i++){
        for(j=-1; j<i; j++){
            for(k=0; k<N; k++){
                for(l=-1; l<k; l++){
                    sum = dp[i][k]-dp[j][k]-dp[i][l]+dp[j][l];
                    if(sum>maxSum)
                        maxSum=sum;
                }
            }
        }
    }
    printf("%d\n", maxSum);
    return 0;
}
/*
4
0 -2 -7  0
9  2 -6  2
-4  1 -4  1
-1 8  0 -2
*/
