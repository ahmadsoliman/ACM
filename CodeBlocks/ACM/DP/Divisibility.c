#include <stdio.h>
#include <string.h>

int arr[10005], dp[10005][105], N, K;

int recur(int i, int resSF){
    if(i==N){
        if(resSF%K==0)
            return 1;
        return 0;
    }
    if(dp[i][resSF]>-1)
        return dp[i][resSF];
    return (dp[i][resSF]=recur(i+1, (resSF+arr[i])%K)||recur(i+1, (resSF-arr[i])%K));
}

int main(){
    int t, i;
    scanf("%d", &t);
    while(t--){
        memset(dp, -1, sizeof dp);

        scanf("%d %d", &N, &K);
        for(i=0; i<N; i++){
            scanf("%d", &arr[i]);
            arr[i]=arr[i]%K;
        }
        if(N==1){
            if(arr[0]==0)
                printf("Divisible\n");
            else
                printf("Not divisible\n");
        }else{
            if(recur(1,arr[0]))
                printf("Divisible\n");
            else
                printf("Not divisible\n");
        }
    }
    return 0;
}
