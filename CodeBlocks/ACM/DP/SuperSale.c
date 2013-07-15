#include <stdio.h>
#include <string.h>

#define max(x,y) ((x>y)?x:y)

int P[1005], W[1005], dp[1005][35], n;

int recur(int i, int mw){
    if(i==n || mw==0) return 0;
    if(dp[i][mw]!=-1)
        return dp[i][mw];
    return dp[i][mw] = max(recur(i+1, mw), ((W[i]<=mw)?(P[i]+recur(i+1,mw-W[i])):-1));
}

int main(){
    int t, g, i, mw, c;
    scanf("%d", &t);
    while(t--){
        memset(dp, -1, sizeof dp);

        scanf("%d", &n);
        for(i=0; i<n; i++) scanf("%d %d", &P[i], &W[i]);

        c = 0;
        scanf("%d", &g);
        for(i=0; i<g; i++) {
            scanf("%d", &mw);
            c += recur(0, mw);
        }
        printf("%d\n", c);

    }
    return 0;
}
