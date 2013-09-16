#include <stdio.h>

#define max(x,y) ((x>y)?x:y)

int m, n, q, i,j,k,l, c,d, arr[101][101], dp[10][10][10][10];
char s[101];

int recur(int i, int j, int k, int l){
    if(i==j&&k==l) return (q==1)?1:0;

}

int main(){
    scanf("%d %d %d", &m, &n, &q);
    for(i=0; i<m; i++){
        scanf("%s", s);
        for(j=0; j<n; j++){
            arr[i][j] = s[j]-'A';
        }
    }
    printf("%d\n", recur(0,m,0,n));
    return 0;
}
