#include <stdio.h>
#include <string.h>

char a[61], b[61], c[61];
int na,nb,nc;
long long dp[62][62][62];

long long recur(int i, int j, int k){
    if(k==nc) return 1;
    if(i==na && j==nb) return 0;
    long long cnt=0;
    if(i<na && a[i]==c[k]) cnt+=recur(i+1, j, k+1);
    //if(i<na) cnt+=recur(i+1, j, k);
    if(j<nb && b[j]==c[k]) cnt+=recur(i, j+1, k+1);
    if(i<na && j<nb) cnt+=recur(i+1, j+1, k);
    return cnt;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%s %s %s", a, b, c);
        na = strlen(a);nb = strlen(b);nc = strlen(c);
        printf("%lld\n", recur(0,0,0));
    }
    return 0;
}
