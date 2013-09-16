#include <stdio.h>
#include <stdlib.h>

#define MOD 100000000

typedef struct{
    int x, type, i;
} point;

point points[200010], p1,p2;
int n, dp[100010], ends[200010],nextS[200010], i,j,k, last,summed, latestS, comp;


int compare (const void * a, const void * b){
    comp = (*(point*)a).x - (*(point*)b).x;
    return (comp==0)?((*(point*)a).type - (*(point*)b).type):comp;
}

int main(){
    while(scanf("%d", &n)>0){
        if(n==-1)
            break;
        for(i=0; i<n; i++){
            scanf("%d %d", &j, &k);
            p1.x = j;
            p1.type = 1;
            p1.i=i;
            points[2*i] = p1;
            p2.x = k;
            p2.type = 0;
            p2.i=i;
            points[2*i+1] = p2;
        }
        qsort(points, 2*n, sizeof(point), compare);

        //for(i=0; i<2*n; i++) printf("%d:%d ", points[i].x, points[i].type);

        latestS=-1;
        dp[2*n]=0;summed=0;
        for(i=2*n-1; i>=0; i--){
            if(points[i].type==0){
                nextS[i]=latestS;
                if(nextS[i]!=-1){
                    dp[i]=(1+dp[nextS[i]])%MOD;
                    summed+=dp[i];
                } else
                    dp[i]=1;
                last=i;
            }else{
                latestS=i;
                dp[i]=dp[last];
            }
            printf("%d:%d:%d ", points[i].x, points[i].type, dp[i]);
        }

        printf("%08d\n", summed);
    }
    return 0;
}
