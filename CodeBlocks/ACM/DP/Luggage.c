#include <stdio.h>
#include <string.h>

int n, suits[21], dp[21][205][205];

int recur(int i, int a, int b){
    if(i==n){
        if(a==b)
            return 1;
        return 0;
    }
    if(dp[i][a][b]!=-1)
        return dp[i][a][b];
    return dp[i][a][b] = recur(i+1, a+suits[i], b) || recur(i+1, a, b+suits[i]);
}

char in[10000];
char * comp;

int main(){
    int t, i, res;
    gets(in);
    sscanf(in, "%d", &t);
    while(t--){
        gets(in);
        comp = strtok(in," ");
        n=0;
        while(comp != NULL){
            sscanf(comp, "%d", &suits[n++]);
            comp = strtok(NULL, " ");
        }
        memset(dp, -1, sizeof dp);
        res = recur(0,0,0);
        if(res)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
