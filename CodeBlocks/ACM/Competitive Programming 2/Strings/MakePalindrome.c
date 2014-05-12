#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define min(x,y) ((x<y)?x:y)

char s[1005];
int dp[1005][1005], len, vis[1005][1005], kase;

int recur(int i, int j){
    if(vis[i][j]==kase) return dp[i][j];
    if(i>=j) return dp[i][j]=0;

    int o1,o2,o3,o4;
    o1=o2=o3=1000000000;
    if(s[i]==s[j]) o1=recur(i+1, j-1);
    o2 = 1+recur(i+1, j);
    o3 = 1+recur(i, j-1);

    vis[i][j]=kase;
    return dp[i][j]=min(min(o1,o2), o3);
}

int newlen, latei, latej;
char res[2005];

void rec(int i, int j){
    if(i==j) res[latei]=s[i];
    if(i>=j) return;

    int o1,o2,o3,o4;
    o1=o2=o3=1000000000;
    if(s[i]==s[j]) o1=dp[i+1][j-1];
    o2 = 1+dp[i+1][j];
    o3 = 1+dp[i][j-1];

    if(o1<=o2 && o1<=o3){
        res[latei++]=s[i];
        res[latej--]=s[j];
        rec(i+1, j-1);
    }else if(o2<=o1 && o2<=o3){
        res[latei++]=s[i];
        res[latej--]=s[i];
        rec(i+1, j);
    }else if(o3<=o1 && o3<=o2){
        res[latei++]=s[j];
        res[latej--]=s[j];
        rec(i, j-1);
    }
}

int main(){
    int t, i,j,k;
    kase=1;
    while(scanf("%s", s)>0){
        len = strlen(s);
        printf("%d ", recur(0, len-1));
        newlen=len+dp[0][len-1];
        latei=0, latej=newlen-1;
        rec(0, len-1);
        res[newlen]='\0';
        printf("%s\n", res);
        kase++;
    }
    return 0;
}
