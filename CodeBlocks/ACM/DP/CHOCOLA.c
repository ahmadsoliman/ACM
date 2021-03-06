#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define min(x,y) ((x<y)?x:y)

int hCuts[1005], vCuts[1005], m, n, dp[1001][1001];

int compare (const void * a, const void * b)
{
  return ( *(int*)b - *(int*)a );
}

int recur(int i, int j){
    if(i==m && j==n)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    if(i==m)
        return dp[i][j] = (m+1)*hCuts[j] + recur(i, j+1);

    if(j==n)
        return dp[i][j] = (n+1)*vCuts[i] + recur(i+1, j);

    return dp[i][j] = min((i+1)*hCuts[j]+recur(i, j+1), (j+1)*vCuts[i]+recur(i+1, j));
}

int main(){
    int t, i, j;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &m, &n);
        m--;
        n--;
        for(i=0; i<m; i++)
            scanf("%d",&vCuts[i]);
        for(i=0; i<n; i++)
            scanf("%d",&hCuts[i]);

        memset(dp, -1, sizeof dp);

        qsort(vCuts, m, sizeof(int), compare);
        qsort(hCuts, n, sizeof(int), compare);

        printf("%d\n", recur(0,0));

        for(i=m; i>=0; i--){
            for(j=n; j>=0; j--){
                printf("%d ", dp[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
