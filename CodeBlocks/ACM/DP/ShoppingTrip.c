#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define min(x,y) ((x<y)?x:y)
#define INF 1000000000

int n, twoPowN, operas[15];
int graph[55][55], costs[15], dp[15][8192];

int recur(int i, int selSet){
    if(selSet==twoPowN)
        return -1*graph[operas[i]][0];

    if(dp[i][selSet]!=INF)
        return dp[i][selSet];

    int j, curC, maxC=-1*INF, k,tmp;
    for(j=1; j<n; j++){
        if(i!=j && operas[i]!=operas[j] && !(selSet & (1<<j))){
            curC=0;
            for(k=0, tmp=selSet; k<n; k++){
                if(operas[j]==operas[k] && !(tmp & (1<<k))){
                    curC += costs[k];
                    tmp |= (1<<k);
                }
            }
            curC += -1*graph[operas[i]][operas[j]] + recur(j, tmp);
            if(curC>maxC)
                maxC = curC;
        }
    }
    curC = -1*graph[operas[i]][0];
    if(curC>maxC)
        maxC = curC;
    return dp[i][selSet] = maxC;
}

int main(){
    int t, i, j, k, N, M, h1,h2, res;
    double c;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &N, &M);
        N++;
        for(i=0; i<N; i++)
            for(j=0; j<N; j++)
                graph[i][j]=INF;
        for(i=0; i<M; i++) {
            scanf("%d %d %lf", &h1, &h2, &c);
            c = c*100+1e-9;
            if((int)c<graph[h1][h2]){
                graph[h1][h2] = (int)c;
                graph[h2][h1] = (int)c;
            }
        }

        for(k=0; k<N; k++)
            for(i=0; i<N; i++)
                for(j=0; j<N; j++)
                    graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);

         /*for(i=0; i<N; i++){
            for(j=0; j<N; j++){
                printf("%d ", graph[i][j]);
            }
            printf("\n");
         }*/


        scanf("%d", &n);
        n++;
        twoPowN = pow(2,n)-1;

        operas[0] = 0;
        costs[0] = 0;
        for(i=1; i<n; i++) {
            scanf("%d %lf", &operas[i], &c);
            costs[i] = (int)(c*100+1e-9);
        }

        for(i=0; i<=n; i++)
            for(j=0; j<=twoPowN; j++)
                dp[i][j] = INF;

        res = recur(0,1);

        if(res>0)
            printf("Daniel can save $%.2lf\n", ((double)res/100.0+1e-9));
        else
            printf("Don't leave the house\n");
    }
    return 0;
}
