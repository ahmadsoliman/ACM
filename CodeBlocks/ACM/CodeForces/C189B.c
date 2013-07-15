#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int c, s[105], e[105], vis[105], dp[105][105];

int recur(int a, int b){
    if(a==b)
        return 1;

    if(dp[a][b]!=-1)
        return dp[a][b];

    int i, res=0;
    vis[a] = 1;
    for(i=0; i<c; i++){
        if(!vis[i] && ((s[a]>s[i] && s[a]<e[i]) || e[a]>s[i] && e[a]<e[i]))
            res |= recur(i, b);
    }
    return dp[a][b] = res;
}

int main(){
    int t, q, a, b;

    scanf("%d", &t);
    while(t--){
        scanf("%d", &q);
        if(q==1) {
            scanf("%d %d", &a, &b);
            s[c] = a;
            e[c] = b;
            c++;
        }else{
            memset(vis, 0, sizeof vis);
            memset(dp, -1, sizeof dp);
            scanf("%d %d", &a, &b);
            if(recur(a-1,b-1)) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
