#include <stdio.h>
#include <string.h>

int K, L, dp[1000001][2];

int recur(int N, int turn){
    if(N==0) return turn;
    if(dp[N][turn]!=-1)
        return dp[N][turn];
    if(turn) return dp[N][turn] = ((N>=L)?recur(N-L, !turn):1)&&((N>=K)?recur(N-K, !turn):1)&&recur(N-1, !turn);
    return dp[N][turn] = ((N>=L)?recur(N-L, !turn):0)||((N>=K)?recur(N-K, !turn):0)||recur(N-1, !turn);
}

int main(){
    int m, i, c;
    scanf("%d %d %d", &K, &L, &m);
    memset(dp, -1, sizeof dp);
    while(m--){
        scanf("%d", &c);
        if(recur(c, 0)) printf("A");
        else printf("B");
    }
    printf("\n");
    return 0;
}
