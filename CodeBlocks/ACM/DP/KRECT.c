#include <stdio.h>

#define max(x,y) ((x>y)?x:y)

int m, n, q, i,j,k,l, c,d, arr[101][101], dp1[10][10][10][10], dp2[10][10][10][10], prime[26]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
char s[101];

int main(){
    scanf("%d %d %d", &m, &n, &q);
    for(i=0; i<m; i++){
        scanf("%s", s);
        for(j=0; j<n; j++){
            arr[i][j] = prime[s[j]-'A'];
        }
    }

    for(i=0; i<m; i++)
    for(j=i; j<m; j++)
    for(k=0; k<n; k++) {
        dp1[i][j][k][k]=arr[i][k];
        dp2[i][j][k][k]=1;
    }


    for(i=0; i<n; i++)
    for(j=i; j<n; j++)
    for(k=0; k<m; k++) {
        dp1[k][k][i][j]=arr[i][k];
        dp2[k][k][i][j]=1;
    }

    c=0;
    for(i=0; i<m; i++)
    for(j=i+1; j<m; j++)
    for(k=0; k<n; k++)
    for(l=k+1; l<n; l++){
        d=dp1[i][j-1][k][l]*(dp1[i][j][k][l-1]/dp1[i][j-1][k][l-1]);
        if(d%arr[j][l]==0) {
            dp1[i][j][k][l] = d;
            dp2[i][j][k][l] = max(dp1[i][j-1][k][l],dp1[i][j][k][l-1]);
        }else{
            dp1[i][j][k][l] = d*arr[j][l];
            dp2[i][j][k][l] = max(dp1[i][j-1][k][l],dp1[i][j][k][l-1])+1;
        }
        if(dp2[i][j][k][l]==q) c++;
    }
    printf("%d\n", c);
    return 0;
}
