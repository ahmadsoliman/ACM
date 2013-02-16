#include <stdio.h>
#include <string.h>

int n, time[55][55], toll[55][55], dp[55][1005], dir[55][1005];

int recur(int i, int t){
    if(t<0)return 2100000000;
    if(i==n-1)return 0;
    if(dp[i][t]>-1)return dp[i][t];

    int j, curToll, minToll=2100000000, minJ=-1;
    for(j=0; j<n; j++){
        if(i==j)continue;
        curToll = recur(j, t-time[i][j]) + toll[i][j];
        if(curToll<minToll){
            minToll=curToll;
            minJ=j;
        }
    }
    dir[i][t]=minJ;
    return dp[i][t] = minToll;
}

int main(){
    int t, tmpT, i, j, totTime, tmpI;
    while(scanf("%d %d", &n, &t)>0){
        if(n==0&&t==0)break;

        memset(dp, -1 , sizeof dp);
        memset(dir, -1 , sizeof dir);
        for(i=0; i<n; i++)for(j=0; j<n; j++)scanf("%d", &time[i][j]);
        for(i=0; i<n; i++)for(j=0; j<n; j++)scanf("%d", &toll[i][j]);

        recur(0,t);
        totTime=0;
        j=t;
        i=0;
        while(1){
            totTime += time[i][dir[i][j]];
            tmpI=i;
            i = dir[i][j];
            j -= time[tmpI][dir[tmpI][j]];
            if(i==n-1)break;
        }
        printf("%d %d\n", dp[0][t], totTime);
    }
    return 0;
}
