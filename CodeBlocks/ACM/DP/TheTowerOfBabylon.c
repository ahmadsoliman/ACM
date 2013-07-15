#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(x,y) ((x<y)?x:y)
#define max(x,y) ((x>y)?x:y)

typedef struct{
    int x,y,z;
} block;

int N;
long long dp[101][101];
block blocks[93];

int compare(const void *a, const void *b){
    return (*(block*)b).x * (*(block*)b).y - (*(block*)a).x * (*(block*)a).y;
}

long long recur(int i, int last){
    if(i==N) return 0;
    if(last>-1&&dp[i][last]!=-1)
        return dp[i][last];
    long long a=recur(i+1,last), b=0;
    if(last==-1||(blocks[last].x>blocks[i].x&&blocks[last].y>blocks[i].y)) b = blocks[i].z+recur(i+1,i);
    if(last>-1) dp[i][last] = max(a,b);
    return max(a,b);
}

int main(){
    int i, j, n,x,y,z,kase=1;
    while(scanf("%d", &n)>0){
        if(n==0) return 0;
        N=0;
        for(i=0; i<n; i++) {
            scanf("%d %d %d", &x, &y, &z);
            block b1,b2,b3;
            b1.z = z;
            b1.x = min(x,y);
            b1.y = max(x,y);

            b2.z = x;
            b2.x = min(y,z);
            b2.y = max(y,z);

            b3.z = y;
            b3.x = min(x,z);
            b3.y = max(x,z);

            blocks[N++] = b1;
            blocks[N++] = b2;
            blocks[N++] = b3;
        }
        qsort(blocks, N, sizeof(block), compare);

        memset(dp, -1, sizeof dp);
        printf("Case %d: maximum height = %ld\n", kase++, recur(0,-1));
    }
    return 0;
}
