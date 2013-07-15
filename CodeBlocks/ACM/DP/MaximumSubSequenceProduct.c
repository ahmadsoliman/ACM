#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INF 10000000000000ll
#define max(x,y) ((x>y)?x:y)

int n, nums[105];
long long dp[105][105];

int main(){
    int i, j;
    long long res, cur;
    while(scanf("%d", &nums[0])>0){
        n = 1;
        while(nums[n-1]!=-999999) scanf("%d", &nums[n++]);
        n--;

        res = -INF;
        for(i=0; i<n; i++){
            for(j=i; j<n; j++){
                if(i==j)
                    dp[i][j] = nums[i];
                else
                    dp[i][j] = dp[i][j-1]*nums[j];
                if(dp[i][j]>res)
                    res = dp[i][j];
            }
        }
        printf("%ld\n", res);
    }
    return 0;
}
