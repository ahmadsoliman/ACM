#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int fields[2005], strips[2005], dp[150005], M, K;

int recur(int q){
    if(q==0) return 0;
    if(dp[q]>-1) return dp[q];

    int i, r, maxR = 0;
    for(i=0; i< M; i++){
        r = 0;
        if(fields[i]<=q)
            r = fields[i] + recur(q-fields[i]);
        else
            break;
        if(r>maxR) maxR = r;
    }
    for(i=0; i< K; i++){
        r = 0;
        if(strips[i]<=q)
            r = strips[i] - 1 + recur(q-strips[i]);
        else
            break;
        if(r>maxR) maxR = r;
    }

    return dp[q] = maxR;
}

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main(){
    int t, Q, i;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &Q, &M, &K);
        for(i=0; i<M; i++) scanf("%d", &fields[i]);
        for(i=0; i<K; i++) scanf("%d", &strips[i]);

        qsort(fields, M, sizeof(int), compare);
        qsort(strips, K, sizeof(int), compare);


        memset(dp, -1, sizeof dp);
        printf("%d\n", recur(Q));
    }
    return 0;
}
