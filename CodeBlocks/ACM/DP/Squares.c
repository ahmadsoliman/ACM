#include <stdio.h>
#include <math.h>

#define min(x,y) ((x<y)?x:y)

int dp[10001];

int main(){
    int i, j, t, N, sqrtN, minN, halfN;
    dp[1]=1;dp[2]=2;
    for(i=3; i<10001; i++){
        sqrtN = ceil(sqrt(i));
        if(i==sqrtN*sqrtN){
            dp[i]=1;
            continue;
        }
        minN=i;
        halfN=i/2;
        for(j=1; j<=halfN; j++)
            minN=min(minN, dp[j]+dp[i-j]);
        dp[i]=minN;
    }

    scanf("%d", &t);
    while(t--){
        scanf("%d", &N);
        printf("%d\n", dp[N]);
    }
    return 0;
}
