#include <stdio.h>
#include <string.h>

#define min(x,y) ((x<y)?x:y)

char s1[2005], s2[2005];
int n1, n2, dp[2005][2005];

int recur(int i, int j){
    if(i==n1&&j==n2)
        return 0;
    if(i==n1)
        return n2-j;
    if(j==n2)
        return n1-i;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(s1[i]==s2[j]){
        int a=recur(i+1,j+1),b=1+recur(i+1, j),c=1+recur(i,j+1);
        return dp[i][j] = min(a,min(b,c));
    }else{
        int a=recur(i+1, j),b=recur(i,j+1), c=recur(i+1,j+1);
        return dp[i][j] = 1+min(a,min(b,c));
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%s", &s1);
        scanf("%s", &s2);
        n1 = strlen(s1);
        n2 = strlen(s2);
        memset(dp, -1, sizeof dp);
        printf("%d\n", recur(0,0));
    }
    return 0;
}
