#include <stdio.h>
#include <string.h>
#define max(x,y) ((x>y)?x:y)

int w, n, depths[31], golds[31], taken[31], dp[31][1005];

int recur(int i, int t){
    if(i==n || t==0)
        return 0;
    if(dp[i][t]!=-1)
        return dp[i][t];
    int a = recur(i+1, t), b = 0, tNeeded = 3*w*depths[i];
    if(t>=tNeeded)
        b = golds[i] + recur(i+1, t-tNeeded);
    if(a>=b)
        taken[i] = 0;
    else
        taken[i] = 1;
    return dp[i][t] = max(a, b);
}

int main(){
    int t, i, c, e=0;
    while(scanf("%d %d", &t, &w)>0){
        scanf("%d", &n);
        for(i=0; i<n; i++) scanf("%d %d", &depths[i], &golds[i]);

        if(e)
            printf("\n");
        else
            e=1;
        memset(taken, 0, sizeof taken);
        memset(dp, -1, sizeof dp);
        printf("%d\n", recur(0, t));
        c=0;
        for(i=0; i<n; i++) if(taken[i]) c++;
        printf("%d\n", c);
        for(i=0; i<n; i++) if(taken[i]) printf("%d %d\n", depths[i], golds[i]);
    }
    return 0;
}
