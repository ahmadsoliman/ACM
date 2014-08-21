#include <stdio.h>

#define max(x,y) ((x>y?x:y))

int arr[2005], tom[2005], dp[2005][2005];

int main(){
    int t, i, j, n, m, maxV;
    scanf("%d", &t);
    while(t--){
        for(i=0; ;i++) {
            scanf("%d", &arr[i]);
            if(arr[i]==0) break;
        }
        n=i;
        maxV=0;
        while(1){
            for(i=0; ;i++) {
                scanf("%d", &tom[i]);
                if(tom[i]==0) break;
            }
            m=i;
            if(m==0) break;

            for(i=0; i<n ;i++) dp[i][m] = 0;
            for(i=0; i<m ;i++) dp[n][i] = 0;

            for(i=n-1; i>=0; i--){
                for(j=m-1; j>=0; j--){
                    int a=0,b=dp[i+1][j],c=dp[i][j+1];
                    if(arr[i]==tom[j])
                        a = 1+dp[i+1][j+1];
                    dp[i][j] = max(a,max(b,c));
                }
            }
            if(maxV<dp[0][0]) maxV=dp[0][0];
        }
        printf("%d\n", maxV);
    }
    return 0;
}
