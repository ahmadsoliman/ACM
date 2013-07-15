#include <stdio.h>
#include <string.h>

#define min(x,y) (x<y)?x:y

int n, dp[2005][1005];
char s[2005];

int recur(int i, int open){
    if(i==n && open==0) return 0;
    if(i==n || open>n/2) return 1000000000;
    if(dp[i][open]!=-1) return dp[i][open];

    if(open==0 && s[i]=='}') return dp[i][open] = 1+recur(i+1, open+1);
    if(open==0 && s[i]=='{') return dp[i][open] = recur(i+1, open+1);

    int a=recur(i+1, (s[i]=='{')?open+1:open-1),
        b=1+recur(i+1, (s[i]=='}')?open+1:open-1);
    return dp[i][open] = min(a,b);
}

int main(){
    int kase=1;
    while(1){
        gets(s);
        if(s[0]=='-') break;
        n=strlen(s);
        while(s[n]!='{'&&s[n]!='}')n--;
        n++;
        memset(dp, -1, sizeof dp);
        printf("%d. %d\n", kase++, recur(0, 0));
    }
    return 0;
}
