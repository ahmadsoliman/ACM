#include <stdio.h>
#include <string.h>

int dp[13][99];

int recur(int n, int k){
    if(k==0) return 1;
    if(k==1) return n-1;
    if(n==0) return 0;
    for()
}

int main(){
    int t,n,k;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n,&k);
        printf("%d\n", recur(n,k));
    }
    return 0;
}
