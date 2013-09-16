#include <stdio.h>

int n, arr[1005], dp[1005][1005], vis[1005][1005], kase;

int recur(int i, int w){
    if(i>=n) return 0;
    if(vis[i][w]==kase)
        return dp[i][w];
    int a=recur(i+1, w), b=0;
    if(arr[i]<=w) b=arr[i]+recur(i+2, w-arr[i]);
    if(b>a) a = b;
    vis[i][w]=kase;
    return dp[i][w]=a;
}

int main(){
    int t, w, i;
    scanf("%d", &t);
    kase=1;
    while(t--){
        scanf("%d %d", &n, &w);
        for(i=0; i<n; i++) scanf("%d", &arr[i]);
        printf("Scenario #%d: %d\n", kase++, recur(0, w));
    }
    return 0;
}
