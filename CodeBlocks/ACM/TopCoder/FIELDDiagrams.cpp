//SRM 401

#include <stdio.h>

#define max(x,y) ((x>y)?x:y)

long long dp[35][35];

long long countDiagrams(int fieldOrder) {
    int i, j;
    for(i=0; i<fieldOrder; i++)
        dp[i][0]=fieldOrder-i;

    for(i=fieldOrder-2; i>=0; i--)
        for(j=1; j<dp[i][0]; j++){
            dp[i][j]=1+dp[i][j-1]+max(dp[i+1][j-1],dp[i+1][j]);
        }

    return dp[0][fieldOrder-1];
}

int main(){
    printf("%lld", countDiagrams(5));
    return 0;
}
