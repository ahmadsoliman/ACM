#include <stdio.h>
#include <string.h>
#define INF (2000000000)

int P[505],W[505], dp[10005], N;

int recur(int C){
    if(C==0)
        return 0;
    if(C<0)
        return -1;
    if(dp[C]>-1)
        return dp[C];
    int minV=INF, curV, i;
    for(i=0; i<N; i++){
        curV=recur(C-W[i]);
        if(curV==-1)continue;
        curV+=P[i];
        if(curV<minV)
            minV=curV;
    }
    return dp[C]=minV;
}

int main(){
    int t,E,F,i,V;
    scanf("%d", &t);
    while(t--){
        memset(dp, -1, sizeof dp);

        scanf("%d %d", &E, &F);
        scanf("%d", &N);
        for(i=0; i<N; i++){
            scanf("%d %d", &P[i], &W[i]);
        }
        V=recur(F-E);
        if(V<INF)
            printf("The minimum amount of money in the piggy-bank is %d.\n", V);
        else
            printf("This is impossible.\n");
    }
    return 0;
}
