#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define max(x,y) ((x>y)?x:y)

char s[1005];
int dp[1005][1005], len, vis[1005][1005], kase;

int recur(int i, int j){
    if(i==j) return 1;
    if(i>j) return 0;

    if(vis[i][j]==kase) return dp[i][j];

    int o1,o2,o3,o4;
    o1=o2=o3=0;
    if(s[i]==s[j]) o1=2+recur(i+1, j-1);
    o2 = recur(i+1, j);
    o3 = recur(i, j-1);

    vis[i][j]=kase;
    return dp[i][j]=max(max(o1,o2), o3);
}

int main(){
    int t, i,j,k;
    kase=1;
    sscanf(gets(s), "%d", &t);
    while(t--){
        gets(s);
        len = strlen(s);
        if(len==0) printf("0\n");
        else printf("%d\n", recur(0, len-1));
        kase++;
    }
    return 0;
}
