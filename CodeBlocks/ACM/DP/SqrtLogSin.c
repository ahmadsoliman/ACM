#include <stdio.h>
#include <math.h>

int dp[1000005];

int main(){
    int i;
    double tmp;
    dp[0]=1;
    for(i=1; i<1000001; i++){
        tmp = sin(i);
        dp[i]=((dp[(int)(i-sqrt(i))]+dp[(int)log(i)])%1000000+dp[(int)(i*tmp*tmp)])%1000000;
    }
    while(scanf("%d", &i)>0){
        if(i==-1)
            break;
        printf("%d\n", dp[i]);
    }
    return 0;
}
