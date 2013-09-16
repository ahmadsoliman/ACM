#include <stdio.h>

int n, dp[1000010][5][5];

int main(){
    int i, t, j, k, l, col1, col2;

    for(i=0; i<2; i++){
        for(j=3; j>=0; j--){
            for(k=3; k>=0; k--){
                dp[i][j][k]=1;
            }
        }
    }
    for(i=2; i<1000002; i++){
        for(j=3; j>=0; j--){
            for(k=3; k>=0; k--){
                n=i; col1=j; col2=k;


            }
        }
    }

    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%d\n", dp[n][0][0]);
    }
    return 0;
}
