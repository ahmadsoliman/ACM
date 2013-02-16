#include <stdio.h>
#include <string.h>

int dp[105][105][105][105], map[105][105];

int main(){
    int t,s,b, r1,c1,r2,c2, i, j, k, l, column, row, maxArea, area;
    memset(dp, 1, sizeof dp);
    scanf("%d", &t);
    while(t--){
        memset(map, 0, sizeof map);
        scanf("%d", &s);
        scanf("%d", &b);
        for(k=0; k<b; k++){
            scanf("%d %d %d %d",  &r1,&c1,&r2,&c2);
            r1--;c1--;r2--;c2--;
            for(i=r1; i<=r2; i++){
                for(j=c1; j<=c2; j++){
                    map[i][j]=1;
                }
            }
        }

        maxArea=0;
        for(i=1; i<=s; i++){
            for(k=0; k<i; k++){
                for(j=1; j<=s; j++){
                    for(l=0; l<j; l++){
                        dp[i][k][j][l] = dp[i-1][k][j][l] & dp[i][k][j-1][l] & !map[i-1][j-1];
                        area = (i-k)*(j-l);
                        if(dp[i][k][j][l] && area>maxArea)
                            maxArea=area;
                    }
                }
            }
        }
        printf("%d\n", maxArea);
    }
    return 0;
}
