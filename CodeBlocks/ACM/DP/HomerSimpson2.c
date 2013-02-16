#include <stdio.h>

int dp[10001][10001];



int main(void){
    int m, n, t, i ,j, N, found, foundMax, notFoundMax, notFoundTime;
    while(scanf("%d %d %d", &m ,&n ,&t)>0){
        if(m<n)
            N = t/m;
        else
            N = t/n;
        foundMax = 0;
        found = 0;
        notFoundMax=0;
        notFoundTime=0;

        for(i=0; i<=N; i++){
            for(j=0; j<=N; j++){
                dp[i][j]=i*m+j*n;
                if(dp[i][j]>t)
                    break;
                if(dp[i][j]==t && i+j>foundMax){
                    foundMax=i+j;
                    found=1;
                }
                if(dp[i][j]==notFoundTime && notFoundMax<i+j)
                    notFoundMax=i+j;
                if(dp[i][j]>notFoundTime && dp[i][j]<t){
                    notFoundTime=dp[i][j];
                    notFoundMax=i+j;
                }
               // printf("%d ",dp[i][j]);
            }
            //printf("\n");
        }
        if(found>0){
            printf("%d\n",foundMax);
        }else{
            printf("%d %d\n", notFoundMax, (t-notFoundTime));
        }
    }
    return 0;
}
