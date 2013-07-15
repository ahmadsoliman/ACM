#include <stdio.h>
#include <string.h>

int coins[] = {1, 5, 10, 25, 50};

long long dp[10000][6];

long long countR(int n, int last){
    if(n==0)
        return 1;
    if(last==5)
        return 0;

    if(dp[n][last]>-1)
        return dp[n][last];

    long long c;
    if(n>=coins[last])
        c = countR(n-coins[last], last);
    else
        return 0;

    c+=countR(n, last+1);

    return dp[n][last] = c;
}

int main(){
    int n, i;
    memset(dp, -1, sizeof dp);
    while(scanf("%d", &n)>0){
        if(n==0)
            break;

        printf("%ld\n", countR(n, 0));
    }
    return 0;
}
