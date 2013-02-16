#include <stdio.h>

int dp[100005], nums[100005];

int GCD(int m, int n){
    if(m==0)
        return n;
    return GCD(n%m,m);
}

int main(){
    int n, i, j, longest;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &nums[i]);
    }
    dp[0]=1;
    for(i=1; i<n; i++){
        longest=0;
        for(j=0; j<i; j++){
            if(GCD(nums[j],nums[i])>1 && dp[j]>longest)
                longest = dp[j];
        }
        dp[i]=longest+1;
    }
    printf("%d", dp[n-1]);
    return 0;
}
