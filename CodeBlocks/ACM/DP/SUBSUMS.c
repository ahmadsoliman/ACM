#include <stdio.h>

int dp[40][40];

int main(){
    int N, A, B, i,j,k;
    long long countS=0ll;

    scanf("%d %d %d", &N, &A, &B);
    for(i=0; i<N; i++){
        scanf("%d", &dp[i][i]);
        if(dp[i][i]>=A && dp[i][i]<=B)countS++;
    }
    if(0>=A && 0<=B)countS++;

    for(k=1; k<N; k++){
        for(i=0; i+k<N; i++){//i row, i+k column
            dp[i][i+k] = dp[i][i] + dp[i+1][i+k];
            if(dp[i][i+k]>=A && dp[i][i+k]<=B) countS++;
        }
    }
    printf("%lld\n", countS);
    return 0;
}
