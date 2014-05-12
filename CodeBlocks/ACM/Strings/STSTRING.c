#include <stdio.h>
#include <string.h>
#include <math.h>

typedef long long ll;

char A[10], B[10], C[10];
int lenA, lenB, dp[10][15];

int rec(int n, int c){
    if(n==0) return 0;
    if(c>=10) return 0;
    if(c!=-1 && dp[n][c]!=-1) return dp[n][c];
    int i, res=0;
    for(i=0; i<10; i++){
        if(c==-1 || abs(c-i)>1) res += 1+rec(n-1, i);
    }
    if(c!=-1) dp[n][c]=res;
    return res;
}


int recur(int n, int c, int k){

}

int main(){
    int i,j,k, res;
    memset(dp, -1, sizeof dp);
    while(scanf("%s %s", A, B)>0){
        lenA = strlen(A);
        lenB = strlen(B);

        res = 0;
        for(i=1; i<=lenA; i++) res+=rec(i,-1);

        printf("%d\n", res);
    }
    return 0;
}
