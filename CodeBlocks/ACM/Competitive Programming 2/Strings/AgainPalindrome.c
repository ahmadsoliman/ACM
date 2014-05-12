#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define min(x,y) ((x<y)?x:y)

typedef long long ll;

char s[100];
ll dp[105][105], len, vis[105][105], kase;

ll recur(int i, int j){
    if(i==j) return 1;
    if(i>=j) return 0;

    if(vis[i][j]==kase) return dp[i][j];

    ll sum=0;
    if(s[i]==s[j]) sum+=1+recur(i+1, j-1);
    sum+=recur(i+1, j)+recur(i, j-1)-recur(i+1, j-1);

    vis[i][j]=kase;
    return dp[i][j]=sum;
}

int main(){
    int t, i,j,k, f;
    kase=1;
    scanf("%d", &t);
    while(t--){
        scanf("%s", s);
        len = strlen(s);

        printf("%lld\n", recur(0, len-1));
        kase++;
    }
    return 0;
}
