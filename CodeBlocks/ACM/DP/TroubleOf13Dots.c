#include <stdio.h>
#include <string.h>
#define max(x,y) ((x>y)?x:y)

int totA, n, prices[105], favours[105], dp[10205][105];

int recur(int a, int i){
    if(i==n)
        return 0;
    if(a>2000){
        if(a==totA+200)
            return 0;
    }else if(a==totA)
        return 0;

    if(dp[a][i]!=-1)
        return dp[a][i];

    int x = recur(a, i+1), y = 0;
    if(a+prices[i]<=totA || (a>2000 && a+prices[i]<=totA+200))
        y = favours[i]+recur(a+prices[i],i+1);

    return dp[a][i] = max(x, y);
}

int main(){
    int a, i, s, f;
    while(scanf("%d %d", &a, &n)>0){
        s=0;
        f=0;
        for(i=0; i<n; i++) {
            scanf("%d %d", &prices[i], &favours[i]);
            s += prices[i];
            f += favours[i];
        }
        if(a>=s){
            printf("%d\n", f);
        }else{
            totA = a;
            memset(dp, -1, sizeof dp);
            printf("%d\n", recur(0, 0));
        }
    }
    return 0;
}
