#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    int s;
    int o;
} jC;

jC jS[101];
int m,n, cS[101], dp[101][101];
char s[30];

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int compare2 (const void * a, const void * b){
    if(( (*(jC*)a).s - (*(jC*)b).s )==0){
        return ( (*(jC*)a).o - (*(jC*)b).o );
    }
    return ( (*(jC*)a).s - (*(jC*)b).s );
}


int recur(int i, int j){//ana, hwa
    if(dp[i][j]!=-1)return dp[i][j];
    if(i==m)
        return dp[i][j] = 0;
    if(j==n) return dp[i][j] = cS[i] + recur(i+1, j);

    int maxC=recur(i+1,j), curC=0;
    if(jS[j].o==1){
        if(cS[i]>=jS[j].s) curC = cS[i]-jS[j].s + recur(i+1, j+1);
    }else{
        if(cS[i]>jS[j].s) curC = recur(i+1, j+1);
    }
    if(curC>maxC)
        maxC=curC;
    return dp[i][j] = maxC;
}

int main(){
    int i, j, v;
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++){
        scanf("%s", s);
        scanf("%d", &v);
        jC jc;
        jc.s = v;
        if(strcmp(s, "ATK")==0) jc.o=1;
        else jc.o=0;
        jS[i]=jc;
    }
    memset(dp, -1, sizeof dp);
    for(i=0; i<m; i++) scanf("%d", &cS[i]);
    qsort(cS, m, sizeof(int), compare);
    qsort(jS, n, sizeof(jC), compare2);
    printf("%d\n", recur(0,0));
    return 0;
}
