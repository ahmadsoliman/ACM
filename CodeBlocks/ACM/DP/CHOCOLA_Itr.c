#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define min(x,y) ((x<y)?x:y)

int hCuts[1005], vCuts[1005], m, n, dp[1001][1001];

int compare (const void * a, const void * b)
{
  return ( *(int*)b - *(int*)a );
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

        qsort(vCuts, m, sizeof(int), compare);
        qsort(hCuts, n, sizeof(int), compare);

        for(i=1; i<=m; i++)
            dp[i][0] = dp[i-1][0] + vCuts[i-1];

        for(i=1; i<=n; i++)
            dp[0][i] = dp[0][i-1] + hCuts[i-1];

        for(i=1; i<=m; i++){
            for(j=1; j<=n; j++){
                //if(i==m&&j==n)
                  //    dp[i][j] = min((i+1)*hCuts[j-1]+dp[i][j-1], (j+1)*vCuts[i-1]+dp[i-1][j]);
                if(i==m)
                    dp[i][j] = i*hCuts[j-1] + dp[i][j-1];
                else if(j==n)
                    dp[i][j] = j*vCuts[i-1] + dp[i-1][j];
                else
                    dp[i][j] = min(i*hCuts[j-1]+dp[i][j-1], j*vCuts[i-1]+dp[i-1][j]);
            }
        }

        for(i=0; i<=m; i++){
            for(j=0; j<=n; j++){
                printf("%d ", dp[i][j]);
            }
            printf("\n");
        }

        printf("%d\n", dp[m][n]);
    }
    return 0;
}
