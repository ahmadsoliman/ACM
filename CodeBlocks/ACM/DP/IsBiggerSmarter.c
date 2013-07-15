#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max(x,y) ((x>y)?x:y)

typedef struct {
    int w, iq, i;
}elef;

int compare (const void * a, const void * b)
{
  return ( (*(elef*)a).w - (*(elef*)b).w );
}

int n, dp[1005][1005];
elef elefs[1005];

int recur(int i, int last){
    if(i==n)
        return 0;

    if(dp[i][last]!=-1)
        return dp[i][last];

    int a = recur(i+1, last), b = 0;
    if(elefs[i].w>elefs[last].w&&elefs[i].iq<elefs[last].iq)
        b = 1+recur(i+1, i);

    return dp[i][last] = max(a,b);
}

int main(){
    n=1;
    int c, i, j, last, w, iq;

    //int t;
    //scanf("%d", &t);
    while(scanf("%d %d", &w, &iq)>0){//t-- &&
        elefs[n].w = w;
        elefs[n].iq = iq;
        elefs[n].i = n;
        n++;
    }
    elefs[0].w = -1;
    elefs[0].iq = 2000000000;
    elefs[0].w = 0;
    qsort (elefs, n, sizeof(elef), compare);

    memset(dp, -1, sizeof dp);
    c = recur(0, 0);
    printf("%d\n", c);

    last = 0;
    for(i=0; i<n; i++){
        if(elefs[i].w>elefs[last].w&&elefs[i].iq<elefs[last].iq&&1+dp[i+1][i]>=dp[i+1][last]){
            last = i;
            printf("%d\n", elefs[i].i);
        }
    }
    return 0;
}
