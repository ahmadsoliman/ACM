#include <stdio.h>
#include <string.h>

int dp[1005][1005], cuts[55], n;

int cut(int start, int endS){
    if(start==endS)
        return 0;
    if(dp[start][endS]>-1)
        return dp[start][endS];
    int i, minCut=1000000000, curMin;
    for(i=0; i<n; i++){
        if(cuts[i]>start&&cuts[i]<endS){
            curMin= endS-start + cut(start,cuts[i]) + cut(cuts[i], endS);
            if(curMin<minCut)
                minCut = curMin;
        }
    }
    if(minCut==1000000000)
        minCut=0;
    return dp[start][endS]=minCut;
}

int main(){
    int l, i,j,k, last;
    while(scanf("%d", &l)>0){
        if(l==0)
            break;
        memset(dp, -1, sizeof dp);
        scanf("%d", &n);
        last=0;
        for(i=0; i<n; i++){
            scanf("%d", &cuts[i]);
            for(j=last; j<cuts[i]; j++)
                for(k=j; k<cuts[i]; k++)
                    dp[j][j]=0;
            last=cuts[i]+1;
        }
        printf("The minimum cutting is %d.\n", cut(0,l));
    }
}
