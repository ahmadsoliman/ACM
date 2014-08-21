#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int n, twoPowN, bX[12], bY[12], dp[1048580][12], elemC;

int recur(int i, int selSet){
    if(selSet==twoPowN)
        return (abs(bX[i]-bX[0])+abs(bY[i]-bY[0]));

    if(dp[selSet][i]!=-1)
        return dp[selSet][i];

    int j, curC, minC=2000000000;
    for(j=1; j<n; j++){
        if(i!=j && !(selSet & (1<<j))){
            curC = (abs(bX[i]-bX[j])+abs(bY[i]-bY[j])) + recur(j, selSet | (1<<j));
            if(curC<minC)
                minC = curC;
        }
    }
    return dp[selSet][i] = minC;
}

int main(){
    int t, w, h, i;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &w, &h);
        scanf("%d %d", &bX[0], &bY[0]);
        scanf("%d", &n);
        n++;
        twoPowN = pow(2,n)-1;
        for(i=1; i<n; i++) scanf("%d %d", &bX[i], &bY[i]);

        memset(dp, -1, sizeof dp);
        printf("The shortest path has length %d\n", recur(0,1));
    }
    return 0;
}
