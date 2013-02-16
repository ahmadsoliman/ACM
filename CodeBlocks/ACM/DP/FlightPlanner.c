#include <stdio.h>
#include <string.h>

#define min(x,y) ((x<y)?x:y)

int arr[1005][10], dp[1005][10], X, visited[1005][10];

int recur(int x, int l){
    if(x==0 && l>0)
        return 1000000;
    if(x==0&&l==0)
        return 0;
    int a=1000000,b=1000000,c=1000000;
    if(visited[x][l])
        return dp[x][l];
    visited[x][l]=1;
    if(l>0)
        a = recur(x-1, l-1)+60-arr[x-1][l-1];
    b = recur(x-1,l)+30-arr[x-1][l];
    if(l<9)
        c = recur(x-1,l+1)+20-arr[x-1][l+1];

    return (dp[x][l] = min(a, min(b, c)));
}

int main(){
    int t, x, i, j;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&X);
        x=X/100;
        for(i=9; i>=0; i--){
            for(j=0; j<x; j++){
                scanf("%d", &arr[j][i]);
                dp[j][i]=2000000000;
                visited[j][i] = 0;
            }
        }
        recur(x,0);

        printf("%d\n\n", dp[x][0]);
    }
    return 0;
}
