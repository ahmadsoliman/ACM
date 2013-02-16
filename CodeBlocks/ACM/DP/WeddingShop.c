#include <stdio.h>
#include <string.h>

int prices[25][25], dp[205][25], num_of_items[25], M, C;

int recur(int m, int c){
    if(m<0)
        return 0;
    if(c==C)
        return M-m;
    if(dp[m][c]>-1)
        return dp[m][c];

    int i, maxM=0, curM;
    for(i=0; i<num_of_items[c]; i++){
        if((curM=recur(m-prices[c][i],c+1))>maxM)
            maxM=curM;
    }
    return dp[m][c]=maxM;
}

int main(){
    int t, K, i, j;
    scanf("%d", &t);
    while(t--){
        memset(dp, -1, sizeof dp);

        scanf("%d %d", &M, &C);
        for(i=0; i<C; i++){
            scanf("%d", &K);
            num_of_items[i] = K;
            for(j=0; j<K; j++)
                scanf("%d", &prices[i][j]);
        }
        int money = recur(M, 0);
        if(money==0)
            printf("no solution\n");
        else
            printf("%d\n", money);

    }
    return 0;
}
