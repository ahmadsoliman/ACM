#include <stdio.h>
#include <string.h>

#define min(x,y) ((x<y)?x:y)

int N, M, fare[101][101], dp[101][101];

int recur(int i, int j){
    if(i==N)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    int a = fare[i+1][j] + recur(i+1, j), b=1000000000, c=1000000000;
    if(j>0) b = fare[i+1][j-1] + recur(i+1, j-1);
    if(j<M-1) c = fare[i+1][j+1] + recur(i+1, j+1);
    return dp[i][j] = min(a,min(b,c));
}

int main(){
    int i,j,curC,minC=1000000000;
    scanf("%d %d", &N, &M);
    for(i=0; i<N; i++)for(j=0; j<M; j++) scanf("%d", &fare[i][j]);
    memset(dp, -1, sizeof dp);
    for(i=0; i<M; i++){
        curC = fare[0][i] + recur(0,i);
        if(curC<minC)
            minC = curC;
    }
    printf("%d\n", minC);
    return 0;
}
