#include <stdio.h>
#include <string.h>

int arr[1005][1005];
long long dp[1005][1005];

int main(){
    int N, M,i,j,k,l, e=0;
    long long tmp, sum, up,left,corner;
    while(scanf("%d %d", &N, &M)>0){
        if(e)
            printf("\n");
        else
            e=1;
        for(i=1; i<=N; i++){
            for(j=1; j<=N; j++){
                scanf("%d", &arr[i][j]);
                up=0;left=0;corner=0;
                if(i>1)
                    up=dp[i-1][j];
                if(j>1)
                    left=dp[i][j-1];
                if(i>1&&j>1)
                    corner=dp[i-1][j-1];

                dp[i][j] = arr[i][j] + up+left-corner;
            }
        }
        sum=0;
        for(i=1; i+M<=N+1; i++){
            for(j=1; j+M<=N+1; j++){
                sum += tmp = dp[i+M-1][j+M-1]-dp[i-1][j+M-1]-dp[i+M-1][j-1]+dp[i-1][j-1];
                printf("%d\n", tmp);
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
