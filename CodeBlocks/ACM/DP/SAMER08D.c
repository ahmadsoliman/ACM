#include <stdio.h>
#include <string.h>

int k, dp[1005][1005], n1, n2;
char s1[1005], s2[1005];

int recur(int i, int j){
    if(i==n1 || j==n2)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];

    int a=recur(i+1,j), b=recur(i, j+1), c=0, cur;
    int l;
    for(l=0; l+i<n1 && l+j<n2; l++){
        if(s1[i+l]!=s2[j+l])
            break;
        if(l+1>=k){
            cur =  l+1 + recur(i+l+1, j+l+1);
            if(cur>c)
                c = cur;
        }
    }
    return dp[i][j] = ((a>b)?((a>c)?a:c):((b>c)?b:c));
}

int main(){
    while(scanf("%d", &k)>0){
        if(k==0)
            break;
        scanf("%s", s1);
        scanf("%s", s2);
        n1 = strlen(s1);
        n2 = strlen(s2);

        memset(dp, -1, sizeof dp);
        printf("%d\n", recur(0,0));
    }
    return 0;
}
