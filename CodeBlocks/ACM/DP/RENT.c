#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x,y, c;
} pair;

int t, n, a,b,c, i,j,k, comp, dp[10005], endIndex[20005],starts[20005], latestS, maxV;
pair points[20005], pairs[10005], p1,p2,p3;

int compare (const void * a, const void * b){
    comp = (*(pair*)a).x - (*(pair*)b).x;
    return (comp==0)?((*(pair*)a).y - (*(pair*)b).y):comp;
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i=0; i<n; i++){
            scanf("%d %d %d", &a, &b, &c);
            b+=a;
            p1.x = a;p1.y = b;p1.c = c;
            pairs[i] = p1;
            p2.x = a;p2.y = 1;
            points[2*i] = p2;
            p3.x = b;p3.y = 0;
            points[2*i+1] = p3;
        }
        qsort(pairs, n, sizeof(pair), compare);
        qsort(points, 2*n, sizeof(pair), compare);

        latestS=-1;
        for(i=2*n-1, j=n-1, k=n-1; i>=0; i--){
            if(points[i].y==1) { latestS=i; starts[i]=k--; }
            else endIndex[j--]=latestS;
            printf("%d:%d:%d ", points[i].x, points[i].y, starts[endIndex[j+1]]);
        }
        dp[n]=0;maxV=-1;
        for(i=n-1; i>=0; i--){
            if(endIndex[i]==-1) dp[i]=pairs[i].c;
            else dp[i]=pairs[i].c+dp[starts[endIndex[i]]];
            if(dp[i]>maxV) maxV=dp[i];
        }
        printf("%d\n", maxV);
    }
    return 0;
}
