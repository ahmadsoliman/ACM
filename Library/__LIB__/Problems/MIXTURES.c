#include <stdio.h>
#include <string.h>

int n, nums[105], colors[105][105], dp[105][105];

int recur(int i, int j){
    if(i==j)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    int k, minC = 200000000, cur;
    for(k=i; k<j; k++){
        cur = recur(i,k) + recur(k+1,j) + colors[i][k]*colors[k+1][j];
        if(cur<minC)
            minC = cur;
    }
    return dp[i][j] = minC;
}

int main(){
    int i,j;
    while(scanf("%d", &n)>0){
        for(i=0; i<n; i++) {
            scanf("%d", &nums[i]);
            colors[i][i] = nums[i];
        }
        memset(dp, -1, sizeof dp);
        for(i=0; i<n; i++) for(j=i+1; j<n; j++) colors[i][j] = (colors[i][j-1] + nums[j])%100;
        printf("%d\n", recur(0,n-1));
    }
    return 0;
}
