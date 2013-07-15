#include <stdio.h>
#include <string.h>

#define min(x,y) ((x<y)?x:y)

int gcd(int m, int n){
    if(m==0)return n;
    return gcd(n%m, m);
}

int n, coins[51], dp[51][4];

int recur(int i, int leg){
    if(leg==0)
        return 1;
    if(i==n)
        return 1000000000;
    if(dp[i][leg]!=-1)
        return dp[i][leg];
    int a=recur(i+1, leg), b=recur(i+1, leg-1);
    if(b<1000000000) b = coins[i]*(b/gcd(coins[i],b));
    if(a==1)
        a = 1000000000;
    return dp[i][leg] = min(a,b);
}

int main(){
    int t, i, lcm, cur;
    double div;
    while(scanf("%d %d", &n, &t)){
        if(n==0&&t==0)
            break;
        memset(dp, -1, sizeof dp);
        for(i=0; i<n; i++){
            scanf("%d", &coins[i]);
        }
        lcm = recur(0, 4);
        //printf("LCM: %d\n", lcm);
        for(i=0; i<t; i++){
            scanf("%d", &cur);
            div = 1.0*cur/lcm;
            if(cur%lcm==0){
                printf("%d %d\n", cur, cur);
            }else{
                printf("%d %d\n", (int)div*lcm, ((int)div+1)*lcm);
            }
        }
    }
    return 0;
}
