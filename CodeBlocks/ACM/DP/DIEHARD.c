#include <stdio.h>
#include <string.h>

#define max(x,y) ((x>y)?x:y)

int dp[5001][5001][3];

int recur(int h, int a, int last){
    if(last!=-1 && dp[h][a][last]!=-1)
        return dp[h][a][last];
    int b=0,c=0,d=0;
    if(last!=0) b=1+recur(h+3, a+2, 0);
    if(last!=1 && h>5 && a>10) c=1+recur(h-5, a-10, 1);
    if(last!=2 && h>20) d=1+recur(h-20, a+5, 2);
    return dp[h][a][last] = max(b,max(c,d));
}

int main(){
    int t, H, A;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &H, &A);
        memset(dp, -1, sizeof dp);
        printf("%d\n", recur(H, A, -1));
    }
    return 0;
}
