#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define min(x,y) ((x<y)?x:y)

char s[1005];
int dp[1005][1005], len, vis[1005][1005], kase;

int recur(int i, int j){
    if(i>=j) return 0;

    if(vis[i][j]==kase) return dp[i][j];

    int o1,o2,o3,o4;
    o1=o2=o3=o4=1000000000;
    if(s[i]==s[j]) o1=recur(i+1, j-1);
    o2 = 1+recur(i+1, j);
    o3 = 1+recur(i, j-1);
    o4 = 1+recur(i+1, j-1);

    vis[i][j]=kase;
    return dp[i][j]=min(min(o1,o2), min(o3,o4));
}

int main(){
    int t, i,j,k;
    kase=1;
    scanf("%d", &t);
    while(t--){
        scanf("%s", s);
        len = strlen(s);
        printf("Case %d: %d\n", kase++, recur(0, len-1));
    }
    return 0;
}
