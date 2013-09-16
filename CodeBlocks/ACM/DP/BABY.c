#include <stdio.h>
#include <string.h>
#include <math.h>

#define INF 1000000000

int done, n, kase, dp[65600], visdp[65600], baby[20], board[20], grid[20][20];

int bfs(int bm, int node){
    for(i=0; i<n; i++){

    }
}

int recur(int bm){
    if(bm==done) return 0;
    if(visdp[bm]==kase) return dp[bm];
    int i, c, minc=INF;
    for(i=0; i<n; i++){
        if(!(bm&(1<<i))){
            c = bfs(bm, i);
            if(c<minc) minc=c;
        }
    }
    visdp=kase;
    return dp[bm]=minc;
}

int main(){
    int i,j;
    kase=1;
    while(scanf("%d", &n)>0){
        if(n==0) return 0;
        done = pow(2,n);
        for(i=0; i<n; i++) { scanf("%d", &baby[i]); };
        for(i=0; i<n; i++) { scanf("%d", &board[i]); };


        kase++;
    }
    return 0;
}
