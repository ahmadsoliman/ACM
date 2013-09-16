#include <stdio.h>
#include <string.h>
#include <math.h>

unsigned long long dp[1000][1000];

unsigned long long recur(int n, int k){
    if(k==0){
		if(n==0) return 1;
		else return 0;
	} else if(k==1) {
		if(n>6) return 0;
		else if(n<=0) return 0;
		else return 1;
	}else if(n<=0) return 0;
    if(dp[n][k]!=-1)
        return dp[n][k];
    int i;
    unsigned long long c=0;
    for(i=1; i<=6 && k-i>=0; i++) c+= recur(n-1, k-i);
    return dp[n][k]=c;
}

int main(){
    int t, n, k;
    scanf("%d", &t);
    memset(dp, -1, sizeof dp);
    while(t--){
        scanf("%d %d", &n, &k);
        if(n<1000 && k<1000) {
            printf("%llu\n", (unsigned long long)(recur(n, k)/pow(6,n)*100.0));
        } else printf("0\n");
    }
    return 0;
}

