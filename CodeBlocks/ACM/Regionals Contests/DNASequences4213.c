#include <stdio.h>
#include <string.h>

#define max(x,y) ((x>y)?x:y)

int k, n, m, dp[1005][1005], vis[1005][1005], kase;
char s1[1005], s2[1005];

int recur(int i, int j) {
    if(i>=n||j>=m) return 0;
    if(vis[i][j]==kase){
        return dp[i][j];
    }
    int a=recur(i+1, j), b=recur(i, j+1), cur, c=0;

    int r=0;
    while(i+r<n && j+r<m && s1[i+r]==s2[j+r]){
        r++;
        if(r>=k){
            cur = r+recur(i+r, j+r);
            if(cur>c) c=cur;
        }
    }
    vis[i][j]=kase;
    return dp[i][j] = max(a,max(b,c));
}

int main(){
    int i,j;
    kase=1;
    while(scanf("%d", &k)>0){
        if(k==0) return 0;
        scanf("%s%s", s1, s2);
        n = strlen(s1);
        m = strlen(s2);
        printf("%d\n", recur(0,0));
        kase++;
    }
    return 0;
}
