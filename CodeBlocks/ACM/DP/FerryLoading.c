#include <stdio.h>
#include <string.h>

#define max(x,y) ((x>y)?x:y)
#define EPS 1e-10

int len, n, dp[10000][100][100], ports[10000];
double cars[10000];

int recur(int i, double l, double r){
    if(i==n)return 0;
    if(l-(int)l >= 0.5) l = (int)l + 1;
    else l = (int)l;
    if(r-(int)r >= 0.5) r = (int)r + 1;
    else r = (int)r;

    if(dp[i][(int)l][(int)r]>-1)
        return dp[i][(int)l][(int)r];
    int left=-1, right=-1;
    if(l+cars[i] <= len)
        left = recur(i+1, l+cars[i], r);
    if(r+cars[i] <= len)
        right = recur(i+1, l, r+cars[i]);
    if(left==-1 && right==-1)
        return 0;
    if(left>right){
        ports[i] = 0;
        return dp[i][(int)l][(int)r] = 1+left;
    }else{
        ports[i] = 1;
        return dp[i][(int)l][(int)r] = 1+right;
    }
}

int main(){
    int t, cur, i;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &len);
        n = 0;
        while(scanf("%d", &cur) && cur!=0) cars[n++] = cur/100.0;

        memset(dp, -1, sizeof dp);
        int res = recur(0, 0.0, 0.0);
        printf("%d\n", res);
        for(i = 0; i<res; i++){
            printf("%s\n", (ports[i]==0)?"port":"starboard");
        }
    }
    return 0;
}
