#include <stdio.h>
#include <string.h>

#define max(x,y) ((x>y)?x:y)

int n, orig[22], student[22], dp[22][22];

int recur(int i, int last){
    if(i==n+1)
        return 0;
    if(dp[i][last]!=-1)
        return dp[i][last];
    int a = recur(i+1, last), b = -1;
    if(student[i]>student[last])
        b = 1+recur(i+1, i);
    return dp[i][last] = max(a,b);
}

int main(){
    int i, c;
    scanf("%d", &n);
    for(i=1; i<=n; i++) {
        scanf("%d", &c);
        orig[i]=c;
    }
    while(scanf("%d", &c)>0){
        student[0] = -1;
        student[c] = orig[1];
        for(i=2; i<=n; i++) {
            scanf("%d", &c);
            student[c] = orig[i];
        }

        memset(dp, -1, sizeof dp);
        printf("%d\n", recur(0,0));

    }
}
