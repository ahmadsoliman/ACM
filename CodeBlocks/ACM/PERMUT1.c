#include <stdio.h>

int dp[14][100];

int main(void){
    int t, n, k, i, j, r;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        for(i=0; i<=n; i++){
            for(j=0; j<=k; j++){
                dp[i][j]=0;
            }
        }

        for(i=1; i<=n; i++){
            dp[i][0]=1;
        }

        for(i=1; i<=n; i++){
            for(j=1; j<=k; j++){
                dp[i][j]=0;
                for(r=0; r<n&&r<=j; r++){
                    dp[i][j]+=dp[i-1][j-r];
                }
            }
        }
        printf("%d\n", dp[n][k]);
    }
    return 0;
}
