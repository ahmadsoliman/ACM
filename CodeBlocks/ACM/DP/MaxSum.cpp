#include <stdio.h>
/*c*/

int arr[105][105];
int dp[105][105];


#define MIN -2000000000
int columnSum[105];
int kadane2D(int R, int C){
    int s=MIN,S=MIN,t, row, x, i;
    for(row = 0; row<R; row++) {
        for(i=0; i<C; i++) columnSum[i] = 0;
        for(x = row; x<R; x++) {
            s = MIN;
            t = 0;
            for(i=0; i<C; i++) {
                columnSum[i]+=arr[x][i];
                t+=columnSum[i];
                if(t>s) s = t;
                if(t<0) t = 0;
            }
            if(s>S) S = s;
        }
    }
    return S;
}

int main(){
    int N, i , j, k ,l, up, left, corner, maxSum, sum;

    scanf("%d", &N);
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            scanf("%d", &arr[i][j]);
        }
    }
/*
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
*/
    maxSum=kadane2D(N, N);
/*    for(i=0; i<N; i++){
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
  */  printf("%d\n", maxSum);
    return 0;
}
/*
4
0 -2 -7  0
9  2 -6  2
-4  1 -4  1
-1 8  0 -2
*/
