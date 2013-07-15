#include <stdio.h>

long long dp[15];

int main(){
    int i, n;

    dp[1]=1;
    for(i=2; i<14; i++)dp[i]=dp[i-1]*i;

    while(scanf("%d", &n)>0){
        if(n<0){
            if(n%2)
                printf("Overflow!\n");
            else
                printf("Underflow!\n");
        }else if(n>13)
            printf("Overflow!\n");
        else if(n<8)
            printf("Underflow!\n");
        else
            printf("%ld\n", dp[n]);
    }

    return 0;
}
