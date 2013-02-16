#include <stdio.h>
#include <string.h>

#define max(x,y) ((x>y)?x:y)

int M[205][205], m , n, dp[205][205][2];

int recur(int i, int j, int dir){//dir 0:right, 1:left
    if(j<0||i>=m||j>=n)return 0;
    if(M[i][j]==2)return 0;
    if(dp[i][j][dir]>-1)return dp[i][j][dir];
    if(dir==0){
        return dp[i][j][dir] = M[i][j]+max(recur(i,j+1,dir), recur(i+1, j, !dir));
    }else{
        return dp[i][j][dir] = M[i][j]+max(recur(i,j-1,dir), recur(i+1, j, !dir));
    }
}

char s[205];

int main(){
    int t, i, j;
    scanf("%d", &t);
    while(t--){
        memset(dp, -1, sizeof dp);
        scanf("%d %d", &m, &n);
        for(i=0; i<m; i++){
            scanf("%s", &s);
            for(j=0; j<n; j++){
                switch(s[j]){
                    case '0':M[i][j]=0;break;
                    case 'T':M[i][j]=1;break;
                    case '#':M[i][j]=2;break;
                    default: M[i][j]=0;
                }
            }
        }
        printf("%d\n", recur(0, 0, 0));
    }
    return 0;
}
