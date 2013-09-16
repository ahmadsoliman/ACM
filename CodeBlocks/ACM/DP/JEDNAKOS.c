#include <stdio.h>
#include <string.h>

#define INF 1000000000
#define min(x,y) ((x<y)?x:y)

char A[1010], s[2000];
int n, sums[1010];

int recur(int last, int i, int s){
    if(i==n && s==0) return 0;
    if(i==n || s==0) return INF;

    int a=recur(last, i+1, s), b=1+recur(i, i+1, s-sums[i]+((last>-1)?sums[last]:0));
    return min(a,b);
}

int main(){
    int S, i, j;
    scanf("%s", A);
    char * pch = strtok (A,"=");
    n = strlen(pch);
    memccpy(A, pch, n, sizeof(char));
    pch = strtok (NULL, "=");
    sscanf(pch, "%d", &S);

    sums[0] = A[0]-'0';
    for(i=1; i<n; i++) sums[i] = sums[i-1] + A[i]-'0';

    printf("%d\n", recur(-1, 0, S));
    return 0;
}
