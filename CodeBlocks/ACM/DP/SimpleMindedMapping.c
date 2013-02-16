#include <stdio.h>
#include <string.h>

int dp[30][360][30];

int recur(int l, int s, int prev){
    if(s<0)
        return 0;
    if(l==0){
        if(s==0)
            return 1;
        return 0;
    }
    if(dp[l][s][prev]>-1)
        return dp[l][s][prev];
    int sum=0,i;
    for(i=prev+1; i<=26; i++){
        sum+=recur(l-1, s-i, i);
    }
    return (dp[l][s][prev]=sum);
}

int main(){
    int L, S, t=1;
    while(scanf("%d %d", &L, &S)>0){
        if(L==0 && S==0)
            break;
        memset(dp, -1, sizeof dp);
        if(L>26)
            printf("Case %d: %d\n", t++ ,0);
        else
            printf("Case %d: %d\n", t++ ,recur(L,S,0));
    }
    return 0;
}
