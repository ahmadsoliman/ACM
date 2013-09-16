#include <stdio.h>

int i,j, x, k, v[10], dp[100005];

int main(){
    scanf("%d", &x);
        scanf("%d", &k);
        for(i=0; i<k; i++){
            scanf("%d", &v[i]);
            if(i>0) v[i]+=v[i-1];
        }
        dp[0]=1;
        for(i=1; i<=x; i++){
            dp[i]=0;
            for(j=0; j<k; j++){
                if(i>=v[j] && dp[i-v[j]]==1) { dp[i] = 1 ; break; }
            }
        }
        if(dp[x]==1) printf("YES\n");
        else printf("NO\n");

    return 0;
}
