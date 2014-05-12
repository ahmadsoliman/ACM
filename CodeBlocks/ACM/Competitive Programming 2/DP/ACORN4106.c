#include <stdio.h>
#include <string.h>
#include <math.h>

#define max(x,y) ((x>y)?x:y)

int acorn[2005][2005], dp[2005];

int main(){
    int c, t,h,f, i,j,k, ha;
    scanf("%d", &c);
    while(c--){
        scanf("%d %d %d", &t, &h, &f);
        memset(acorn, 0, sizeof acorn);
        for(i=0; i<t; i++){
            scanf("%d", &k);
            for(j=0; j<k; j++) {
                scanf("%d", &ha);
                acorn[i][ha]++;
            }
        }
        memset(dp, 0, sizeof dp);
        for(i=0; i<t; i++) dp[h]=max(dp[h], acorn[i][h]);
        for(i=h-1; i>=0; i--){
            for(j=0; j<t; j++){
                acorn[j][i]+=max(acorn[j][i+1], ((i+f<=h)?dp[i+f]:0));
                dp[i]=max(dp[i], acorn[j][i]);
            }
        }
        printf("%d\n", dp[0]);
    }
    return 0;
}
