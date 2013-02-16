#include <stdio.h>

int dp[75][75];

int main(void){
    int t, N, T, P, rem, i,j,k;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &N, &T, &P);
        rem = T - P*N;

        for(i=0; i<=N; i++){
            for(j=0; j<=rem; j++){
                dp[i][j]=0;
            }
        }

        for(i=0; i<=N; i++){
            dp[i][0]=1;
        }
        for(i=0; i<=rem; i++){
            dp[1][i]=1;
        }
        for(i=2; i<=N; i++){
            for(j=1; j<=rem; j++){
                for(k=0; k<=j; k++){
                    dp[i][j] += dp[i-1][j-k];
                }
            }
        }

        printf("%d\n", dp[N][rem]);
    }

    return 0;
}
