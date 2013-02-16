#include <stdio.h>
#include <string.h>

#define min(x,y) ((x<y)?x:y)
#define INF (200000000)

int w[15][105], m, n, dp[15][105], vis[15][105];

int recur(int i, int j){
    if(j>=n){
        return 0;
    }
    if(vis[i][j])
        return dp[i][j];
    vis[i][j]=1;

    int a=INF,b=INF,c=INF;

    if(i>=m-1)
        c=w[i][j]+recur(0, j+1);
    if(i>0)
        a=w[i][j]+recur(i-1, j+1);
    b=w[i][j]+recur(i, j+1);
    if(i<m-1)
        c=w[i][j]+recur(i+1, j+1);
    if(i==0)
        a=w[i][j]+recur(m-1, j+1);
    return dp[i][j]=min(a,min(b,c));
}

int main(){
    int i,j, minC, curMin, minI, a, b, c;
    while(scanf("%d %d", &m, &n)>0){
        for(i=0; i<m; i++){
            for(j=0; j<n; j++){
                scanf("%d", &w[i][j]);
            }
        }
        memset(vis, 0, sizeof dp);

        minC=INF, minI=0;
        for(i=0; i<m; i++){
            curMin = recur(i, 0);
            if(curMin<minC){
                minC=curMin;
                minI=i;
            }
        }
        printf("%d", minI+1);
        for(i=1; i<n; i++){
            if(minI>0)
                a=dp[minI-1][i];
            else
                a=dp[m-1][i];
            b=dp[minI][i];
            if(minI<m-1)
                c=dp[minI+1][i];
            else
                c=dp[0][i];

            if(minI==m-1){
                if(a<=b){
                    if(a<c){
                        if(minI>0)
                            minI--;
                        else
                            minI=m-1;
                    }else{
                        minI=0;
                    }
                }else{
                    if(c<=b){
                        minI=0;
                    }
                }
            }else if(minI>0){
                if(a<=b){
                    if(a<=c){
                        minI--;
                    }else{
                        if(minI<m-1)
                            minI++;
                        else
                            minI=0;
                    }
                }else{
                    if(c<b){
                        if(minI<m-1)
                            minI++;
                        else
                            minI=0;
                    }
                }
            }else if(minI==0){
                if(a<b){
                    if(a<c){
                        minI=m-1;
                    }else{
                        minI++;
                    }
                }else{
                    if(c<b){
                        if(minI<m-1)
                            minI++;
                        else
                            minI=0;
                    }
                }
            }

            printf(" %d", (minI+1));
        }
        printf("\n%d\n", minC);
    }
    return 0;
}
