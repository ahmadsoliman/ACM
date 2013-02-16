#include <stdio.h>

int values[100005], colors[100005];
long long dp[100005];

int main(){
    int n, q, i, a, b, j, k;
    long long maxV=0ll, tmp=0ll, maxMax=0ll;
    scanf("%d %d", &n, &q);
    for(i=0; i<n; i++){
        scanf("%d", &values[i]);
    }
    for(i=0; i<n; i++){
        scanf("%d", &colors[i]);
    }
    for(i=0; i<q; i++){
        scanf("%d %d", &a, &b);
        maxMax=0ll;
        dp[0]=values[0]*b;

        for(j=1; j<n; j++){
            maxV=0ll;
            for(k=0; k<j; k++){
                if(colors[j]==colors[k]){//a
                    tmp = dp[k]+values[j]*a;
                    if(tmp>maxV)
                        maxV=tmp;
                }else{
                    tmp = dp[k]+values[j]*b;
                    if(tmp>maxV)
                        maxV=tmp;
                }
            }
            dp[j]=maxV;
            if(maxV>maxMax)
                maxMax=maxV;
        }
        if(maxMax>0)
            printf("%I64d\n", maxMax);
        else
            printf("%d\n", 0);
    }
    return 0;
}
