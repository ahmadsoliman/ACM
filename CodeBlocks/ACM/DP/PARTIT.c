#include <stdio.h>

int t, m, n,k, i,j, cur, sum, temp,p, dp[222][11];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &m);
        scanf("%d", &n);
        scanf("%d", &k);

        dp[0][0]=1;
        for(i=1;i<221;++i)dp[i][0]=0;
        for(i=1;i<11;++i)dp[0][i]=0;
        for(i=1;i<221;++i)
        for(j=1;j<11 && j<=i;++j)
        dp[i][j]=dp[i-1][j-1]+dp[i-j][j];

        cur=0;
        sum=0;
        for(i=0,p=1;i<n;++i){
            temp=0;
            while(cur+dp[m-sum-p-(p-1)*(n-i-1)][n-i-1]+temp<k){
                temp+=dp[m-sum-p-(p-1)*(n-i-1)][n-i-1];
                p++;
            }
            printf("%d ",p);
            sum+=p;
            cur+=temp;
        }
        printf("\n");
    }
    return 0;
}
