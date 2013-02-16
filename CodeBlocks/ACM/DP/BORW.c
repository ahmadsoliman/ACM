#include <stdio.h>
#include <string.h>

#define max(x,y) ((x>y)?x:y)

int dp[205][205][205], nums[205], N;

int recur(int i, int prevB, int prevW){
    if(i==N)
        return 0;
    if(dp[i][prevB][prevW]>-1)
        return dp[i][prevB][prevW];
    int a=recur(i+1, prevB, prevW), b=0,c=0;
    if(prevB<0 || nums[i]>nums[prevB])
        b=1+recur(i+1, i, prevW);
    if(prevW<0 || nums[i]<nums[prevW])
        c=1+recur(i+1, prevB, i);
    return dp[i][prevB][prevW]=max(a,max(b,c));
}

int main(){
    int i;
    while(scanf("%d", &N)>0){
        if(N<0)
            break;
        memset(dp, -1, sizeof dp);
        for(i=0; i<N; i++){
            scanf("%d", &nums[i]);
        }
        printf("%d\n", N-max(recur(1,-1,-1), max(recur(1,0,-1),recur(1,-1,0))+1));
    }
    return 0;
}
