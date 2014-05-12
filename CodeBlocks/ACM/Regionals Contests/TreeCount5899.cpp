#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int dp[2000][100];

#define MOD 1000000000

int recur(int n, int h){
    if(n==0) return h==0;
    if(n==1) return h==1;
    if(h<0) return 0;

    if(dp[n][h]!=-1) return dp[n][h];

    long long sum = 0;
    for(int i=0; i<n; i++){
        sum = (sum+ (long long)(recur(i, h-1)%MOD) * (recur(n-i-1, h-1) %MOD) % MOD)%MOD;
        if(h>1){
            sum = (sum+ (long long)(recur(i, h-1)%MOD) * (recur(n-i-1, h-2) %MOD) % MOD)%MOD;
            sum = (sum+ (long long)(recur(i, h-2)%MOD) * (recur(n-i-1, h-1) %MOD) % MOD)%MOD;
        }
    }

    return dp[n][h]=sum%MOD;
}

int main(){
    int n, i,j,k, h;
    long long sum;
    memset(dp, -1, sizeof dp);
    while(scanf("%d", &n)>0){
        sum=0;
        h=ceil(log(n)/log(2))+1;
        for(i=1; i<=h; i++){
            sum=(sum+recur(n,i))%MOD;
        }
        printf("%09d\n", sum);
    }
    return 0;
}
