#include <stdio.h>
#include <string.h>

int n, arr[1005], cumm[1005], dp[1005][1005][2];

void recur(int i, int k){
    if(k==0) {

        return;
    }
    if(i==0) return;

}

int main(){
    int m, i;
    while(scanf("%d%d", &n, &m)>0){
        if(n==0&&m==0) return 0;
        for(i=0; i<n; i++) scanf("%d", &arr[i]);

        cumm[n-1]=arr[n-1];
        for(i=n-2; i>=0; i--) cumm[i]=cumm[i+1]+arr[i];

        memset(dp, -1, sizeof dp);
        //recur(n-1, m);

        printf("%d\n", dp[n-1][m][0]);
    }
    return 0;
}
