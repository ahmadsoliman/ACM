#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INF 1000000000

int done, n, kase, dp[18][65600], visdp[18][65600];

int len[20][20];

int recur(int cur, int bm){
    if(cur==n) return 0;
    if(visdp[cur][bm]==kase) return dp[cur][bm];
    int i, c, minc=INF;
    for(i=0; i<n; i++){
        if(!(bm&(1<<i))){
            c = len[cur][i]+recur(cur+1, bm|(1<<i));
            if(c<minc) minc=c;
        }
    }
    visdp[cur][bm]=kase;
    return dp[cur][bm]=minc;
}

int babyx[18], babyy[18], boardx[18], boardy[18];

int main(){
    int i,j, tmp;
    kase=1;
    while(scanf("%d", &n)>0){
        if(n==0) return 0;

        for(i=0; i<n; i++) { scanf("%d", &tmp); babyx[i]=i; babyy[i]=tmp-1; };
        for(i=0; i<n; i++) { scanf("%d", &tmp); boardx[i]=i; boardy[i]=tmp-1; };

        for(i=0; i<n; i++) for(j=0; j<n; j++) len[i][j]=abs(babyx[i]-boardx[j])+abs(babyy[i]-boardy[j]);

        printf("%d\n", recur(0, 0));
        kase++;
    }
    return 0;
}
