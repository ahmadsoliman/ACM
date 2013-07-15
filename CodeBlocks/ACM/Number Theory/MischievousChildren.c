#include <stdio.h>
#include <string.h>

long long dp[21];
char s[25];
int counts[26];

int main(){
    int t,n,i,kase=1;
    long long res;
    for(i=1, dp[0]=1; i<21; i++){
        dp[i] = dp[i-1]*i;
    }
    scanf("%d", &t);
    while(t--) {
        scanf("%s", s);
        n = strlen(s);
        memset(counts, 0, sizeof counts);
        for(i=0; i<n; i++) counts[s[i]-'A']++;
        res = dp[n];
        for(i=0; i<26; i++) if(counts[i]>1) res/=dp[counts[i]];

        printf("Data set %d: %ld\n", kase++, res);
    }
    return 0;
}
