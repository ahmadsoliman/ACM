#include <stdio.h>
#include <string.h>

int coins[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

long long dp[6001][11];

long long countR(int n, int last){
    if(n==0)
        return 1;
    if(last==11)
        return 0;

    if(dp[n][last]>-1)
        return dp[n][last];

    long long c;
    if(n*5>=coins[last])
        c = countR(n-coins[last]/5, last);
    else
        return 0;

    c+=countR(n, last+1);

    return dp[n][last] = c;
}

int main(){
    double n;
    int i;
    memset(dp, -1, sizeof dp);
    while(scanf("%lf", &n)>0){
        if(n==0)
            break;


        if(n<10) printf("  ");
        else if(n<100) printf(" ");
        printf("%.2lf", n);

        long long r = countR(n*20, 0), tmp1 = r;
        int digits = 0;
        while(tmp1>0&&++digits) tmp1/=10;
        for(i=0; i<17-digits; i++) printf(" ");
        printf("%ld\n", r);
    }
    return 0;
}
