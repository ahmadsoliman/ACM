#include <stdio.h>
#include <string.h>

#define INF 1000000000
int n1,n2, dp[1001][1001], pos[26][1001], counts[26];
char s1[1001], s2[1001];

int recur(int i, int j){
    if(i==n1)
        return INF;

    if(dp[i][j]!=-1)
        return dp[i][j];

    int k;
    for(k=0; k<counts[s1[i]-'a']; k++) if(pos[s1[i]-'a'][k]>=j) break;

    if(k==counts[s1[i]-'a'])//not found
        return dp[i][j] = 1;

    int a=1+recur(i+1, pos[s1[i]-'a'][k]+1), b=recur(i+1,j);
    return dp[i][j] = (a<b)?a:b;
}

int main(){
    scanf("%s", s1);
    scanf("%s", s2);
    n1 = strlen(s1);
    n2 = strlen(s2);
    memset(counts, 0, sizeof counts);
    memset(pos, -1, sizeof pos);
    int i;
    for(i=0; i<n2; i++) pos[s2[i]-'a'][counts[s2[i]-'a']++] = i;
    memset(dp, -1, sizeof dp);
    printf("%d\n", recur(0,0));
    return 0;
}
