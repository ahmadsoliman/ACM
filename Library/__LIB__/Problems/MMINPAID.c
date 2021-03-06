#include <stdio.h>
#include <string.h>

#define INF 10000000

int n, m, a[12], b[12], c[12], p[12], r[12], dp[12][2200];

int recur(int i, int bm){
    if(i==n-1) return 0;

    if(dp[i][bm]!=-1)
        return dp[i][bm];

    dp[i][bm] = INF;

    int j, k, minC=INF, curC, rec;
    for(j=0; j<m; j++){
        if(i==a[j]){
            rec = recur(b[j], bm|(1<<i));
            curC = r[j] + rec;
            if(curC<minC) minC = curC;
            if(c[j]==a[j]){
                curC = p[j] + rec;
                if(curC<minC) minC = curC;
            }else{
                for(k=0; k<n; k++){
                    if(k==c[j]&&(bm&(1<<k))){
                        curC = p[j] + rec;
                        if(curC<minC) minC = curC;
                        break;
                    }
                }
            }
        }
    }
    return dp[i][bm]=minC;
}

int vis[11];

int dfs(int i){
    if(i==n-1) return 1;
    if(vis[i]) return 0;
    vis[i]=1;
    int j;
    for(j=0; j<m; j++) if(dfs(b[j])) return 1;
    return 0;
}

int main(){
    int i,res;
    scanf("%d", &n);
    scanf("%d", &m);
    for(i=0; i<m; i++){
        scanf("%d", &a[i]);
        scanf("%d", &b[i]);
        scanf("%d", &c[i]);
        scanf("%d", &p[i]);
        scanf("%d", &r[i]);
        a[i]--;b[i]--;c[i]--;
    }
    if(dfs(0)==0)
        printf("impossible\n");
    else{
        memset(dp, -1, sizeof dp);
        res = recur(0, 0);
        if(res>=INF)
            printf("impossible\n");
        else
            printf("%d\n", res);
    }
    return 0;
}
