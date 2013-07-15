#include <stdio.h>
#include <string.h>

int N, n, nums[2100], done, vis[2048], dp[1025][1025];

int recur(int t, int sum){
    if(t==N){
        if(sum%N)
            return 0;
        return dp[t][sum] = 1;
    }

    if(dp[t][sum]!=-1)
        return dp[t][sum];

    int i;
    for(i=0; i<n; i++){
        if(!vis[i]){
            vis[i] = 1;
            if(recur(t+1, (sum+nums[i])%N)){
                return dp[t][sum] = 1;
            }else
                vis[i] = 0;
        }
    }
    return dp[t][sum] = 0;
}

int main(){
    int i, res;
    while(scanf("%d", &N)>0){
        if(N==0)
            break;
        n = 2*N-1;
        for(i=0; i<n; i++) scanf("%d", &nums[i]);

        memset(vis, 0, sizeof vis);
        memset(dp, -1, sizeof dp);
        res = recur(0, 0);
        if(!res){
            printf("No\n");
        }else{
            int j, e=0;
            printf("Yes\n");
            for(j=0; j<n; j++){
                if(vis[j]){
                    if(e)
                        printf(" ");
                    else
                        e = 1;
                    printf("%d", nums[j]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}
