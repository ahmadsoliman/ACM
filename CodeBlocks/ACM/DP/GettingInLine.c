#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int n, twoPowN, bX[12], bY[12];
double dp[10][600];

double recur(int i, int selSet){
    if(selSet==twoPowN)
        return 0;

    if(dp[i][selSet]!=-1)
        return dp[i][selSet];

    int j;
    double curC, minC=20000000;
    for(j=0; j<n; j++){
        if(i!=j && !(selSet & (1<<j))){
            curC = 16 + sqrt(pow(bX[i]-bX[j],2)+pow(bY[i]-bY[j],2)) + recur(j, selSet | (1<<j));
            if(curC<minC)
                minC = curC;
        }
    }
    return dp[i][selSet] = minC;
}

int main(){
    int i, j, minI, selSet, kase=1;
    double curC, minC, minTotC;
    while(scanf("%d", &n)>0){
        if(n==0)
            break;
        for(i=0; i<n; i++)  scanf("%d %d", &bX[i], &bY[i]);
        twoPowN = pow(2,n)-1;

        for(i=0; i<=n; i++)for(j=0; j<=twoPowN*2; j++)dp[i][j]=-1;

        minC = 20000000;
        for(i=0; i<=n; i++){
            curC = recur(i,(1<<i));
            if(curC<minC){
                minC=curC;
                minI = i;
            }
        }
        minTotC = minC;

        printf("**********************************************************\nNetwork #%d\n", kase++);

        selSet = (1<<minI);
        i = minI;
        while(selSet!=twoPowN){
            minC = 20000000;
            for(j=0; j<n; j++){
                curC = 16 + sqrt(pow(bX[i]-bX[j],2)+pow(bY[i]-bY[j],2)) + dp[j][selSet | (1<<j)];
                if(i!=j && !(selSet & (1<<j)) && curC<=minC){
                    minC = curC;
                    minI = j;
                }
            }
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", bX[i], bY[i], bX[minI], bY[minI], 16 + sqrt(pow(bX[i]-bX[minI],2)+pow(bY[i]-bY[minI],2)));
            i = minI;
            selSet |= (1<<i);
        }
        printf("Number of feet of cable required is %.2lf.\n", minTotC);
    }
    return 0;
}
